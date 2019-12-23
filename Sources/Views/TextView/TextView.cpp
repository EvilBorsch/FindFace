//
// Created by Сергей Петренко on 2019-11-16.
//

#include <boost/algorithm/string.hpp>
#include "TextView.h"
#include "iostream"

bool TextView::append(ContainerView &mView){
    return false;
}
bool TextView::appendInSubview(std::string subviewName, ContainerView& mView){
    return false;
}
bool TextView::removeSubview(std::string subviewName){
    return false;
}
void TextView::destroy(){

}


TextView::TextView(std::string n, Type t, BClass c, std::string txt){
    name = std::move(n);
    type = enumToString(t);
    _class = enumToString(c);
    text = std::move(txt);
};
TextView::TextView(std::string n, Type t, std::string txt){
    name = std::move(n);
    type = enumToString(t);
    _class = "";
    text = std::move(txt);
};

void TextView::setText(std::string mText){
    text = mText;
}

std::string TextView::getText(){
    return text;
}

std::string TextView::toStringOpen(int depth) {
    std::string res;
    for(int i=0;i<3*depth;i++){
        res+=" ";
    }
    res += "<"+type + " class=\""+ _class+"\">"+text;
    return res;
}
std::string TextView::toStringClose(int depth) {
    std::string res;
    res += "</"+type+">\n\n";
    return res;
}
std::string TextView::toString(int depth) {
    return toStringOpen(depth)+toStringClose(depth);
}

TextView::~TextView() {

}

TextView::TextView(std::string templateTextView){
    std::vector<std::string> result;

    templateTextView = boost::replace_all_copy(templateTextView, "<", " ");
    templateTextView = boost::replace_all_copy(templateTextView, ">", " ");

    std::cout<<templateTextView<<std::endl;

    boost::split(result, templateTextView, boost::is_any_of(" "));
    type = result[0];
    boost::split(result, templateTextView, boost::is_any_of("\""));
    _class = result[1];
    boost::split(result, result[2], boost::is_any_of("/"));
    text = result[0];


}
