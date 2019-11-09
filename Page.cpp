//
// Created by Сергей Петренко on 2019-11-07.
//

#include "Page.h"

PageGenerator::PageGenerator() {

}

Page PageGenerator::generate_start_page() {
    return Page();
}

Page PageGenerator::generate_result_page(PageData m_data) {
    return Page();
}

PageData PageGenerator::get_page_data() {
    return PageData();
}

void PageManager::get_from_server() {

}

void PageManager::push_to_server() {

}

PageManager::PageManager() {

}

PageManager::PageManager(PageData m_data) {

}

PageGenerator PageManager::get_page_generator() {
    return PageGenerator();
}

Page::Page() {

}

void Page::append_to_head(PageData page_data, string sv_path) {

}

void Page::append_in_view(PageData page_data, string sv_path) {

}

void Page::delete_view(string m_name) {

}

string Page::to_string() {
    return std::string();
}

Page::Page(PageData page_data) {

}


void PageData::get_static() {
}

PageData::PageData(string response_from_server) {

}

PageData::PageData() {

}
