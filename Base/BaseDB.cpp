#include "BaseDB.h"

#include "BaseDataStructure.h"
#include "BaseDBManager.h"
#include "BaseSearchEngine.h"

BaseDB::BaseDB(BaseDataStructure *data_structure_, BaseSearchEngine *search_engine_, BaseDBManager *db_manager_):
data_structure(data_structure_), search_engine(search_engine_), db_manager(db_manager_){}