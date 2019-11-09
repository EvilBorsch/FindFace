//
// Created by Сергей Петренко on 2019-11-07.
//

#ifndef CPPROJECT_CONTAINERVIEW_H
#define CPPROJECT_CONTAINERVIEW_H
#include <string>
#include <algorithm>
#include <map>


using std::vector;
using std::string;
using std::map;

class ContainerView {
private:
    string path;
    ContainerView *parent;
    string selector;
    string tag;
    map<string,string> attributes;
public:
    ContainerView();
    ContainerView* get_parent();
    void set_parent(ContainerView *containerView);
    string get_selector();
    string get_type();
    string get_path();
    void set_type(string m_type);
};


#endif //CPPROJECT_CONTAINERVIEW_H
