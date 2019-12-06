//
// Created by Сергей Петренко on 2019-11-16.
//

#include "ImageView.h"

void ImageView::append(ContainerView &mView){}
bool ImageView::appendInSubview(std::string subviewName, ContainerView& mView){return false;}
void ImageView::removeSubview(std::string subviewName){}
void ImageView::destroy(){}


ImageView::ImageView(std::string n, Type t, BClass c, std::string s, int h, int w){
    name = n;
    type = enumToString(t);
    _class = enumToString(c);
    src = s;
    height = h;
    width = w;
}
std::string ImageView::toStringOpen(int depth) {
    std::string res = "";
    for(int i=0;i<3*depth;i++){
    res+=" ";
    }
    res += "<"+type
    + " class=\""
    + _class +
    "\" src=\""
    + src +"\""
    + R"( alt="" width=")"
    + std::to_string(width)
    +"\" height=\""
    + std::to_string(height)
    + "\">\n\n";
    return res;
}
std::string ImageView::toStringClose(int depth ) {
return "";
}
std::string ImageView::toString(int depth) {
return toStringOpen(depth)+toStringClose(depth);
}