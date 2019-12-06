//
// Created by Сергей Петренко on 2019-11-16.
//

#include "RowView.h"


RowView::RowView(int indx){
    type = enumToString(Type::ROW);
    scope = "scope";
    index = indx;
}
RowView::RowView(int indx, ContainerView& containerView){
    type = enumToString(Type::ROW);
    scope = "scope";
    index = indx;
    append(containerView);
}
RowView::RowView( ContainerView& containerView){
type = enumToString(Type::ROW);
scope = "scope";
append(containerView);
}

void RowView::setIndex(int indx){
    index = indx;
}

std::string RowView::toString(int depth)  {
std::string res;
if(depth == 0){
res += "<"+getType() + " scope=\""+ scope+"\">\n\n";
depth++;
}
if(!subviews.empty()) {
for (ContainerView &v: subviews) {
res += v.toStringOpen(depth);
depth++;
if (!v.subviews.empty()) {
res += v.toString(depth);
}
res+=v.toStringClose(--depth);
}
}
if(--depth == 0){
res+="</"+getType() +">\n\n";
}
return res;
}

std::string RowView::toStringOpen(int depth){
    std::string res;
    for(int i=0;i<3*depth;i++){
        res+=" ";
    }
    res += "<"+type + " scope=\""+ scope+"\">\n\n";
    return res;
}
std::string RowView::toStringClose(int depth){
    std::string res;
    for(int i=0;i<3*depth;i++){
        res+=" ";
    }
    res += "</"+type+">\n\n";
    return res;
}

void RowView::append(ContainerView &mView){
    subviews.push_back(mView);
}
bool RowView::appendInSubview(std::string subviewName, ContainerView& mView){

}
void RowView::removeSubview(std::string subviewName){

}
void RowView::destroy(){

}