#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <memory>

#include <bsoncxx/builder/stream/document.hpp>

#include "DataBase/Base/BaseDataStructure.h"
#include "DataBase/Base/BaseDBManager.h"
#include "DataBase/Base/BaseContainer.h"
#include "DataBase/Base/BaseComporator.h"
#include "DataBase/Base/BaseMetrificator.h"

#include "DBManager.h"
#include "Container.h"

class KDTree: public BaseDataStructure{

public:
	KDTree(const std::string &id, DBManager *db_manager, const size_t &max_containers_count);
	~KDTree();

	KDTree(const KDTree&) = delete;
	KDTree& operator=(const KDTree&) = delete;

	void add(const std::vector<double>& key, const std::string& data, BaseComporator *cmp);

	//std::vector<std::string> range_search(const std::vector<double>& min, const std::vector<double>& max);
	std::vector<std::string> neighbor_search(const std::vector<double>& key, BaseComporator *cmp, BaseMetrificator *mth);

	void save(bsoncxx::builder::basic::sub_document &document);
	void load(const bsoncxx::v_noabi::document::element& document_reader);
	
	size_t max_containers_count = 0;
private:

	std::pair<std::vector<std::string>, double> find_range(const std::vector<double>& container, BaseComporator *cmp, BaseMetrificator *mth);
	void split_container(std::string container_id);

	std::string root_container_id = "";
};



