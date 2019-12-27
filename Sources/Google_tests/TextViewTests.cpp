//
// Created by Сергей Петренко on 2019-12-23.
//
#include "gtest/gtest.h"
#include "TextView/TextView.h"
#include "TextView/TextView.cpp"
class TestTestViews : public ::testing::Test
{
protected:
    TextView*  textView;

    void SetUp() override
    {
        textView = new TextView("testname", Type::H4, BClass::TEXT_NORMAL,"TEXT");
    }
    void TearDown() override
    {
        //delete textView;
    }
};

TEST_F(TestTestViews, test_textview_constructor)
{
EXPECT_EQ(textView->toString(0),"<h4 class=\"my-0 font-weight-normal\">TEXT</h4>\n\n");
}

TEST_F(TestTestViews, test_setText)
{
    textView->setText("NEWTEXT");
    EXPECT_EQ(textView->toString(0),"<h4 class=\"my-0 font-weight-normal\">NEWTEXT</h4>\n\n");
}

TEST_F(TestTestViews, test_getText)
{
    EXPECT_EQ(textView->getText(),"NEWTEXT");
}
TEST_F(TestTestViews, test_getClass)
{
    EXPECT_EQ(textView->getClass(),"my-0 font-weight-normal");
}

TEST_F(TestTestViews, test_getType)
{
    EXPECT_EQ(textView->getType(),"h4");
}





