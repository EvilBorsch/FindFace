//
// Created by Сергей Петренко on 2019-11-08.
//
#include <PageData/PageData.h>
#include "gtest/gtest.h"
#include "UserData/UserData.h"
#include <Container/ContainerView.h>
#include <PageGenerator/PageGenerator.h>
#include "View/View.h"
#include "Page.h"

class TestPage : public ::testing::Test
{
public:
    PageGenerator* pageGenerator;
    //UserData* userData1 = new UserData("SLUG1","fname", "sname","https://sun9-60.userapi.com/c855624/v855624982/135c19/xi-ReZmdN70.jpg",19 );
    //UserData* userData2 = new UserData("SLUG2","fname", "sname","https://sun9-14.userapi.com/c844321/v844321164/1e3f38/sjVui97PcoU.jpg",9 );
    //std::vector<UserData*> userData {
    //PageData* pageData = new PageData(userData,PageType::TABLE_OF_USERS, Organize::ONE_LINE_VERTICAL);
    std::string res;
protected:
    void SetUp() override
    {
        pageGenerator = new PageGenerator();

        //res = pageGenerator->generatePage()->toString();

    }
    void TearDown() override
    {
        delete pageGenerator;
    }

};
TEST_F(TestPage, testTableCorrectOneLineVertical){

    ASSERT_STREQ("hi","hi");
}

//
//class TestPageViews : public ::testing::Test
//{
//protected:
//    void SetUp() override
//    {
//        stringProperty = new StringProperty();
//        view = new View();
//
//    }
//    View *view;
//    StringProperty *stringProperty;
//};
//
//
//
//class TestPageGenerator : public ::testing::Test
//{
//protected:
//    void SetUp() override
//    {
//        page_generator = new PageGenerator();
//        page_data = new PageData();
//    }
//    PageGenerator *page_generator;
//    PageData *page_data;
//
//};
//
//TEST_F(TestPageGenerator, test_generate_result_page)
//{
//    auto generated_page = page_generator->generate_result_page(*page_data);
//    ASSERT_EQ(generated_page.to_string(), "my_generated_page");
//}
//
//
//class TestPageManager : public ::testing::Test
//{
//protected:
//    void SetUp() override
//    {
//    page_manager = new PageManager();
//    }
//    void TearDown() override
//    {
//        delete page_manager;
//
//    }
//    PageManager *page_manager;
//};


