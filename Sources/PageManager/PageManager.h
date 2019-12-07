//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_PAGEMANAGER_H
#define CPPROJECT_PAGEMANAGER_H

#include <PageGenerator/PageGenerator.h>
#include <fstream>
#include <thread>
#include <iostream>

class PageManager {
private:
    PageData *data;
    PageGenerator *pageGenerator;
public:
    PageManager(PageData *mData) {
        data = mData;
        pageGenerator = new PageGenerator();
    }

    ~PageManager() {
    }

    Page *generatePage(PageData &pageData) {
        switch (pageData.getpageType()) {
            case PageType::TABLE_OF_USERS :
                return pageGenerator->generateTablePage(pageData.userData,
                                                        pageData.getPageOrganizeType());

            case PageType::ONE_USER_PAGE :
                return pageGenerator->generateUserPage(
                        reinterpret_cast<UserData &&>(data->userData[0]));

            case PageType::START_PAGE :
                return pageGenerator->generateStartPage();
        }
    }


    void generatePages() {
        std::ofstream out("tablepage.html");
        out << pageGenerator->generateTablePage(data->userData,
                                                data->getPageOrganizeType())->toString();
        out.close();
        std::vector<std::thread> vecOfThreads;
        int i = 0;
        for (auto &userData: data->userData) {
            std::string name = "userpage" + std::to_string(i++);
            vecOfThreads.push_back(std::thread(
                    std::bind(&PageManager::threadGeneratePage, *this)));
        }
        for (std::thread &th : vecOfThreads) {
            if (th.joinable()) {
                th.join();
            }
        }
    }

    void threadGeneratePage() {
        UserData *testData = new UserData("slug", "fname", "sname", "imgsrc",
                                          19);
        std::ofstream out("file.txt");
        out << pageGenerator->generateUserPage(*testData);
        out.close();
    }

};

#endif //CPPROJECT_PAGEMANAGER_H
