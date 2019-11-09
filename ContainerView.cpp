//
// Created by Сергей Петренко on 2019-11-07.
//

#include "ContainerView.h"

ContainerView::ContainerView() {

}

ContainerView *ContainerView::get_parent() {
    return nullptr;
}

void ContainerView::set_parent(ContainerView *containerView) {

}

string ContainerView::get_selector() {
    return std::string();
}

string ContainerView::get_type() {
    return std::string();
}

void ContainerView::set_type(string m_type) {

}

string ContainerView::get_path() {
    return std::string();
}


