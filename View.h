//
// Created by Сергей Петренко on 2019-11-07.
//

#ifndef CPPROJECT_VIEW_H
#define CPPROJECT_VIEW_H


#include "ContainerView.h"
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using std::vector;
using std::string;
using std::map;

class StringProperty{
public:
    bool is_new_line;
    bool is_tag_close;
    int indent;
    StringProperty();
};

class View: public ContainerView{
protected:
    string name;
    string type;
    string view_template;
    vector<View> subviews;

public:
    View();
    View(string m_view_template);
    View get_subview_by_name(View m_view, string name);

    string to_string(StringProperty property);
    void set_name(string m_name);
    void set_view_template(string m_view_template);
    void append_in_subview(View m_view,string sv_path);
    void remove_subview(View m_view,string sv_path);
    string get_view_template();
    string get_name();
};

class ImageView: public View{
private:
    string image_path;
public:
    ImageView();
    ImageView(string m_image_path);
    void set_image_path(string m_image_path);
    string get_image_path();

};

class TextView: public View{
private:
    string text;
public:
    TextView();
    TextView(string m_text);
    void set_text(string m_text);
    string get_text();

};

class Button: public TextView, public ImageView{
public:
    Button();
    Button(string path,string text);
};

class RowView: protected View{
public:
    RowView();
};

class ColumnView: public View{
protected:
    vector<RowView> rows;
public:
    ColumnView();
    ColumnView(int rows_count);
};

class TableView: public View{
private:
    int rows_count;
    int columns_count;
protected:
    vector<ColumnView> rows;
public:
    TableView();
    TableView(int rows, int columns);
    void append_in_row(View m_row, string path);
    void remove_column(View m_column, string path);
    void remove_row(View m_row, string path);
    int get_row_count();
    int get_colums_count();

};

#endif //CPPROJECT_VIEW_H
