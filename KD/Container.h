#pragma once

#include <vector>
#include <bsoncxx/builder/stream/document.hpp>
#include "BaseContainer.h"


class Container:public BaseContainer{
public:

	Container(const std::string &id_);

	void save(bsoncxx::v_noabi::builder::stream::key_context<bsoncxx::v_noabi::builder::stream::key_context<>>& document);
	void load(const bsoncxx::document::view& document_reader);

	std::vector<double> get_key();
	std::string get_data();

	void set_key(const std::vector<double>& key_);
	void set_data(const std::string& data_);

private:

	std::vector<double> key;
	std::string data;
};
