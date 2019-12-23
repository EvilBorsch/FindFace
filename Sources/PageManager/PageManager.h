//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_PAGEMANAGER_H
#define CPPROJECT_PAGEMANAGER_H

#include <StaticGeneration/PageGenerator/PageGenerator.h>
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
//        std::vector<UserData *> usersData{
//                new UserData("Stalin.su", "Дмитрий", "Болдин",
//                             "https://sun9-70.userapi.com/c205424/v205424565/2840/Q9ExfkJtduQ.jpg",
//                             19),
//                new UserData("Kek", "Дмитрий", "Гуляченков",
//                             "https://sun9-14.userapi.com/c844321/v844321164/1e3f38/sjVui97PcoU.jpg",
//                             19),
//                new UserData("Averkiller1", "Александр", "Аверкиев",
//                             "https://sun9-6.userapi.com/c857536/v857536032/10e4a0/yPxRO3gAIb0.jpg",
//                             19),
//                new UserData("Sarkiss", "Сергей", "Петренко",
//                             "https://sun9-49.userapi.com/c850732/v850732072/7dac/26Ja2edmJwU.jpg",
//                             19)
//        };

        pageGenerator->generateSimilarUsersPage(usersData,Organize::RECT_HORIZONTAL);
        startPage = pageGenerator->page;

        for(int i = 0; i < userData.size(); i++){
            userPages.emplace_back(pageGenerator->generateUserPage(*userData[i]));
        }
    }


//    void generatePages() {
//        std::ofstream out("tablepage.html");
//        out << pageGenerator->generateTablePage(data->userData,
//                                                data->getPageOrganizeType())->toString();
//        out.close();
//        std::vector<std::thread> vecOfThreads;
//        int i = 0;
//        for (auto &userData: data->userData) {
//            std::string name = "userpage" + std::to_string(i++);
//            vecOfThreads.push_back(std::thread(
//                    std::bind(&PageManager::threadGeneratePage, *this)));
//        }
//        for (std::thread &th : vecOfThreads) {
//            if (th.joinable()) {
//                th.join();
//            }
//        }
//    }

    void threadGeneratePage() {
        UserData *testData = new UserData("slug", "fname", "sname", "imgsrc",
                                          19);
        std::ofstream out("file.txt");
        out << pageGenerator->generateUserPage(*testData);
        out.close();
    }

};

#endif //CPPROJECT_PAGEMANAGER_H
