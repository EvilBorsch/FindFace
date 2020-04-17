#pragma once

#include "BaseDataStructure.h"
#include "BaseDBManager.h"
#include "BaseSearchEngine.h"

class BaseDB{
public:
	BaseSearchEngine *search_engine;

protected:

	BaseDataStructure *data_structure;
	BaseDBManager *db_manager;
};