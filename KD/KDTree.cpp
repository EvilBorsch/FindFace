#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <algorithm>

#include <bsoncxx/builder/stream/document.hpp>

#include "BaseDataStructure.h" 
#include "DBManager.h"
#include "Container.h"
#include "KDTree.h"



Cmp::Cmp(const size_t &depth_):depth(depth_){}
Cmp::Cmp(){}

bool Cmp::operator()(const std::vector<double>& a, const std::vector<double>& b, const double& bias){
    return a[depth % a.size()] + bias < b[depth % b.size()];
}


bool Cmp::operator()(const double& a, const double& b){
    return a < b;
}


double Metric::operator()( const std::vector<double>& a, const std::vector<double>& b){
    double ret = 0.0;
    for(size_t c = 0; c < a.size(); ++c){
    	double dist = a[c] - b[c];
    	ret += dist * dist;	
    }
	return ret > 0.0 ? sqrt(ret) : 0.0;
}


KDTree::KDTree(const std::string &id, const DBManager *db_manager):BaseDataStructure(id, db_manager){}

KDTree::~KDTree(){}

void KDTree::add(const std::vector<double>& key, const std::string& data){

	Container *container = ((DBManager*)db_manager)->get_free_container();
	container->set_key(key);
	container->set_data(data);
	((DBManager*)db_manager)->save_container(container);

	KDTreeNode **currient_kd_tree_node = &root;
	size_t depth = 0;

	while((*currient_kd_tree_node != nullptr)&&((*currient_kd_tree_node)->containers.size() == 1)){
		if(Cmp(depth)(load_key((*currient_kd_tree_node)->containers[0]), load_key(container->id))){
			currient_kd_tree_node = &((*currient_kd_tree_node)->right_node);
		}
		else{
			currient_kd_tree_node = &((*currient_kd_tree_node)->left_node);
		}
	}

	if(*currient_kd_tree_node == nullptr){
		*currient_kd_tree_node = new KDTreeNode(container->id, db_manager);
	}
	else{
		(**currient_kd_tree_node)(container->id, Cmp(depth));
	}

	delete container;
	std::cout << "\n";
}



std::vector<std::string> KDTree::range_search(const std::vector<double>& min, const std::vector<double>& max){

	std::vector<std::string> out_data;
	std::queue<KDTreeNode*> kd_tree_node_queue;
	std::queue<size_t> kd_tree_depth_queue;

	if(root != nullptr){
		kd_tree_node_queue.push(root);
		kd_tree_depth_queue.push(0);
	}

	while(!kd_tree_node_queue.empty()){
		KDTreeNode *currient_kd_tree_node = kd_tree_node_queue.front();
		size_t currient_kd_tree_depth = kd_tree_depth_queue.front();

		if(Cmp(currient_kd_tree_depth)(load_key(currient_kd_tree_node->containers[0]), min)){
			if(currient_kd_tree_node->right_node != nullptr){
				kd_tree_node_queue.push(currient_kd_tree_node->right_node);
				kd_tree_depth_queue.push(currient_kd_tree_depth + 1);
			}
		}
		else if(Cmp(currient_kd_tree_depth)(max, load_key(currient_kd_tree_node->containers[0]))){
			if(currient_kd_tree_node->left_node != nullptr){
				kd_tree_node_queue.push(currient_kd_tree_node->left_node);
				kd_tree_depth_queue.push(currient_kd_tree_depth + 1);
			}
		}
		else{
			if(currient_kd_tree_node->containers.size() == 1){
				out_data.push_back(currient_kd_tree_node->containers[0]);
			}
			else{
				out_data.insert(out_data.end(), currient_kd_tree_node->containers.begin(), currient_kd_tree_node->containers.end());
			}

			if(currient_kd_tree_node->left_node != nullptr){
				kd_tree_node_queue.push(currient_kd_tree_node->left_node);
				kd_tree_depth_queue.push(currient_kd_tree_depth + 1);
			}
			if(currient_kd_tree_node->right_node != nullptr){
				kd_tree_node_queue.push(currient_kd_tree_node->right_node);
				kd_tree_depth_queue.push(currient_kd_tree_depth + 1);
			}
		}
		
		kd_tree_node_queue.pop();
		kd_tree_depth_queue.pop();
	}

	std::vector<std::string> out;
	for(size_t c = 0; c < out_data.size(); ++c){
		Container *container = ((DBManager*)db_manager)->get_container(out_data[c]);
		out.push_back(container->get_data());
		delete container;
	}

	return out;
}



