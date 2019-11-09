//
// Created by Сергей Петренко on 2019-11-07.
//

#include "View.h"

void View::append_in_subview(View m_view, string sv_path) {

}



View::View() {

}

View::View(string m_view_template) {

}

View View::get_subview_by_name(View m_view, string name) {
    return View();
}

string View::to_string(StringProperty property) {
    return std::string();
}

void View::set_name(string m_name) {

}

void View::set_view_template(string m_view_template) {

}

string View::get_view_template() {
    return std::string();
}

string View::get_name() {
    return std::string();
}

void View::remove_subview(View m_view, string sv_path) {

}

ImageView::ImageView() {

}

ImageView::ImageView(string m_image_path) : View(m_image_path) {

}

void ImageView::set_image_path(string m_image_path) {

}

string ImageView::get_image_path() {
    return std::string();
}

StringProperty::StringProperty() {

}

TextView::TextView() {

}

TextView::TextView(string m_text) : View(m_text) {

}

void TextView::set_text(string m_text) {

}

string TextView::get_text() {
    return std::string();
}

Button::Button() {

}

Button::Button(string path, string text) {

}

RowView::RowView() {

}

ColumnView::ColumnView() {

}

ColumnView::ColumnView(int rows_count) {

}

TableView::TableView() {

}

TableView::TableView(int rows, int columns) {

}

void TableView::append_in_row(View m_view, string path) {

}

int TableView::get_row_count() {
    return 0;
}

int TableView::get_colums_count() {
    return 0;
}

void TableView::remove_column(View m_view, string path) {

}
void TableView::remove_row(View m_view, string path) {

}