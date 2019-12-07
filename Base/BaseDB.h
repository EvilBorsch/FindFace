#pragma once

#include "BaseDataStructure.h"
#include "BaseDBManager.h"
#include "BaseSearchEngine.h"

class BaseDB{
public:
	BaseDB(BaseDataStructure *data_structure_, BaseSearchEngine *search_engine_, BaseDBManager *db_manager_);

protected:
	BaseDataStructure *data_structure;
	BaseSearchEngine *search_engine;
	BaseDBManager *db_manager;
};