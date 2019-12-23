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

ContainerView::ContainerView(std::string containerName, Type containerType, std::string containerClass){
    name = containerName;
    type = enumToString(containerType);
    _class = containerClass;
    id = "";
}
ContainerView::ContainerView(std::string containerName, Type containerType, std::string containerClass, std::string containerId ){
    name = containerName;
    type = enumToString(containerType);
    _class = containerClass;
    id = containerId;
}

std::string ContainerView::getAction() {
    return action;
}

