#pragma once
#include <string>

#include "BaseContainer.h"
#include "BaseDBManager.h"


class BaseDataStructure: public BaseContainer{ 
public:
	BaseDataStructure(const std::string &id, BaseDBManager *db_manager_);
	virtual void save(bsoncxx::builder::basic::sub_document &document) = 0;
	virtual void load(const bsoncxx::v_noabi::document::element& document_reader) = 0;

	BaseDBManager *db_manager;
};