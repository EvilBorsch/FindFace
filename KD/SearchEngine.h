#pragma once

#include <string>

#include "BaseSearchEngine.h"
#include "KDTree.h"
#include "DBManager.h"


class SearchEngine: public BaseSearchEngine{
public:

	SearchEngine(const KDTree* data_structure, const DBManager* db_manager);
	std::vector<std::string> get_best_match(const std::vector<double> &key);
	std::vector<std::string> range_search(const std::vector<double> &key);
};
