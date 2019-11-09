#include <iostream>
#include <string>  
#include <vector>

#include <gtest/gtest.h>
#include "db_template.cpp"


TEST(ContainerTest, InitTest){
	Container<int, int> *test_container = new Container<int, int>(1, 2);
	EXPECT_EQ(test_container->get_key(), 1);
	EXPECT_EQ(test_container->get_data(), 2);
	delete test_container;
}


TEST(BTreeNodeTest, InitTest){
	BTreeNode *node = new BTreeNode();
	delete node;
}


TEST(DBManager, InitTest){
	DBManager *db_manager = DBManager::get_instance("/test_data/tree_data");
	delete db_manager;
}

TEST(DBManager, SaveLoadTest){
	DBManager *db_manager = DBManager::get_instance("/test_data/tree_data");

	const unsigned int containers_count = 10;
	const unsigned int node_ids_count = 10;
	const int key = 1;
	const float data = 2.2;

	std::vector<unsigned int> node_ids;
	std::vector<Container<int, float>> containers;

	for(int c = 0; c < node_ids_count; ++c){
		unsigned int node_id = db_manager->get_new_btree_node();
		node_ids.push_back(node_id);

		BTreeNode *node = db_manager->get_tree_by_id(node_id);

		for(int c = 0; c < containers_count; ++c){
			Container<int, float> *container = new Container<int, float>(key, data);
			containers.push_back(*container);

			node->keys.push_back(*container);
		}

		delete node;
	}

	for(int c = 0; c < node_ids_count; ++c){
		BTreeNode* node = db_manager->get_tree_by_id(node_ids[c]);
		
		for(int c = 0; c < node->keys.size(); ++c){
			EXPECT_EQ(((Container<int, float>*)(&(node->keys[c])))->get_key(), key);
			EXPECT_EQ(((Container<int, float>*)(&(node->keys[c])))->get_data(), data);
		}

		delete node;
	}

	for(int c = 0; c < node_ids.size(); c++){
		delete &(node_ids[c]);
	}

	for(int c = 0; c < containers.size(); c++){
		delete &(containers[c]);
	}

	delete db_manager;
}
 
int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}