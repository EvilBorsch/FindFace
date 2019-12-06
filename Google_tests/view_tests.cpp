//
// Created by Сергей Петренко on 2019-11-08.
//
#include "gtest/gtest.h"
#include "Container/ContainerView.h"
#include "View/View.h"

//class TestViews : public ::testing::Test
//{
//protected:
//    void SetUp() override
//    {
//        string_property = new StringProperty();
//        view = new View();
//
//    }
//    void TearDown() override
//    {
//        delete string_property;
//        delete view;
//    }
//    View *view;
//    StringProperty *string_property;
//};
//
//TEST_F(TestViews, test_set_get_template)
//{
//    view->set_view_template("p");
//    ASSERT_EQ(view->get_view_template(), "p");
//}
//
//TEST_F(TestViews, test_set_get_name)
//{
//    view->set_name("string_view");
//    ASSERT_EQ(view->get_view_template(), "string_view");
//}
//
//TEST_F(TestViews, test_to_string)
//{
//    view->set_view_template("<p>*name=*</p>");
//    view->set_name("string_view");
//    ASSERT_EQ(view->to_string(*string_property),
//            "<p>name=sting_view</p>");
//}
//
//TEST_F(TestViews, test_add_subview)
//{
//    view->set_view_template("<p>*name=*</p>");
//    view->set_name("string_view");
//    View *subview = new View();
//    subview->set_view_template("<p>*name=*</p>");
//    subview->set_name("substring_view");
//    view->append_in_subview(*subview,view->get_path());
//
//    ASSERT_EQ(view->to_string(*string_property),
//            "<p>name=sting_view <p>name=substring_view</p></p>");
//}
//TEST_F(TestViews, test_remove_subview)
//{
//    view->set_view_template("<p>*name=*</p>");
//    view->set_name("string_view");
//    View *subview = new View();
//    subview->set_view_template("<p>*name=*</p>");
//    subview->set_name("substring_view");
//    view->append_in_subview(*subview,view->get_path());
//    view->remove_subview(*view,subview->get_path());
//    ASSERT_EQ(view->to_string(*string_property),
//            "<p>name=sting_view</p>");
//}
//TEST_F(TestViews, test_remove_subview_by_name)
//{
//    view->set_view_template("<p>*name=*</p>");
//    view->set_name("string_view");
//    View *subview = new View();
//    subview->set_view_template("<p>*name=*</p>");
//    subview->set_name("substring_view");
//    view->append_in_subview(*subview,view->get_path());
//    view->remove_subview(*view,
//            view->get_subview_by_name(*view,"subsring_view").get_path());
//    ASSERT_EQ(view->to_string(*string_property),
//            "<p>name=sting_view</p>");
//}
//
//
//class TestTextViews : public ::testing::Test
//{
//protected:
//    void SetUp() override
//    {
//        string_property = new StringProperty();
//        tv = new TextView();
//
//    }
//    void TearDown() override
//    {
//        delete string_property;
//        delete tv;
//    }
//    TextView *tv;
//    StringProperty *string_property;
//};
//TEST_F(TestTextViews, test_to_string)
//{
//    tv->set_view_template("<p>*name=**text*</p>");
//    tv->set_name("text_view");
//    tv->set_text("sample_text");
//    ASSERT_EQ(tv->to_string(*string_property), "<p>name=sting_view sample_text</p>");
//}
//
//class TestImageViews : public ::testing::Test
//{
//protected:
//    void SetUp() override
//    {
//        string_property = new StringProperty();
//        iv = new ImageView();
//
//    }
//    void TearDown() override
//    {
//        delete string_property;
//        delete iv;
//    }
//    ImageView *iv;
//    StringProperty *string_property;
//};
//TEST_F(TestImageViews, test_to_string)
//{
//    iv->set_view_template("<p>*name=**img=*</p>");
//    iv->set_name("text_view");
//    iv->set_image_path("image_path");
//    ASSERT_EQ(iv->to_string(*string_property), "<p>name=sting_view sample_text</p>");
//}
//
//class TestButtons : public ::testing::Test
//{
//protected:
//    void SetUp() override
//    {
//        string_property = new StringProperty();
//        button = new Button();
//
//    }
//    void TearDown() override
//    {
//        delete string_property;
//        delete button;
//    }
//    Button* button;
//    StringProperty *string_property;
//};
//
//
//class TestTableViews : public ::testing::Test
//{
//protected:
//    void SetUp() override
//    {
//        string_property = new StringProperty();
//        tableView = new TableView(2,2);
//        columnView = new ColumnView(tableView->get_row_count());
//        rowView = new RowView();
//    }
//    void TearDown() override
//    {
//        delete string_property;
//        delete rowView;
//        delete columnView;
//        delete tableView;
//    }
//    RowView *rowView;
//    ColumnView *columnView;
//    TableView *tableView;
//    StringProperty *string_property;
//};
//
//TEST_F(TestTableViews, test_append)
//{
//    tableView->set_view_template("table_view_template");
//    tableView->set_name("table_view_name");
//    tableView->append_in_row(View(),"container/table/row");
//    ASSERT_EQ( tableView->to_string(*string_property),
//            "template_for_tableview_with_params_and_new_row");
//}
//TEST_F(TestTableViews, test_delete)
//{
//    tableView->set_view_template("table_view_template");
//    tableView->set_name("table_view_name");
//    tableView->remove_row(View(),"container/table/row");
//    tableView->remove_column(View(),"container/table/row");
//    ASSERT_EQ( tableView->to_string(*string_property),
//               "template_for_tableview_with_deleted_rows_and_columns");
//}
//
//TEST_F(TestTableViews, test_index_for_columns)
//{
//    tableView->set_view_template("table_view_template");
//    tableView->set_name("table_view_name");
//    tableView->remove_row(View(),"container/table/row");
//    tableView->remove_column(View(),"container/table/column");
//    ASSERT_THROW(tableView->remove_row(View(),"container/table/row"), std::out_of_range);
//}






