#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <algorithm>

#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#include "BaseDataStructure.h" 
#include "DBManager.h"
#include "Container.h"



class Cmp{
public:

	Cmp(const size_t &depth_);
	Cmp();

    bool operator()(const std::vector<double>& a, const std::vector<double>& b, const double& bias = 0);
    bool operator()(const double& a, const double& b);
private:
	const size_t depth = 0;
};


class Metric{

public:
	double operator()( const std::vector<double>& a, const std::vector<double>& b);
};


class KDTree: public BaseDataStructure{ 
public:

	KDTree(const std::string &id, const DBManager *db_manager);
	~KDTree();

	KDTree(const KDTree&) = delete;
	KDTree& operator=(const KDTree&) = delete;

	void add(const std::vector<double>& key, const std::string& data);

	std::vector<std::string> range_search(const std::vector<double>& min, const std::vector<double>& max);
	std::vector<std::string> neighbor_search(const std::vector<double>& key);

	void save(bsoncxx::v_noabi::builder::stream::key_context<bsoncxx::v_noabi::builder::stream::key_context<>>& document);
	void load(const bsoncxx::document::view& document_reader);

private:

	class KDTreeNode{
	public:

		std::vector<std::string> containers;
		KDTreeNode *left_node = nullptr;
		KDTreeNode *right_node = nullptr;
		const BaseDBManager *db_manager;

		KDTreeNode(const std::string& container, const BaseDBManager *db_manager);
		KDTreeNode(const std::vector<std::string>& containers, const BaseDBManager *db_manager);

		void operator()(const std::string& container, const Cmp& cmp);
	
	private:

		typename std::vector<std::string>::iterator 
		insert_sorted(std::vector<std::string> &containers, const std::string &container, const Cmp &cmp);
	};

	KDTreeNode* root = nullptr;

	std::vector<double> load_key(const std::string &id);
	std::vector<std::string> find_range(const std::vector<double>& container);

	static const size_t max_containers_count = 5;
};
