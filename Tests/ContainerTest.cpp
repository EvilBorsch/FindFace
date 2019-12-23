#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <vector>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/sub_document.hpp>

#include "Container.h"

TEST(ContainerTest, InitTest){
	EXPECT_NO_THROW(Container container("..."));
}

TEST(ContainerTest, SetGetKeyTest){
	std::vector<std::pair<std::vector<double>, std::string>> data = {
		std::make_pair(std::vector<double>{1,2,3}, "1"),
		std::make_pair(std::vector<double>{3,2,1}, "3")
	};

	Container container("...");

	EXPECT_NO_THROW(container.set_data(data));
	EXPECT_EQ(container.get_data(), data);
}

TEST(ContainerTest, SetGetDataTest){
	std::vector<std::string> id = {"1", "2", "3"};
	Container container("...");

	EXPECT_NO_THROW(container.set_containers_id(id));
	EXPECT_EQ(container.get_containers_id(), id);
}

TEST(ContainerTest, SaveLoadContainerTest){
	std::vector<std::pair<std::vector<double>, std::string>> data = {
		std::make_pair(std::vector<double>{1,2,3}, "1"),
		std::make_pair(std::vector<double>{3,2,1}, "3")
	};
	std::vector<std::string> id = {"1", "2", "3"};
	Container save_container("...");

	EXPECT_NO_THROW(save_container.set_data(data));
	EXPECT_NO_THROW(save_container.set_containers_id(id));

  	bsoncxx::builder::basic::document doc;

  	doc.append(bsoncxx::builder::basic::kvp("test", [&save_container](bsoncxx::builder::basic::sub_document sub_doc){
    	save_container.save(sub_doc);
    }));

  Container load_container("...");
  EXPECT_NO_THROW(load_container.load(doc.extract().view()["test"]));

  EXPECT_EQ(data, load_container.get_data());
  EXPECT_EQ(id, load_container.get_containers_id());
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

