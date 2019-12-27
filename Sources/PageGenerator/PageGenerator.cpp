//
// Created by Сергей Петренко on 2019-11-16.
//

#include "PageGenerator.h"
#include "Samples/SampleViews.h"


Page *
PageGenerator::generateTablePage(std::vector<UserData *> userData, Organize o) {
    page = new Page();
    std::vector<PersonView *> persons;
    int i = 0;
    for (auto &u : userData) {
        persons.push_back(new PersonView(*u, i++));
    }
    int rowsCount = 0;
    int cellsCount = 0;
    organizeCells(o, rowsCount, cellsCount, userData.size());
    View *view = new View("Main", Type::DIV, BClass::CARD_DECK);
    TableView *tableView = new TableView("Table", rowsCount, cellsCount);
    int r = 0;
    int c = 0;
    tableView->appendCell(
            std::make_shared<CellView>(*new CellView(c, rowsCount)));
    for (auto &p: persons) {
        tableView->appendRowInCell(c, std::make_shared<RowView>(
                *new RowView(r, *p)));
        r++;
        if (r >= rowsCount) {
            r = 0;
            tableView->appendCell(
                    std::make_shared<CellView>(*new CellView(++c, rowsCount)));
        }
    }
    page->appendInBody(*tableView);
    return page;
}



Page *PageGenerator::generateStartPage(std::vector<UserData *> userData) {
    const std::string title1 = "ФайндФейс";
    const std::string title2 = "Разработчики проекта";
    const std::string link = "http://localhost:"+ std::to_string(PORT) + "/request/";
    page = new Page();
    View *v = new View("Main", Type::DIV);
    View *nav = createNavbar();
    v->append(*nav);
    v->append(*createHead(title1));
    v->append(*createDevSection(userData,title2));
    v->append(*createFileForm(link));
    v->append(*createContactSection());
    page->appendInBody(*v);
    return page;
}

Page *PageGenerator::generateLinkPage(std::string url) {
    const std::string title1 = "ФайндФейс";
    const std::string title2 = "Разработчики проекта";
    const std::string link = "http://localhost:" + std::to_string(PORT) + "/request/";
    page = new Page();
    View *v = new View("Main", Type::DIV);
    View *nav = createNavbar();
    v->append(*nav);
    v->append(*createHead(title1));
    v->append(*new TextView("URL",Type::H4,BClass::TEXT_NORMAL,url));
    v->append(*createFileForm(link));
    v->append(*createContactSection());
    page->appendInBody(*v);
    return page;
}

Page *PageGenerator::generateUserPage(UserData userData) {
    const std::string title = "Мы что-то нашли";

    page = new Page();
    View *v = new View("Main", Type::DIV);
    View *nav = createNavbar();
    v->append(*nav);
    v->append(*createDecorate());
    v->append(*createUserCard(&userData));
    v->append(*createContactSection());
    page->appendInBody(*v);

    return page;
}


Page *PageGenerator::generateSimilarUsersPage(std::vector<UserData *> userData,Organize o) {
    const std::string title = "Мы что-то нашли";

    page = new Page();

    View *v = new View("Main", Type::DIV);
    v->append(*createNavbar());
    v->append(*createBar("Похожие"));
    v->append(*new View("usersContainer", Type::DIV,BClass::CONTAINER));
    v->appendInSubview("usersContainer",*createUserTable(userData,Organize::RECT_HORIZONTAL));
    v->append(*createContactSection());
    page->appendInBody(*v);

    return page;
}

Page *PageGenerator::generateLinkWithImgPage(std::string img, std::string url) {
    const std::string title1 = "ФайндФейс";
    const std::string title2 = "Разработчики проекта";
    const std::string link = "http://localhost:" + std::to_string(PORT) + "/request/";
    page = new Page();
    View *v = new View("Main", Type::DIV);
    View *nav = createNavbar();
    v->append(*nav);
    v->append(*createHead(title1));
    v->append(*createFoundedUserSection(img,url));
    v->append(*createFileForm(link));
    v->append(*createContactSection());
    page->appendInBody(*v);
    return page;
}

Page *PageGenerator::generateManyLinkWithImgPage(std::string img, std::vector<std::string> urls){
    const std::string title1 = "ФайндФейс";
    const std::string title2 = "Разработчики проекта";
    const std::string link = "http://localhost:" + std::to_string(PORT) + "/request/";
    page = new Page();
    View *v = new View("Main", Type::DIV);
    View *nav = createNavbar();
    v->append(*nav);
    v->append(*createHead(title1));
    for(auto& u: urls){
        v->append(*createFoundedUserSection(img,u));
    }
    v->append(*createFileForm(link));
    v->append(*createContactSection());
    page->appendInBody(*v);
    return page;
}


Page *PageGenerator::generateMessagePage(std::string msg){
    const std::string title1 = "ФайндФейс";
    const std::string title2 = "Разработчики проекта";
    const std::string link = "http://localhost:" + std::to_string(PORT) + "/request/";
    page = new Page();
    View *v = new View("Main", Type::DIV);
    View *nav = createNavbar();
    v->append(*nav);
    v->append(*createHead(title1));
    v->append(*new View("ContainerMsg",Type::DIV,BClass::FLEX_COLUMN));
    v->appendInSubview("ContainerMsg",*new TextView("MSG",Type::H4,BClass::TEXT_NORMAL,msg));
    v->append(*createFileForm(link));
    v->append(*createContactSection());
    page->appendInBody(*v);
    return page;
}