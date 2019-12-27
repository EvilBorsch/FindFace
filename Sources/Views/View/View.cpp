//
// Created by Сергей Петренко on 2019-11-07.
//

#include "View.h"




View::View(std::string n, Type t, BClass c) {
    name = n;
    type = enumToString(t);
    _class = enumToString(c);
    id ="";
    action = "";
}

View::View(std::string n, Type t) {
    name = n;
    type = enumToString(t);
    _class = "";
    id ="";
    action = "";
}

std::string View::toStringOpen(int depth) {

    std::string res;
    for (int i = 0; i < 3 * depth; i++) {
        res += " ";
    }
    res += "<" + getType() + " class=\"" + getClass()+"\"";
    if(std::strcmp(id.data(),"")){
        res+= " id= \"" + getId()+"\"";
    }
    res+=">\n\n";
    return res;
}

std::string View::toStringClose(int depth) {
    std::string res;
    for (int i = 0; i < 3 * depth; i++) {
        res += " ";
    }
    if(std::strcmp(getType().data(),"li")){
    res += "</" + getType() + ">\n\n";
        }
    else
        res += "<" + getType() + ">\n\n";
    return res;
}

std::string View::toString(int depth) {
    std::string res;
    if (depth == 0) {
        res += "<" + getType() + " class=\"" + getClass()+"\"" + " action=" + getAction();
        if(!std::strcmp(id.data(),"")){
            res+= " id= \"" + getId()+"\"";
        }
        res+=  ">\n\n";
        depth++;
    }
    if (!subviews.empty()) {
        for (ContainerView &v: subviews) {
            res += v.toStringOpen(depth);
            depth++;
            if (!v.subviews.empty()) {
                res += v.toString(depth);
            }
            res += v.toStringClose(--depth);

        }

    }
    if (--depth == 0) {
        res += "</" + getType() + ">\n\n";
    }
    return res;
}

bool View::appendInSubview(std::string subviewName, ContainerView &mView) {

    for (ContainerView &v : subviews) {
        if (std::strcmp(subviewName.data(), v.getName().data()) == 0) {
            v.append(mView);
            return true;
        }
        if (!v.subviews.empty()) {
            v.appendInSubview(subviewName, mView);
        }
    }
    return false;
}

bool View::append(ContainerView &mView) {
    subviews.emplace_back(mView);
}

void View::destroy() {
    int i = 0;
    for (ContainerView &v: subviews) {
        if (!v.subviews.empty()) {
            v.destroy();
        }
        subviews.clear();
        i++;
    }
}

bool View::removeSubview(std::string subviewName) {
    int i = 0;
    for (ContainerView &v : subviews) {
        auto it = std::find_if(v.subviews.begin(), v.subviews.end(),
                               [&](ContainerView &v) {
                                   return std::strcmp(v.getName().data(),
                                                      subviewName.data());
                               });
        if (it == v.subviews.end()) {
            v.subviews[i].get().destroy();
            v.subviews.erase(v.subviews.begin() + i);
        }

        if (std::strcmp(subviewName.data(), v.getName().data()) == 0) {
            v.destroy();
        }
        if (!v.subviews.empty()) {
            v.removeSubview(subviewName);
        }
        i++;
    }
}

View::~View() {
    destroy();
}

View::View(std::string viewName, Type t, BClass c, std::string _id) {
    name = viewName;
    type = enumToString(t);
    _class = enumToString(c);
    id = _id;
}



