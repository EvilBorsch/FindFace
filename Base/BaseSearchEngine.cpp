#include "BaseSearchEngine.h"

BaseSearchEngine::BaseSearchEngine(const BaseDataStructure* data_structure_,
	const BaseDBManager* db_manager_):data_structure(data_structure_), db_manager(db_manager_){}