std::vector<std::string> KDTree::neighbor_search(const std::vector<double>& container){

	std::vector<std::string> nearest_containers;

	if(root == nullptr){
		return nearest_containers;
	}

	nearest_containers = find_range(container);
	
	if(nearest_containers.empty()){
		return nearest_containers;
	}

	auto best_metric = Metric()(load_key(nearest_containers[0]), container);

	std::queue<KDTreeNode*> kd_tree_node_queue;
	std::queue<size_t> kd_tree_depth_queue;

	if(root != nullptr){
		kd_tree_node_queue.push(root);
		kd_tree_depth_queue.push(0);
	}

	while(!kd_tree_node_queue.empty()){
		KDTreeNode *currient_kd_tree_node = kd_tree_node_queue.front();
		size_t currient_kd_tree_depth = kd_tree_depth_queue.front();

		for(size_t c = 0; c < currient_kd_tree_node->containers.size(); ++c){
			auto buff_metric = Metric()(container, load_key(currient_kd_tree_node->containers[c]));

			if(Cmp()(buff_metric, best_metric)){
				best_metric = buff_metric;
				nearest_containers.clear();
				nearest_containers.push_back(currient_kd_tree_node->containers[c]);
			}
			else if(!Cmp()(best_metric, buff_metric)){
				
				nearest_containers.push_back(currient_kd_tree_node->containers[c]);
			}
		}

		if(Cmp(currient_kd_tree_depth)(container, load_key(currient_kd_tree_node->containers[0]))){
			if(!Cmp(currient_kd_tree_depth)(container, load_key(currient_kd_tree_node->containers[0]), best_metric)){
				if(currient_kd_tree_node->left_node != nullptr){
					kd_tree_node_queue.push(currient_kd_tree_node->left_node);
					kd_tree_depth_queue.push(currient_kd_tree_depth + 1);
				}
				if(currient_kd_tree_node->right_node != nullptr){
					kd_tree_node_queue.push(currient_kd_tree_node->right_node);
					kd_tree_depth_queue.push(currient_kd_tree_depth + 1);
				}
			}
			else{
				if(currient_kd_tree_node->left_node != nullptr){
					kd_tree_node_queue.push(currient_kd_tree_node->left_node);
					kd_tree_depth_queue.push(currient_kd_tree_depth + 1);
				}
			}
		}
		else{
			if(Cmp(currient_kd_tree_depth)(container, load_key(currient_kd_tree_node->containers[0]), -best_metric)){
				if(currient_kd_tree_node->left_node != nullptr){
					kd_tree_node_queue.push(currient_kd_tree_node->left_node);
					kd_tree_depth_queue.push(currient_kd_tree_depth);
				}
				if(currient_kd_tree_node->right_node != nullptr){
					kd_tree_node_queue.push(currient_kd_tree_node->right_node);
					kd_tree_depth_queue.push(currient_kd_tree_depth);
				}
			}
			else{
				if(currient_kd_tree_node->right_node != nullptr){
					kd_tree_node_queue.push(currient_kd_tree_node->right_node);
					kd_tree_depth_queue.push(currient_kd_tree_depth);
				}
			}	
		}

		kd_tree_node_queue.pop();
		kd_tree_depth_queue.pop();
	}


	std::vector<std::string> out;
	for(size_t c = 0; c < nearest_containers.size(); ++c){
		Container *container = ((DBManager*)db_manager)->get_container(nearest_containers[c]);
		out.push_back(container->get_data());
		delete container;
	}

	return out;
}


void KDTree::save(bsoncxx::v_noabi::builder::stream::key_context<bsoncxx::v_noabi::builder::stream::key_context<>>& document){}
void KDTree::load(const bsoncxx::document::view& document_reader){}


std::vector<std::string> KDTree::find_range(const std::vector<double>& container){

	KDTreeNode *currient_kd_tree_node = root;
	std::vector<std::string> nearest_containers;
	size_t depth = 0;

	auto best_metric = Metric()(container, load_key(root->containers[0]));
	nearest_containers.push_back(root->containers[0]);

	while(currient_kd_tree_node != nullptr){
		for(size_t c = 0; c < currient_kd_tree_node->containers.size(); ++c){
			auto buff_metric = Metric()(container, load_key(currient_kd_tree_node->containers[c]));

			if(Cmp()(buff_metric, best_metric)){
				best_metric = buff_metric;
				nearest_containers.clear();
				nearest_containers.push_back(currient_kd_tree_node->containers[c]);
			}
			else if(!Cmp()(best_metric, buff_metric)){
				
				nearest_containers.push_back(currient_kd_tree_node->containers[c]);
			}
		}

		if(Cmp(depth)(load_key(currient_kd_tree_node->containers[0]), container)){
			currient_kd_tree_node = currient_kd_tree_node->right_node;
		}
		else{
			currient_kd_tree_node = currient_kd_tree_node->left_node;
		}
		++depth;
	}

	return nearest_containers;
}


std::vector<double> KDTree::load_key(const std::string &id){
	Container *container = ((DBManager*)db_manager)->get_container(id);
	std::vector<double> out = container->get_key();
	delete container;
	return(out);
}


KDTree::KDTreeNode::KDTreeNode(const std::string& container, const BaseDBManager *db_manager_):
db_manager(db_manager_){
	containers.push_back(container);
}


KDTree::KDTreeNode::KDTreeNode(const std::vector<std::string>& containers_, const BaseDBManager *db_manager_):
containers(containers_), db_manager(db_manager_){}


void KDTree::KDTreeNode::operator()(const std::string& container, const Cmp& cmp){
	if(containers.size() < max_containers_count){
		insert_sorted(containers, container, cmp);
	}
	else{
		size_t median = containers.size() / 2;
		std::vector<std::string> l_vector(containers.begin(), containers.begin() + median);
		std::vector<std::string> r_vector(containers.begin() + median + 1, containers.end());

		left_node = new KDTreeNode(l_vector, db_manager);
		right_node = new KDTreeNode(r_vector, db_manager);

		containers = std::vector<std::string>{containers[median]};
	}
}


typename std::vector<std::string>::iterator
KDTree::KDTreeNode::insert_sorted(std::vector<std::string> &containers, const std::string &container, const Cmp &cmp){
	
	struct LoadCmp{
		Cmp cmp;
		const BaseDBManager *db_manager;
		
		LoadCmp(const Cmp &cmp_, const BaseDBManager *db_manager_):cmp(cmp_), db_manager(db_manager_){}

		bool operator()(const std::string &a, const std::string &b){

			Container *a_container = ((DBManager*)db_manager)->get_container(a);
			std::vector<double> key_a = a_container->get_key();
			delete a_container;

			Container *b_container = ((DBManager*)db_manager)->get_container(b);
			std::vector<double> key_b = b_container->get_key();
			delete b_container;

			return(cmp(key_a, key_b));
		}
	};

	return containers.insert( 
		std::upper_bound(containers.begin(), containers.end(), container, LoadCmp(cmp, db_manager)),
		container
	);
}