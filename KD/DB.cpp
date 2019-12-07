#include "BaseDB.h"
#include "KDTree.h"
#include "SearchEngine.h"
#include "DBManager.h"
#include "DB.h"


DB::DB(KDTree *data_structure, SearchEngine *search_engine, DBManager *db_manager):
	BaseDB(data_structure, search_engine, db_manager){}