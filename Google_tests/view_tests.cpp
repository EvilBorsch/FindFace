//
// Created by Сергей Петренко on 2019-11-08.
//
#include <Views/ImageView/ImageView.h>
#include <Views/TextView/TextView.h>
#include <Views/TableView/TableView.h>
#include "gtest/gtest.h"
#include "Container/ContainerView.h"
#include "View/View.h"

class TestViews : public ::testing::Test
{
protected:
    void SetUp() override
    {

        view = new View("view", Type::DIV, BClass::CARD_DECK);

    }
    void TearDown() override
    {
        delete view;
    }
    View *view;
};

TEST_F(TestViews, test_view_vonstructor)
{
    EXPECT_EQ(view->toString(),"<div class=\"card-deck mb-3 text-center\">\n\n</div>\n\n");
}

TEST_F(TestViews, test_append_in_view)
{
    view->append(*new View("test",Type::DIV,BClass::CARD_MB4_SHADOW));

    EXPECT_EQ(view->toString(),"<div class=\"card-deck mb-3 text-center\">\n\n   <div class=\"card mb-4 shadow-sm\">\n\n   </div>\n\n</div>\n\n");
}

TEST_F(TestViews, test_append_and_delete)
{
    view->append(*new View("test",Type::DIV,BClass::CARD_MB4_SHADOW));
    view->removeSubview("test");
    EXPECT_EQ(view->toString(),"<div class=\"card-deck mb-3 text-center\">\n\n</div>\n\n");
}

TEST_F(TestViews, test_append_in_subview)
{
    view->append(*new View("test",Type::DIV,BClass::CARD_MB4_SHADOW));
    view->appendInSubview("test",*new View("testInSubview",Type::DIV,BClass::CARD_MB4_SHADOW));

    EXPECT_EQ(view->toString(),"<div class=\"card-deck mb-3 text-center\">\n\n"
                               "   <div class=\"card mb-4 shadow-sm\">\n\n"
                               "      <div class=\"card mb-4 shadow-sm\">\n\n "
                               "     </div>\n\n   </div>\n\n</div>\n\n");
}

TEST_F(TestViews, test_append_in_subview_and_delete)
{
    view->append(*new View("test",Type::DIV,BClass::CARD_MB4_SHADOW));
    view->removeSubview("testInSubview");
    EXPECT_EQ(view->toString(),"<div class=\"card-deck mb-3 text-center\">\n\n</div>\n\n");
}


TEST_F(TestViews, test_add_subview)
{
    view->append(*new View("test",Type::DIV,BClass::CARD_MB4_SHADOW));
    view->removeSubview("test");
    EXPECT_EQ(view->toString(),"<div class=\"card-deck mb-3 text-center\">\n\n</div>\n\n");
}






