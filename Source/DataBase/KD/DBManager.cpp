#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include <bsoncxx/builder/stream/document.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#include "DBManager.h"
#include "Container.h"
#include "DataBase/Base/BaseContainer.h"
#include "DataBase/Base/BaseDBManager.h"
#include "DataBase/Base/BaseDataStructure.h"
#include "KDTree.h"
#include "DBManager.h"


DBManager::DBManager(mongocxx::v_noabi::collection collection_) : collection(
        collection_) {}

void DBManager::save_container(BaseContainer *container) {

    bsoncxx::builder::basic::document save_doc;

    save_doc.append(
            bsoncxx::builder::basic::kvp("$set",
                                         [&container](
                                                 bsoncxx::builder::basic::sub_document sub_doc_1) {
                                             sub_doc_1.append(
                                                     bsoncxx::builder::basic::kvp(
                                                             "container",
                                                             [&container](
                                                                     bsoncxx::builder::basic::sub_document sub_doc_2) {
                                                                 container->save(
                                                                         sub_doc_2);
                                                             }
                                                     )
                                             );
                                         }
            )
    );

    bsoncxx::stdx::optional<bsoncxx::document::value> found_container = collection.find_one(
            bsoncxx::builder::basic::make_document(
                    bsoncxx::builder::basic::kvp(
                            "_id", bsoncxx::oid{
                                    bsoncxx::stdx::string_view{container->id}}
                    )
            )
    );

    if (found_container){
        collection.update_one(found_container.value().view(), save_doc.view());
    }
}

BaseContainer *DBManager::get_container(const std::string &id) {
    bsoncxx::stdx::optional<bsoncxx::document::value> container_doc = collection.find_one(
            bsoncxx::builder::basic::make_document(
                    bsoncxx::builder::basic::kvp(
                            "_id",
                            bsoncxx::oid{bsoncxx::stdx::string_view{id}}
                    )
            )
    );


    Container *container(new Container(id));

    if (container_doc) {
        container->load(container_doc->view()["container"]);
    }


    return (container);

}

BaseContainer *
DBManager::get_kd_tree(const std::string &id, DBManager *db_manager,
                       size_t max_containers_count) {
    bsoncxx::stdx::optional<bsoncxx::document::value> container_doc = collection.find_one(
            bsoncxx::builder::basic::make_document(
                    bsoncxx::builder::basic::kvp(
                            "_id", bsoncxx::oid{bsoncxx::stdx::string_view{id}}
                    )
            )
    );

    KDTree *kd_tree(new KDTree(id, db_manager, max_containers_count));

    if (container_doc) {
        kd_tree->load(container_doc->view()["container"]);
    }

    return (kd_tree);
}


BaseContainer *DBManager::get_free_container() {
    bsoncxx::builder::stream::document document{};
    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = collection.insert_one(document.view());
    std::string id = result.value().inserted_id().get_oid().value.to_string();
    return new Container(id);
}


BaseContainer *DBManager::get_free_kd_tree(DBManager *db_manager,
                                           size_t max_containers_count) {
    bsoncxx::builder::stream::document document{};
    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = collection.insert_one(
            document.view());
    std::string id = result.value().inserted_id().get_oid().value.to_string();
    return new KDTree(id, db_manager, max_containers_count);
}
