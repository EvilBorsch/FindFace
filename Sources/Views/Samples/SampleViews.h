//
// Created by Сергей Петренко on 2019-12-18.
//

#ifndef CPPROJECT_SAMPLEVIEWS_H
#define CPPROJECT_SAMPLEVIEWS_H

#include <View/View.h>

#include "SecondaryView/SecondaryView.h"
#include "ImageView/ImageView.h"
#include "TextView/TextView.h"
#include "PersonView/PersonView.h"
#include "StaticGeneration/PageData/PageData.h"
#include "Form/FormView.h"
#include "StaticGeneration/PageGenerator/PageGenerator.h"


void
organizeCells(Organize o, int &rows, int &cells, int count) {
    switch (o) {
        case Organize::ONE_LINE_VERTICAL:
            rows = 1;
            cells = count;
            break;
        case Organize::ONE_LINE_HORIZONTAL:
            cells = 2;
            rows = count;
            break;

        case Organize::RECT_HORIZONTAL:
            break;
        case Organize::RECT_VERTICAL:
            break;
    }
}


View* createNavbar(){
    View *navBar = new View("mainNav", Type::NAV, BClass::MAIN_NAVBAR, "mainNav");


    navBar->append(*new View("Container", Type::DIV, BClass::CONTAINER));

    navBar->appendInSubview("Container", *new SecondaryView("jsScripts5", Type::A,
                                                            std::vector<Attribute>{
                                                                    Attribute(
                                                                            "class",
                                                                            enumToString(
                                                                                    BClass::NAVBAR_SCROLL_TRIGGER)),
                                                                    Attribute("href",
                                                                              "#page-top"),
                                                                    Attribute("TEXT",
                                                                              "Наш файндвейс"),
                                                            }));
    navBar->appendInSubview("Container", *new View("navbarResponsive", Type::DIV,
                                                   BClass::NAVBAR_COLLPAPSE,
                                                   "navbarResponsive"));

    navBar->appendInSubview("navbarResponsive",
                            *new View("navbarML", Type::UL, BClass::NAVBAR_ML));
    navBar->appendInSubview("navbarML",
                            *new View("navbarItem1", Type::LI, BClass::NAVBAR_ITEM));


    navBar->appendInSubview("navbarItem1",
                            *new SecondaryView("navbarLinkFind", Type::A,
                                               std::vector<Attribute>{
                                                       Attribute("class",
                                                                 enumToString(
                                                                         BClass::NAVBAR_LINK)),
                                                       Attribute("href", "#about"),
                                                       Attribute("TEXT",
                                                                 "Найти человечка"),
                                               }));

    navBar->appendInSubview("navbarML",
                            *new View("navbarItem2", Type::LI, BClass::NAVBAR_ITEM));
    navBar->appendInSubview("navbarItem2",
                            *new SecondaryView("navbarLinkAbout", Type::A,
                                               std::vector<Attribute>{
                                                       Attribute("class",
                                                                 enumToString(
                                                                         BClass::NAVBAR_LINK)),
                                                       Attribute("href",
                                                                 "#portfolio"),
                                                       Attribute("TEXT", "О нас"),
                                               }));

    return navBar;
}

View* createDecorate(){

    View *decorate = new View("Dec0", Type::DIV, BClass::DECORATION_DCDL);
    decorate->append(*new View("Dec1", Type::DIV, BClass::DECORATION_DCL));
    decorate->append(*new View("Dec2", Type::DIV, BClass::DECORATION_DCI));
    decorate->append(*new View("Dec3", Type::DIV, BClass::DECORATION_DCL));

    return decorate;
}

View* createHead(std::string name){
    View* head = new View("Head", Type::HEADER, BClass::MASTHEAD_PRIMARY_CENTER);

    head->append(*new View("FlexColumn", Type::DIV, BClass::FLEX_COLUMN));
    head->appendInSubview("FlexColumn", *new ImageView("Avatar", Type::IMG,
                                                       BClass::MASTHEAD_AVATAR,
                                                       "https://www.pinclipart.com/picdir/big/133-1331433_free-user-avatar-icons-happy-flat-design-png.png"));
    head->appendInSubview("FlexColumn", *new TextView("HeadingText", Type::H1,
                                                      BClass::MASTHEAD_HEADING,
                                                      name));

    return head;
}

View* createBar(std::string name){
    View* head = new View("Head", Type::HEADER, BClass::MASTHEAD_PRIMARY_CENTER);
    head->append(*new View("FlexColumn", Type::DIV, BClass::FLEX_COLUMN));
    head->appendInSubview("FlexColumn", *new TextView("HeadingText", Type::H1,
                                                      BClass::MASTHEAD_HEADING,
                                                      name));

    return head;
}

TableView* createUserTable(std::vector<UserData *> userData){

    std::vector<PersonView *> persons;
    int i = 0;
    for (auto &u : userData) {
        persons.push_back(new PersonView(*u, i++));
    }

    int rowsCount = 0;
    int cellsCount = 0;
    organizeCells(Organize::ONE_LINE_HORIZONTAL, rowsCount, cellsCount,
                  userData.size());

    TableView *tableView = new TableView("Table", rowsCount, cellsCount);
    int r = 0;
    int c = 0;
    tableView->appendCell(
            std::make_shared<CellView>(*new CellView(c, 4)));
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
    return tableView;
}

