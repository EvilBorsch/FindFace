#include "BaseDB.h"
#include "KDTree.h"
#include "SearchEngine.h"
#include "DBManager.h"

class DB: public BaseDB{
public:
	DB(KDTree *data_structure, SearchEngine *search_engine, DBManager *db_manager);
};
