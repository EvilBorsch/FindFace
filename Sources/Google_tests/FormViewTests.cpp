//
// Created by Сергей Петренко on 2019-12-23.
//

#include <Views/View/View.h>
#include "gtest/gtest.h"

#include "Form/FormView.h"
#include "Form/FormView.cpp"

class FormViewTests : public ::testing::Test {
protected:
    FormView *formView;

    void SetUp() override {
        formView = new FormView("test","test","test","test");
    }

    void TearDown() override {
        delete formView;
    }
};

TEST_F(FormViewTests, test_formview_constructor) {
    EXPECT_EQ(formView->toString(0),"<form action= \"test\" method= \"test\" enctype= \"test\">\n\n</form> \n\n");
}


TEST_F(FormViewTests, test_getClass) {
    EXPECT_EQ(formView->getClass(), "");
}

TEST_F(FormViewTests, test_getType) {
    EXPECT_EQ(formView->getType(), "");
}
TEST_F(FormViewTests, test_append) {
    formView->append(*new View("testform",Type::DIV,BClass::CARD_BODY));
    EXPECT_EQ(formView->toString(), "<form action= \"test\" method= \"test\" enctype= \"test\">\n\n   <div class=\"card-body\">\n\n   </div>\n\n</form> \n\n");
}
TEST_F(FormViewTests, test_remove) {
    formView->removeSubview("testform");
    EXPECT_EQ(formView->toString(), "<form action= \"test\" method= \"test\" enctype= \"test\">\n\n</form> \n\n");
}

