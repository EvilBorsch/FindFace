#pragma once

#include <string>

#include "DataBase/Base/BaseSearchEngine.h"
#include "DataBase/Base/BaseComporator.h"
#include "DataBase/Base/BaseMetrificator.h"
#include "KDTree.h"
#include "DBManager.h"


class SearchEngine: public BaseSearchEngine{
public:

	SearchEngine(const KDTree* data_structure, const DBManager* db_manager);
	std::vector<std::string> get_best_match(const std::vector<double> &key, BaseComporator *cmp, BaseMetrificator *mth);
};
