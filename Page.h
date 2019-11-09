//
// Created by Сергей Петренко on 2019-11-07.
//

#ifndef CPPROJECT_PAGE_H
#define CPPROJECT_PAGE_H


#include "View.h"
#include <string.h>

using std::string;
using std::vector;
class PageData{
public:
    PageData();
    PageData(string response_from_server);
    vector<string> image_urls;
    vector<string> user_urls;
    map<string,string> static_files;
    void get_static();
};


class Page {
protected:
    View view;
public:
    Page();
    Page(PageData page_data);
    void append_to_head(PageData page_data, string sv_path);
    void append_in_view(PageData page_data, string sv_path);
    void delete_view(string m_name);
    string to_string();
};

class PageGenerator{
private:
    string url;
    PageData data;
protected:
    Page page;
public:
    PageGenerator();
    Page generate_start_page();
    Page generate_result_page(PageData m_data);
    PageData get_page_data();

};

class PageManager{
private:
    PageData data;
    PageGenerator pageGenerator;
public:
    PageManager();
    PageManager(PageData m_data);
    void get_from_server();
    void push_to_server();
    PageGenerator get_page_generator();

};


#endif //CPPROJECT_PAGE_H
