#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "DBManager.h"
#include "KDTree.h"
#include "SearchEngine.h"
#include "BaseComporator.h"
#include "BaseMetrificator.h"

mongocxx::instance inst{};
mongocxx::client conn{mongocxx::uri{}};

class TestSearchEngine: public::testing::Test{
protected:
	void SetUp();
	void TearDown();

	std::vector<std::vector<double>> test_keys;
	std::vector<std::vector<double>> neighbour_search_tests;
	std::vector<std::string> neighbour_search_answers;
	SearchEngine *search_engine;

private:
	void load_test_keys();
	void neighbour_search_search_test_data();

	DBManager *db_manager;
	KDTree *kd_tree;
	mongocxx::v_noabi::collection collection;
};

void TestSearchEngine::SetUp(){

	load_test_keys();
	neighbour_search_search_test_data();

	collection = conn["testdb"]["testcollection"];
	db_manager = new DBManager(collection);
	kd_tree = new KDTree("...", db_manager, 3);
	search_engine = new SearchEngine(kd_tree, db_manager);

	BaseComporator cmp;

	for(auto &key : test_keys){

		kd_tree->add(key, std::to_string(key[0]), &cmp);
	}
}

void TestSearchEngine::TearDown(){
	delete db_manager;
	delete kd_tree;
	delete search_engine;
}

void TestSearchEngine::load_test_keys(){
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

void TestSearchEngine::neighbour_search_search_test_data(){
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
	KDTree *kd_tree;

	EXPECT_NO_THROW(db_manager = new DBManager(collection));
	EXPECT_NO_THROW(kd_tree = new KDTree("...", db_manager, 3));
	EXPECT_NO_THROW(SearchEngine search_engine(kd_tree, db_manager));

	delete db_manager;
	delete kd_tree;
}


TEST_F(TestSearchEngine, BestMatchTest){
	for(size_t c = 0; c < neighbour_search_tests.size(); ++c){
		std::string search_engine_tree_answer;
		BaseComporator cmp = BaseComporator();
		BaseMetrificator mth= BaseMetrificator();

		EXPECT_NO_THROW(search_engine_tree_answer = search_engine->get_best_match(neighbour_search_tests[c], &cmp, &mth)[0]);
		EXPECT_EQ(search_engine_tree_answer, neighbour_search_answers[c]);
	}
}


int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}