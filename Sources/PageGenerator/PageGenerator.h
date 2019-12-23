//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_PAGEGENERATOR_H
#define CPPROJECT_PAGEGENERATOR_H

#include <math.h>
#include <Page/Page.h>
//#include <Views/PersonView/PersonView.h>
//#include <Views/Form/FormView.h>
#include <PageData/PageData.h>




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
