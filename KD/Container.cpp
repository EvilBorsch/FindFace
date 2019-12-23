#include <array>
#include <string>

#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/builder/basic/sub_document.hpp>

#include "Container.h"

Container::Container(const std::string &id_):
	BaseContainer(id_){}

void Container::save(bsoncxx::builder::basic::sub_document &document){

    auto keys_array_builder = bsoncxx::builder::basic::array{};
    auto data_array_builder = bsoncxx::builder::basic::array{};
    auto containers_id_array_builder = bsoncxx::builder::basic::array{};

    for(auto &pair : data){
        auto key_array_builder = bsoncxx::builder::basic::array{};

        for(auto &e : pair.first){
            key_array_builder.append(e);
        }

        data_array_builder.append(pair.second);
        keys_array_builder.append(key_array_builder);
    }

    for(auto &id : containers_id){
        containers_id_array_builder.append(id);
    }

    document.append(
        bsoncxx::builder::basic::kvp("keys", keys_array_builder), 
        bsoncxx::builder::basic::kvp("data", data_array_builder),
        bsoncxx::builder::basic::kvp("containers_id", containers_id_array_builder)
    );
}

void Container::load(const bsoncxx::v_noabi::document::element& document_reader){

    size_t counter = 0;
    for(auto &key_array : document_reader["keys"].get_array().value){
        std::vector<double> key;

        for(auto &e : key_array.get_array().value){
            key.push_back((double)e.get_double());
        }

        data.push_back(std::make_pair(key, (std::string)document_reader["data"][counter].get_utf8().value));
        counter++;
    }

    for(auto &id : document_reader["containers_id"].get_array().value){
        containers_id.push_back((std::string)id.get_utf8().value);
    }
}


std::vector<std::pair<std::vector<double>, std::string>> Container::get_data(){
    return data;
}

std::vector<std::string> Container::get_containers_id(){
    return containers_id;
}

void Container::set_data(const std::vector<std::pair<std::vector<double>, std::string>>& data_){
    data = data_;
}

void Container::set_containers_id(const std::vector<std::string> &containers_id_){
    containers_id = containers_id_;
}