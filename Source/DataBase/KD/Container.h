#pragma once

#include <vector>
#include <utility>

#include <bsoncxx/builder/basic/sub_document.hpp>
#include <bsoncxx/builder/stream/document.hpp>

#include "DataBase/Base/BaseContainer.h"


class Container:public BaseContainer{
public:

	Container(const std::string &id_);

	void save(bsoncxx::builder::basic::sub_document &document);
	void load(const bsoncxx::v_noabi::document::element& document_reader);

	std::vector<std::pair<std::vector<double>, std::string>> get_data();
	std::vector<std::string> get_containers_id();

	void set_data(const std::vector<std::pair<std::vector<double>, std::string>>& data);
	void set_containers_id(const std::vector<std::string> &containers_id);


private:

	std::vector<std::pair<std::vector<double>, std::string>> data;
	std::vector<std::string> containers_id;
};
