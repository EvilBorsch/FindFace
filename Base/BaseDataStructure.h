#pragma once
#include <string>

#include "BaseContainer.h"
#include "BaseDBManager.h"


class BaseDataStructure: public BaseContainer{ 
public:
	BaseDataStructure(const std::string &id, const BaseDBManager *db_manager_);

	const BaseDBManager *db_manager;
};