TableView* createUserTable(std::vector<UserData *> userData, Organize organize){

    std::vector<PersonView *> persons;
    int i = 0;
    for (auto &u : userData) {
        persons.push_back(new PersonView(*u, i++));
    }

    int rowsCount = 0;
    int cellsCount = 0;
    organizeCells(organize, rowsCount, cellsCount,
                  userData.size());
    int num = 0;
    for(int i = 2; i <= userData.size();i+=2){
        num+=1;
    }

    switch(organize){
        case Organize::RECT_HORIZONTAL:
            rowsCount= userData.size()/num;
            cellsCount = userData.size()/rowsCount;
            rowsCount+=2;
            break;
    }

    TableView *tableView = new TableView("Table", rowsCount, cellsCount);
    int r = 0;
    int c = 0;
    tableView->appendCell(
            std::make_shared<CellView>(*new CellView(c, 4)));
    for (auto &p: persons) {
        tableView->appendRowInCell(c, std::make_shared<RowView>(
                *new RowView(r, *p)));
        r++;
        if (r >= rowsCount) {
            r = 0;
            c++;
            tableView->appendCell(
                    std::make_shared<CellView>(*new CellView(c, rowsCount)));
        }
    }
    return tableView;
}


View* createDevSection(std::vector<UserData *> userData, std::string title){
    View* devSection = new View("SectionDevelopers", Type::SECTION,
                                BClass::SECTION_PORTFOLIO, "portfolio");



    devSection->append(*new View("DevelopersContainer", Type::DIV,BClass::CONTAINER));

    devSection->append(*new TextView("DevsText", Type::H2,BClass::SECTION_HEADING, title));


    devSection->appendInSubview("DevelopersContainer", *createUserTable(userData));

    return devSection;

}

View* createUserCard(UserData *userData){
    std::string title = userData->firstName + " " + userData->secondName;
    View* devSection = new View("SectionDevelopers", Type::SECTION,
                                BClass::SECTION_PORTFOLIO, "portfolio");


    devSection->append(*new View("FC",Type::DIV,BClass::CONTAINER));

    devSection->appendInSubview("FC",*new View("DevelopersContainer", Type::DIV,BClass::CONTAINER));

    devSection->appendInSubview("DevelopersContainer", *new View("CenterUser",Type::DIV,BClass::FLEX_COLUMN));
    devSection->appendInSubview("CenterUser",*new PersonView(*userData, 0));

    devSection->appendInSubview("FC",*new TextView("DevsText", Type::H2,BClass::SECTION_HEADING,title));
    return devSection;

}

View* createFileForm(std::string link){
    View* sectionFile = new View("SectionFile", Type::SECTION, BClass::SECTION_FILE,"about");

    sectionFile->append( *new View("ContainerFile", Type::DIV,BClass::CONTAINER));

    const std::string fileText = "Выберите файл";
    sectionFile->appendInSubview("ContainerFile", *new TextView("UploadFile", Type::H2,BClass::SECTION_FILE_HEADING, fileText));


    sectionFile->appendInSubview( "ContainerFile", *new View("ContainerCenter", Type::DIV,BClass::FLEX_COLUMN));

    sectionFile->appendInSubview("ContainerCenter", *new FormView("fileForm", link,
                                                               "post", "multipart/form-data"));

    sectionFile->appendInSubview("fileForm", *new SecondaryView("FileInput", Type::INPUT,
                                                                std::vector<Attribute>{
                                                                        Attribute("type",
                                                                                  "text"),
                                                                        Attribute("id",
                                                                                  "file_uploads"),
                                                                        Attribute("name",
                                                                                  "file_uploads")
                                                                }));
    sectionFile->appendInSubview("fileForm",
                                 *new SecondaryView("FileButtonInput", Type::BUTTON,
                                                    std::vector<Attribute>{
                                                            Attribute("TEXT", "Загрузить"),
                                                    }));
    return sectionFile;
}


View* createContactSection(){
    View* contactInfo = new View("SectionContact", Type::SECTION, BClass::PAGE_SECTION,
                                 "contact");
    contactInfo->append(
            *new View("ContactContainer", Type::DIV,
                      BClass::CONTAINER));
    contactInfo->append( *new View("FooterText", Type::FOOTER,
                                   BClass::FOOTER_TEXT));
    contactInfo->appendInSubview("FooterText", *new TextView("ContactText0", Type::H4,
                                                             BClass::MB4_UPCASE,
                                                             "Мы тута"));
    contactInfo->appendInSubview("FooterText",
                                 *new TextView("ContactFace", Type::P, BClass::MB0_LEAD,
                                               "МГТУ им. Н.Э. Баумана  ГЗ ауд.395"));
    return contactInfo;
}


#endif //CPPROJECT_SAMPLEVIEWS_H
