//
// Created by Сергей Петренко on 2019-12-04.
//

#include "SecondaryView.h"

SecondaryView::SecondaryView(std::string name, Type t, std::vector<Attribute> attr){
    attributes = attr;
    type = enumToString(t);
}

std::string SecondaryView::toStringOpen(int depth){
    std::string res;
    res+="<"+type+" ";
    for(int i = 0; i < attributes.size();i++){
        res+=attributes[i].key + "=\"" + attributes[i].value+"\" ";
    }
    return res;
}

std::string SecondaryView::toStringClose(int depth) {
    return ">\n";
}

std::string SecondaryView::toString(int depth) {
    return toStringOpen(depth)+toStringClose(depth);
}


bool SecondaryView::appendInSubview(std::string subviewName, ContainerView& mView) {
    return false;
}

void SecondaryView::append(ContainerView &mView){

}

void SecondaryView::destroy() {

}

void SecondaryView::removeSubview(std::string subviewName) {

}