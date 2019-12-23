//
// Created by Сергей Петренко on 2019-11-07.
//

#include "ContainerView.h"

std::string ContainerView::getName(){
    return name;
}

std::string ContainerView::getType(){
    return type;
}
std::string ContainerView::getClass(){
    return _class;
}
std::string ContainerView::getId(){
    return id;
}

ContainerView::ContainerView(std::string n, Type t, std::string c){
    name = n;
    type = enumToString(t);
    _class = c;
    id = "";
}
ContainerView::ContainerView(std::string n, Type t, std::string c, std::string _id ){
    name = n;
    type = enumToString(t);
    _class = c;
    id = _id;
}

std::string ContainerView::getAction() {
    return action;
}

