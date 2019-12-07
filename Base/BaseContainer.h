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

	virtual void save(bsoncxx::v_noabi::builder::stream::key_context<bsoncxx::v_noabi::builder::stream::key_context<>> &document) = 0;
	virtual void load(const bsoncxx::document::view& document_reader) = 0;

	const std::string id;
};
