//
// Created by Сергей Петренко on 2019-11-16.
//

#include "ImageView.h"

bool ImageView::append(ContainerView &mView) {
    return false;
}

bool ImageView::appendInSubview(std::string subviewName, ContainerView &mView) {
    return false;
}

bool ImageView::removeSubview(std::string subviewName) {
    return false;
}

void ImageView::destroy() {

}

ImageView::ImageView(std::string n, Type t, BClass c, std::string s, int h,
                     int w) {
    name = n;
    type = enumToString(t);
    _class = enumToString(c);
    src = s;
    height = h;
    width = w;
}
ImageView::ImageView(std::string n, Type t, BClass c, std::string s) {
    name = n;
    type = enumToString(t);
    _class = enumToString(c);
    src = s;
    height = 0;
    width = 0;
}

std::string ImageView::toStringOpen(int depth) {
    std::string res = "";
    for (int i = 0; i < 3 * depth; i++) {
        res += " ";
    }
    res += "<" + type + " class=\"" + _class + "\" src=\"" + src + "\""
           + R"( alt="" width=")" + ((width==0)? "":std::to_string(width))
           + "\" height=\"" + ((height == 0)?"":std::to_string(height)) + "\">\n\n";
    return res;
}

std::string ImageView::toStringClose(int depth) {
    return "";
}

std::string ImageView::toString(int depth) {
    return toStringOpen(depth) + toStringClose(depth);
}

ImageView::~ImageView() {

}
