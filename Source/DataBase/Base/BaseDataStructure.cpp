#include "BaseDataStructure.h"


BaseDataStructure::BaseDataStructure(const std::string &id, BaseDBManager *db_manager_):
	BaseContainer(id), db_manager(db_manager_){}