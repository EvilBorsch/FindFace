#pragma once

#include "BaseDataStructure.h"
#include "BaseDBManager.h"

class BaseSearchEngine{

public:
	BaseSearchEngine(const BaseDataStructure* data_structure_, const BaseDBManager* db_manager_);

protected:
	const BaseDataStructure* data_structure;
	const BaseDBManager* db_manager;
};