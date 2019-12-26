//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_PAGEMANAGER_H
#define CPPROJECT_PAGEMANAGER_H

#include <PageGenerator/PageGenerator.h>
#include <fstream>
#include <thread>
#include <iostream>
#include <utility>

class PageManager {
private:
    std::vector<UserData*> userData;
    PageGenerator *pageGenerator;
    Page* startPage;

public:
    std::vector<Page*> userPages;
    PageManager(std::vector<UserData*> userdata, int port) {
        userData = std::move(userdata);
        pageGenerator = new PageGenerator(port);
    }

    ~PageManager() {
    }

    void generatePages(std::vector<UserData*> usersData) {
        pageGenerator->generateSimilarUsersPage(usersData,Organize::RECT_HORIZONTAL);
        startPage = pageGenerator->page;

        for(int i = 0; i < userData.size(); i++){
            userPages.emplace_back(pageGenerator->generateUserPage(*userData[i]));
        }
    }



};

#endif //CPPROJECT_PAGEMANAGER_H
