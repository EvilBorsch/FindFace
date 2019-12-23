//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_PAGEGENERATOR_H
#define CPPROJECT_PAGEGENERATOR_H

#include <math.h>
#include <StaticGeneration/Page/Page.h>
#include <StaticGeneration/Views/PersonView/PersonView.h>
#include <StaticGeneration/Views/Form/FormView.h>
#include <StaticGeneration/PageData/PageData.h>




class PageGenerator {

public:
    int PORT;
    Page *page;

    PageGenerator(int port){
        PORT = port;
    }

    Page *generateTablePage(std::vector<UserData *> userData, Organize o);

    Page *generateStartPage(std::vector<UserData *> userData);

    Page *generateUserPage(UserData userData);

    Page *generateSimilarUsersPage(std::vector<UserData *> userData, Organize o);

    Page *generateLinkPage(std::string url);


};


#endif //CPPROJECT_PAGEGENERATOR_H
