//
// Created by Сергей Петренко on 2019-12-23.
//

#include "gtest/gtest.h"

#include "ImageView/ImageView.h"
#include "ImageView/ImageView.cpp"


class ImageViewTests : public ::testing::Test {
protected:
    ImageView *imageView;

    void SetUp() override {
      imageView = new ImageView("test",Type::IMG, BClass::CARD_MB4_SHADOW,"test",1,1);
    }

    void TearDown() override {
        delete imageView;
    }
};

TEST_F(ImageViewTests, test_imageview_constructor) {
    EXPECT_EQ(imageView->toString(0),"<img class=\"card mb-4 shadow-sm\" src=\"test\" alt=\"\" width=\"1\" height=\"1\">\n\n");
}


TEST_F(ImageViewTests, test_getClass) {
    EXPECT_EQ(imageView->getClass(), "card mb-4 shadow-sm");
}

TEST_F(ImageViewTests, test_getType) {
    EXPECT_EQ(imageView->getType(), "img");
}


