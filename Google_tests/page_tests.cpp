//
// Created by Сергей Петренко on 2019-11-08.
//
#include "gtest/gtest.h"
#include "../ContainerView.h"
#include "../View.h"
#include "../Page.h"

class TestPageData : public ::testing::Test
{
protected:
    void SetUp() override
    {
        page_data = new PageData();
    }
    void TearDown() override
    {
        delete page_data;
    }
    PageData *page_data;
};
TEST_F(TestPageData, test_get_static_data1)
{
    map<string,string> current_pd = page_data->static_files;
    page_data->get_static();
    ASSERT_NE(current_pd,page_data->static_files);
}


class TestPageViews : public ::testing::Test
{
protected:
    void SetUp() override
    {
        stringProperty = new StringProperty();
        view = new View();

    }
    View *view;
    StringProperty *stringProperty;
};



class TestPageGenerator : public ::testing::Test
{
protected:
    void SetUp() override
    {
        page_generator = new PageGenerator();
        page_data = new PageData();
    }
    PageGenerator *page_generator;
    PageData *page_data;

};

TEST_F(TestPageGenerator, test_generate_result_page)
{
    auto generated_page = page_generator->generate_result_page(*page_data);
    ASSERT_EQ(generated_page.to_string(), "my_generated_page");
}


class TestPageManager : public ::testing::Test
{
protected:
    void SetUp() override
    {
    page_manager = new PageManager();
    }
    void TearDown() override
    {
        delete page_manager;

    }
    PageManager *page_manager;
};

TEST_F(TestPageManager, test_get_from_server)
{

    PageData page_data = page_manager->get_page_generator().get_page_data();
   // ASSERT_NE(page_data, page_manager->get_from_server());
}


