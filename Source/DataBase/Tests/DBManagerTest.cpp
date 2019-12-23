#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <vector>

#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>

#include "DBManager.h"
#include "Container.h"

mongocxx::instance inst{};
mongocxx::client conn{mongocxx::uri{}};

class TestDBManager: public::testing::Test{
protected:
	void SetUp();
	void TearDown();
	DBManager *db_manager;

private:
	mongocxx::v_noabi::collection collection;
};

void TestDBManager::SetUp(){
	collection = conn["testdb"]["testcollection"];
	db_manager = new DBManager(collection);
}

void TestDBManager::TearDown(){
	delete db_manager;
}


TEST(DBManagerTest, InitTest){
	auto collection = conn["testdb"]["testcollection"];
	EXPECT_NO_THROW(DBManager db_manager(collection));
}

TEST_F(TestDBManager, GetFreeContainerTest){
	Container *empty_container;
	std::vector<std::pair<std::vector<double>, std::string>> empty_data;
	EXPECT_NO_THROW(empty_container = (Container*)db_manager->get_free_container());
	EXPECT_EQ(empty_container->get_data(), empty_data);
	EXPECT_EQ(empty_container->get_containers_id(), std::vector<std::string>{});

	delete empty_container;
}

TEST_F(TestDBManager, InvalidSaveLoadContainerTest){
	Container invalid_container("12312");

	ASSERT_ANY_THROW(db_manager->save_container(&invalid_container));
	ASSERT_ANY_THROW(db_manager->get_container("123123"));
}

TEST_F(TestDBManager, SaveLoadContainerTest){
	Container *container;
	EXPECT_NO_THROW(container = (Container*)db_manager->get_free_container());
	
	std::vector<std::pair<std::vector<double>, std::string>> data = {
		std::make_pair(std::vector<double>{1,2,3}, "1"),
		std::make_pair(std::vector<double>{3,2,1}, "3")
	};
	std::vector<std::string> id = {"1", "2", "3"};

	EXPECT_NO_THROW(container->set_data(data));
	EXPECT_NO_THROW(container->set_containers_id(id));

	EXPECT_EQ(data, container->get_data());
   	EXPECT_EQ(id, container->get_containers_id());

   	EXPECT_NO_THROW(db_manager->save_container(container));

   	std::string container_id = container->id;

   	Container *loaded_container;
   	EXPECT_NO_THROW(loaded_container = (Container*)db_manager->get_container(container_id));

   	EXPECT_EQ(data, loaded_container->get_data());
   	EXPECT_EQ(id, loaded_container->get_containers_id());

   	delete container;
   	delete loaded_container;
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}