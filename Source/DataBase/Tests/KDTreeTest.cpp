#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "DBManager.h"
#include "KDTree.h"
#include "BaseComporator.h"

mongocxx::instance inst{};
mongocxx::client conn{mongocxx::uri{}};


class TestKDTree: public::testing::Test{
protected:
	void SetUp();
	void TearDown();

	KDTree *kd_tree;
	std::vector<std::vector<double>> test_keys;
	std::vector<std::vector<double>> neighbour_search_tests;
	std::vector<std::string> neighbour_search_answers;


private:
	void load_test_keys();
	void neighbour_search_search_test_data();

	DBManager *db_manager;
	mongocxx::v_noabi::collection collection;
};

void TestKDTree::SetUp(){

	load_test_keys();
	neighbour_search_search_test_data();

	collection = conn["testdb"]["testcollection"];
	db_manager = new DBManager(collection);
	kd_tree = new KDTree("...", db_manager, 3);
}

void TestKDTree::TearDown(){
	delete db_manager;
	delete kd_tree;
}

void TestKDTree::load_test_keys(){
	std::ifstream inFile;
    inFile.open("Tests/GeneratedTests/test_data.txt");

    if(inFile.fail()){
    	ADD_FAILURE();
    }

    size_t vector_size;
    inFile >> vector_size;

    while(!inFile.eof()){
    	std::vector<double> key;
    	for(int i = 0; i < vector_size; ++i){
			std::string x;
			inFile >> x;
			key.push_back(::atof(x.c_str()));
		}

		if(!inFile.eof()){
			test_keys.push_back(key);
		}
    }
    inFile.close();
}

void TestKDTree::neighbour_search_search_test_data(){
	std::ifstream inFile;
	inFile.open("Tests/GeneratedTests/nearest_neighbour_data.txt");
	
	if(inFile.fail()){
    	ADD_FAILURE();
    }

	size_t vector_size;
	inFile >> vector_size;

	while(!inFile.eof()){
		std::string answer;
		std::vector<double> neighbour_vector;
		double buffer;

		for(int i = 0; i < vector_size; ++i){
			inFile >> buffer;
			neighbour_vector.push_back(buffer);
		}
		inFile >> answer;

		if(!inFile.eof()){
			neighbour_search_tests.push_back(neighbour_vector);
			neighbour_search_answers.push_back(answer);
		}
	}
	inFile.close();	
}



TEST(KDTreeTest, InitTest){
	auto collection = conn["testdb"]["testcollection"];
	DBManager *db_manager;
	
	EXPECT_NO_THROW(db_manager = new DBManager(collection));
	EXPECT_NO_THROW(KDTree kd_tree("...", db_manager, 3));

	delete db_manager;
}


TEST_F(TestKDTree, AddTest){
	for(auto &key : test_keys){
		BaseComporator cmp = BaseComporator();
		EXPECT_NO_THROW(kd_tree->add(key, std::to_string(key[0]), &cmp));
	}
}

TEST_F(TestKDTree, NeighborSearch){
	BaseComporator cmp = BaseComporator();
	BaseMetrificator mth = BaseMetrificator();

	for(auto &key : test_keys){
		EXPECT_NO_THROW(kd_tree->add(key, std::to_string(key[0]), &cmp));
	}

	for(size_t c = 0; c < neighbour_search_tests.size(); ++c){
		std::string kd_tree_answer;
		EXPECT_NO_THROW(kd_tree_answer = kd_tree->neighbor_search(neighbour_search_tests[c], &cmp, &mth)[0]);
		EXPECT_EQ(kd_tree_answer, neighbour_search_answers[c]);
	}
}


int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}