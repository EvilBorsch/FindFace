//
// Created by Сергей Петренко on 2019-12-02.
//

#include <StaticGeneration/Views/SecondaryView/SecondaryView.h>
#include "PersonView.h"

PersonView::PersonView(UserData userData,int id){
type = enumToString(Type::DIV);
_class = enumToString(BClass::CARD_DECK);
name = "PersonView";
    userImage = new ImageView("userImage",
                              Type::IMG,
                              BClass::MB4,
                              userData.imageUrl,
                              imageHeight,
                              imageWidth);

//username = new SecondaryView("slug",Type::A,std::vector<Attribute>{
//    Attribute("href","/userpage/"+std::to_string(id)),
//    Attribute("class","my-0 font-weight-normal"),
//    Attribute("TEXT",userData.slug )
//});
    username = new TextView("slug",Type::H4,BClass::TEXT_NORMAL,userData.slug);


infoTable = new TableView("table",
                          rowsCount,
                          cellCount);


infoTable->appendCells(std::vector<std::shared_ptr<CellView>> {

        std::make_shared<CellView>(*new CellView(0,std::vector<std::shared_ptr<RowView>>{
                std::make_shared<RowView>(*new RowView(0,
                             *new TextView(
                                     "fNameView",
                                     Type::H4,
                                     BClass::TEXT_NORMAL,
                                     userData.firstName))
                )})),

        std::make_shared<CellView>(*new CellView(1,std::vector<std::shared_ptr<RowView>>{
                std::make_shared<RowView>(*new RowView(0,
                                                       *new TextView(
                                                               "sNameView",
                                                               Type::H4,
                                                               BClass::TEXT_NORMAL,
                                                               userData.secondName))
                )})),

        std::make_shared<CellView>(*new CellView(2,std::vector<std::shared_ptr<RowView>>{
                std::make_shared<RowView>(*new RowView(0,
                                                       *new TextView(
                                                               "ageView",
                                                               Type::H4,
                                                               BClass::TEXT_NORMAL,
                                                               std::to_string(userData.age))))})),
});

makeTemplate();
}


void PersonView::makeTemplate(){

    append(*new View("Frame",
                     Type::DIV, BClass::CARD_DECK));
    appendInSubview("Frame",
                    *new View("Shadow",
                              Type::DIV,
                              BClass::CARD_MB4_SHADOW));

    appendInSubview("Shadow",
                    *new View("CardHeader",
                              Type::DIV,
                              BClass::CARD_HEADER));

    appendInSubview("CardHeader",*username);

    appendInSubview("Shadow",
                    *new View("CardBody",
                              Type::DIV,
                              BClass::CARD_BODY));

    appendInSubview("CardBody", *userImage);
    appendInSubview("CardBody", *infoTable);

}

PersonView::~PersonView() {

}
