//
// Created by Dmitry Boldin on 08/11/2019.
//

#include "gtest/gtest.h"
#include <iostream>
#include "../LRU.cpp"


class LRUTests : public ::testing::Test {
protected:
    void SetUp() {
        cache = new LRU(2);

        value.emplace_back("a");
        cache->put(k, value);

        std::vector<std::string> value1;
        value.emplace_back("b");
        cache->put(k, value1);
    }
    void TearDown() {
        delete cache;
    }
    LRU *cache;
    std::string k = "some_value";
    std::vector<std::string> value;
};

TEST_F(LRUTests, can_get_cached) {
    std::vector<std::string> v = cache->get(k);
    ASSERT_EQ(value, v);
}

TEST_F(LRUTests, nullptr_for_wrong_key) {
    std::vector<std::string> v = cache->get("abcd");
    ASSERT_EQ(nullptr, v);
}
