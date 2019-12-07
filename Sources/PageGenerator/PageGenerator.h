//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_PAGEGENERATOR_H
#define CPPROJECT_PAGEGENERATOR_H

#include <math.h>
#include "Page/Page.h"
#include "Views/PersonView/PersonView.h"
#include "PageData/PageData.h"


class PageGenerator{

public:

    Page* page;
    PageGenerator() = default;

    void organizeCells(Organize o, int& rows, int& cells, int count);

    Page* generateTablePage(std::vector<UserData*> userData, Organize o);

    Page* generateStartPage();

    Page* generateUserPage(UserData userData);



};


#endif //CPPROJECT_PAGEGENERATOR_H
