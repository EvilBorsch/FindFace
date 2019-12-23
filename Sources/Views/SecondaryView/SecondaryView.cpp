//
// Created by Сергей Петренко on 2019-12-04.
//

#include "SecondaryView.h"

SecondaryView::SecondaryView(std::string name, Type t,
                             std::vector<Attribute> attr) {
    attributes = attr;
    type = enumToString(t);
}

std::string SecondaryView::toStringOpen(int depth) {
    std::string res;

    res += "<" + type + " ";
    for (int i = 0; i < attributes.size(); i++) {
        if (std::strcmp(attributes[i].getKey().data(), "TEXT")) {
            res += attributes[i].getKey() + "=\"" + attributes[i].getValue() + "\" ";
        } else {
            res += ">" + attributes[i].getValue();
        }
    }

    return res;
}

std::string SecondaryView::toStringClose(int depth) {
    std::string res;

    if (!strcmp(type.data(), "script")) {
        res += "></" + type;
    }
    else if (!strcmp(type.data(), "a") || !strcmp(type.data(), "label") ||
               !strcmp(type.data(), "span") || !strcmp(type.data(), "button")) {
        res += "</" + type;
    }
    res += ">\n";
    return res;
}

std::string SecondaryView::toString(int depth) {
    return toStringOpen(depth) + toStringClose(depth);
}


bool
SecondaryView::appendInSubview(std::string subviewName, ContainerView &mView) {
    return false;
}

bool SecondaryView::append(ContainerView &mView) {

}

void SecondaryView::destroy() {

}

bool SecondaryView::removeSubview(std::string subviewName) {

}

SecondaryView::~SecondaryView() {

}

Attribute::Attribute(std::string k, std::string v) {
    key = std::move(k);
    value = std::move(v);
}

Attribute::Attribute(std::string templateAttibute) {
    std::vector<std::string> result;
    boost::replace_all_copy(templateAttibute, "\"", "");
    boost::split(result, templateAttibute, boost::is_any_of("="));
    if (result.size() == 2) {
        key = std::move(result[0]);
        value = std::move(result[1]);
    } else {
        key = "attribute";
        value = "value";
    }
}
