//
// Created by Сергей Петренко on 2019-12-05.
//

#include "PageData.h"

PageData::PageData(std::vector<UserData *> u, PageType t, Organize o) {
    type = t;
    userData = u;
    organize = o;
}

void PageData::setOrganizeType(Organize o) {
    organize = o;
}

void PageData::setPageType(PageType t) {
    type = t;
}