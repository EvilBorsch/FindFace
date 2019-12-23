//
// Created by Сергей Петренко on 2019-12-17.
//

#include "FormView.h"

std::string FormView::toStringOpen(int depth) {
    std::string res;
    for (int i = 0; i < 3 * depth; i++) {
        res += " ";
    }
    res +=  "<form action= \"" + getAction() + "\" method= \""+ getMethod()+ "\" enctype= \""+ getEnctype()+"\"";
    res+=  ">\n\n";
    return res;
}

std::string FormView::toStringClose(int depth) {
    std::string res;
    for (int i = 0; i < 3 * depth; i++) {
        res += " ";
    }

        res += "</form>\n\n";
    return res;
}

std::string FormView::toString(int depth) {
    std::string res;
    if (depth == 0) {
        res += "<form action= \"" + getAction() + "\" method= \""+ getMethod()+ "\" enctype= \""+ getEnctype()+"\"";
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
        res += "</form> \n\n";
    }
    return res;
}

bool FormView::appendInSubview(std::string subviewName, ContainerView &mView) {
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

bool FormView::append(ContainerView &mView) {
    subviews.emplace_back(mView);
}

void FormView::destroy() {
    int i = 0;
    for (ContainerView &v: subviews) {
        if (!v.subviews.empty()) {
            v.destroy();
        }
        subviews.clear();
        i++;
    }
}

bool FormView::removeSubview(std::string subviewName) {
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