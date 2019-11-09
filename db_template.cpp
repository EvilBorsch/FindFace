#include <istream>
#include <ostream>
#include <string>  
#include <vector>

#include "db_template.h"

template <typename K, typename D> Container <K, D>::Container(K key_m, D data_m){}
template <typename K, typename D> K Container <K, D>::get_key(){return key;}
template <typename K, typename D> D Container <K, D>::get_data(){return data;}


BTreeNode::BTreeNode(){}


DBManager* DBManager::db_manager;
DBManager::DBManager(std::string data_path){}
void DBManager::save_btree_node(BTreeNode* node){}
BTreeNode* DBManager::load_btree_node(unsigned int tree_id){
	BTreeNode *out = new BTreeNode();
	return out;
}
DBManager* DBManager::get_instance(std::string db_path){return DBManager::db_manager;}
BTreeNode* DBManager::get_tree_by_id(unsigned int tree_id){
	BTreeNode *out = new BTreeNode();
	return out;
}
unsigned int DBManager::get_new_btree_node(){
	unsigned int *out = new unsigned int;
	return *out;
}


bool BaseCmp::operator()(BaseContainer c1, BaseContainer c2){}
bool KDCmp::operator()(BaseContainer c1, BaseContainer c2){return false;}


BTree::BTree(std::string db_path){
	db_manager = DBManager::get_instance(db_path);
}
template <typename Cmp> void BTree::add(BaseContainer container){}
template <typename Cmp> void BTree::del(BaseContainer container){}
template <typename Cmp> std::vector<BaseContainer> BTree::search(BaseContainer container){
	std::vector<BaseContainer> *out = new std::vector<BaseContainer>;
	return(*out);
}
void BTree::save(std::ostream out_stream){}


DB* DB::db;
DB::DB(){}
DB* DB::get_instance(std::string b_tree_save_path){return db;}
template <typename Cmp> void DB::add(BaseContainer container){}
template <typename Cmp> std::vector<BaseContainer> range_search(std::vector<BaseContainer> l_range, std::vector<BaseContainer> r_range){
	std::vector<BaseContainer> *out = new std::vector<BaseContainer>;
	return(*out);
}
template <typename Cmp> std::vector<BaseContainer> neighbor_search(unsigned int count, BaseContainer container){
	std::vector<BaseContainer> *out = new std::vector<BaseContainer>;
	return(*out);
}

