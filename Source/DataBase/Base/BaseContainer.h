#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include <bsoncxx/builder/stream/document.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>


class BaseContainer{
public:

	BaseContainer(const std::string &id_);

	virtual void save(bsoncxx::builder::basic::sub_document &document) = 0;
	virtual void load(const bsoncxx::v_noabi::document::element& document_reader) = 0;

	const std::string id;
};
