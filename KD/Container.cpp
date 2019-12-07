#include <string>
#include <array>
#include <bsoncxx/builder/stream/document.hpp>
#include "Container.h"


Container::Container(const std::string &id_):
	BaseContainer(id_){}

void Container::save(bsoncxx::v_noabi::builder::stream::key_context<bsoncxx::v_noabi::builder::stream::key_context<>>& document){
	auto in_array = document << "key" << bsoncxx::builder::stream::open_array;
    for (auto&& e : key) {
        in_array = in_array << e;
    }
    auto after_array = in_array << bsoncxx::builder::stream::close_array;

    after_array << "data" << data;
}


void Container::load(const bsoncxx::document::view& document_reader){
	size_t c = 0;
    
    for (auto&& e : document_reader["key"].get_array().value) {
        key.push_back((double)e.get_double());
        c++;
    
    }
    data = (std::string)document_reader["data"].get_utf8().value;
}

std::vector<double> Container::get_key(){
	return key;
}

std::string Container::get_data(){
	return data;
}


void Container::set_key(const std::vector<double>& key_){
	key = key_;
}


void Container::set_data(const std::string& data_){
	data = data_;
}