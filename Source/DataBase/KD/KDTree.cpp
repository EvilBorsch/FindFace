#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <memory>

#include <bsoncxx/builder/stream/document.hpp>

#include "DataBase/Base/BaseDataStructure.h"
#include "DataBase/Base/BaseDBManager.h"
#include "DataBase/Base/BaseContainer.h"
#include "DataBase/Base/BaseComporator.h"
#include "DataBase/Base/BaseMetrificator.h"

#include "DBManager.h"
#include "Container.h"
#include "KDTree.h"


KDTree::KDTree(const std::string &id, DBManager *db_manager,
               const size_t &max_containers_count_) :
        BaseDataStructure(id, db_manager),
        max_containers_count(max_containers_count_) {

    std::shared_ptr<Container> root_container(
            (Container *) db_manager->get_free_container());
    db_manager->save_container(root_container.get());
    root_container_id = root_container->id;
}

KDTree::~KDTree() {}

void KDTree::add(const std::vector<double> &key, const std::string &data,
                 BaseComporator *cmp) {

    std::string container_id = root_container_id;
    std::shared_ptr<Container> container(
            (Container *) db_manager->get_container(container_id));
    size_t currient_depth = 0;

    while (!container->get_containers_id().empty()) {
        cmp->set_depth(currient_depth);

        if ((*cmp)(container->get_data()[0].first, key)) {
            container_id = container->get_containers_id()[0];
        } else {
            container_id = container->get_containers_id()[1];
        }

        container = std::shared_ptr<Container>(
                (Container *) db_manager->get_container(container_id));

        currient_depth++;
    }

    std::vector<std::pair<std::vector<double>, std::string>> container_data = container->get_data();

    container_data.insert(
            std::upper_bound(container_data.begin(), container_data.end(),
                             std::make_pair(key, data),
                             [cmp](std::pair<std::vector<double>, std::string> a,
                                   std::pair<std::vector<double>, std::string> b) {
                                 return (*cmp)(a.first, b.first);
                             }
            ),
            std::make_pair(key, data)
    );

    container->set_data(container_data);
    db_manager->save_container(container.get());

    if (container_data.size() >= max_containers_count) {
        split_container(container->id);
    }

}

void KDTree::save(bsoncxx::builder::basic::sub_document &document) {
    document.append(
            bsoncxx::builder::basic::kvp("root_container_id", root_container_id)
    );
}

void KDTree::load(const bsoncxx::v_noabi::document::element &document_reader) {
    root_container_id = (std::string) document_reader["root_container_id"].get_utf8().value;
    std::cout << "root_container_id" << root_container_id << "\n";
}

void KDTree::split_container(std::string container_id) {
    std::shared_ptr<Container> container(
            (Container *) db_manager->get_container(container_id));
    std::vector<std::pair<std::vector<double>, std::string>> container_data = container->get_data();

    if (container_data.size() >= max_containers_count) {
        size_t median = container_data.size() / 2;

        std::shared_ptr<Container> left_container(
                (Container *) db_manager->get_free_container());
        std::shared_ptr<Container> right_container(
                (Container *) db_manager->get_free_container());

        left_container->set_data(
                {container_data.begin(), container_data.begin() + median});
        right_container->set_data(
                {container_data.begin() + median + 1, container_data.end()});
        container->set_data({container_data[median]});

        container->set_containers_id({left_container->id, right_container->id});

        db_manager->save_container(container.get());
        db_manager->save_container(left_container.get());
        db_manager->save_container(right_container.get());
    }
}

std::vector<std::string>
KDTree::neighbor_search(const std::vector<double> &key, BaseComporator *cmp,
                        BaseMetrificator *mth) {

    std::vector<std::string> nearest_containers_data;

    if (root_container_id.empty()) {
        return nearest_containers_data;
    }

    std::pair<std::vector<std::string>, double> find_range_data = find_range(
            key, cmp, mth);
    nearest_containers_data = find_range_data.first;
    double best_metric = find_range_data.second;

    if (nearest_containers_data.empty()) {
        return nearest_containers_data;
    }

    std::queue<std::string> containers_id_queue;
    std::queue<size_t> depth_queue;

    containers_id_queue.push(root_container_id);
    depth_queue.push(0);

    while (!containers_id_queue.empty()) {

        std::string currient_container_id = containers_id_queue.front();
        std::shared_ptr<Container> currient_container(
                (Container *) db_manager->get_container(currient_container_id));
        size_t currient_depth = depth_queue.front();
        cmp->set_depth(currient_depth);

        for (auto &pair : currient_container->get_data()) {
            double buff_metric = (*mth)(pair.first, key);
            if ((*cmp)(buff_metric, best_metric)) {
                best_metric = buff_metric;
                nearest_containers_data = {pair.second};
            } else if (!(*cmp)(best_metric, buff_metric)) {
                nearest_containers_data.push_back(pair.second);
            }
        }

        if (!currient_container->get_containers_id().empty()) {
            if ((*cmp)(key, currient_container->get_data()[0].first)) {
                if (!(*cmp)(key, currient_container->get_data()[0].first,
                            best_metric)) {

                    for (auto &id : currient_container->get_containers_id()) {
                        containers_id_queue.push(id);
                        depth_queue.push(currient_depth);
                    }
                } else {
                    containers_id_queue.push(
                            currient_container->get_containers_id()[0]);
                    depth_queue.push(currient_depth);
                }
            } else {
                if ((*cmp)(key, currient_container->get_data()[0].first,
                           -best_metric)) {
                    for (auto &id : currient_container->get_containers_id()) {
                        containers_id_queue.push(id);
                        depth_queue.push(currient_depth);
                    }
                } else {
                    containers_id_queue.push(
                            currient_container->get_containers_id()[1]);
                    depth_queue.push(currient_depth);
                }
            }
        }

        containers_id_queue.pop();
        depth_queue.pop();
    }

    return nearest_containers_data;
}

std::pair<std::vector<std::string>, double>
KDTree::find_range(const std::vector<double> &key, BaseComporator *cmp,
                   BaseMetrificator *mth) {

    std::vector<std::string> nearest_containers_data;
    size_t currient_depth = 0;

    if (root_container_id.empty()) {
        return std::make_pair(nearest_containers_data, 0);
    }

    std::string container_id = root_container_id;
    std::shared_ptr<Container> container(
            (Container *) db_manager->get_container(container_id));

    std::vector<std::pair<std::vector<double>, std::string>> container_data = container->get_data();
    double best_metric = (*mth)(container_data[0].first, key);
    nearest_containers_data = {container_data[0].second};

    while (!container->get_containers_id().empty()) {

        cmp->set_depth(currient_depth);
        for (auto &pair : container_data) {
            double buff_metric = (*mth)(pair.first, key);
            if ((*cmp)(buff_metric, best_metric)) {
                best_metric = buff_metric;
                nearest_containers_data = {pair.second};
            } else if (!(*cmp)(best_metric, buff_metric)) {
                nearest_containers_data.push_back(pair.second);
            }
        }

        if ((*cmp)(container->get_data()[0].first, key)) {
            container_id = container->get_containers_id()[0];
        } else {
            container_id = container->get_containers_id()[1];
        }

        container = std::shared_ptr<Container>(
                (Container *) db_manager->get_container(container_id));
        container_data = container->get_data();
        currient_depth++;
    }

    return std::make_pair(nearest_containers_data, best_metric);
}