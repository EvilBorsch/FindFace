//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_PAGEMANAGER_H
#define CPPROJECT_PAGEMANAGER_H

#include "PageGenerator/PageGenerator.h"


class PageManager{
private:
    PageData data;
    PageGenerator pageGenerator;
public:
    PageManager();
    PageManager(PageData m_data);

};

#endif //CPPROJECT_PAGEMANAGER_H
