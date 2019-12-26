#include <gtest/gtest.h>
#include <string>

#include "DB.h"
#include "SearchEngine.h"

mongocxx::instance inst{};
mongocxx::client conn{mongocxx::uri{}};	
mongocxx::v_noabi::collection collection = conn["testdb"]["testcollection"];

class TestDB: public::testing::Test{
protected:
	void SetUp();
	void TearDown();

	DB *db;
	std::vector<std::vector<double>> test_keys;
	std::vector<std::vector<double>> neighbour_search_tests;
	std::vector<std::string> neighbour_search_answers;

private:

	void load_test_keys();
	void neighbour_search_search_test_data();
};

void TestDB::SetUp(){

	load_test_keys();
	neighbour_search_search_test_data();

	db = new DB(collection, 3);
}

void TestDB::TearDown(){
	delete db;
}

void TestDB::load_test_keys(){
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

void TestDB::neighbour_search_search_test_data(){
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


TEST(DBTest, InitTest){

	DB *db;
	EXPECT_NO_THROW(db = new DB(collection, 3));
	delete db;
}

TEST_F(TestDB, SaveLoadTest){
	BaseComporator cmp = BaseComporator();
	BaseMetrificator mth = BaseMetrificator();

	for(auto &key : test_keys){
		EXPECT_NO_THROW(db->add(key, std::to_string(key[0]), &cmp));
	}

	for(size_t c = 0; c < neighbour_search_tests.size(); ++c){
		std::string kd_tree_answer;
		EXPECT_NO_THROW(kd_tree_answer = ((SearchEngine*)db->search_engine)->get_best_match(neighbour_search_tests[c], &cmp, &mth)[0]);
		EXPECT_EQ(kd_tree_answer, neighbour_search_answers[c]);
	}

	DB *loaded_db = new DB(collection, 3, db->get_kd_tree_key());
	std::cout << loaded_db->get_kd_tree_key() << "\n";

	for(size_t c = 0; c < neighbour_search_tests.size(); ++c){
		std::string kd_tree_answer;
		EXPECT_NO_THROW(kd_tree_answer = ((SearchEngine*)loaded_db->search_engine)->get_best_match(neighbour_search_tests[c], &cmp, &mth)[0]);
		EXPECT_EQ(kd_tree_answer, neighbour_search_answers[c]);
	}

	delete loaded_db;
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
