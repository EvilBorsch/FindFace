//
// Created by Dmitry Boldin on 09/11/2019.
//

#include "gtest/gtest.h"
#include <iostream>
#include "../Server.cpp"

class APIManagerTests : public ::testing::Test {
protected:
    void SetUp() {
        manager = new APIManger();
    }
    void TearDown() {
        delete manager;
    }
    APIManger *manager;
};

TEST_F(APIManagerTests, registrate_test) {
    typedef HttpResponse (*api_method)(HttpRequest);
    api_method some_method = nullptr;
    std::string url = "/some/url/";
    manager->registrate(some_method, url);

    std::map<std::string, api_method> pos = manager->api_methods.find(url);

    if (pos != manager->api_methods.end())
        FAIL();
    SUCCEED();
}
