//
// Created by Сергей Петренко on 2019-11-16.
//

#include "PageGenerator.h"

void PageGenerator::organizeCells(Organize o, int& rows, int& cells, int count){
    switch(o){
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

Page* PageGenerator::generateTablePage(std::vector<UserData*> userData, Organize o){
    page =  new Page();
    std::vector<PersonView*> persons;
    for(auto &u : userData){
        persons.push_back(new PersonView(*u));
    }

    int rowsCount = 0;
    int cellsCount = 0;
    organizeCells(o,rowsCount,cellsCount,userData.size());

    View* view = new View("Main",Type::DIV,BClass::CARD_DECK);

    TableView* tableView = new TableView("Table",rowsCount,cellsCount);
    int r = 0;
    int c = 0;
    tableView->appendCell(std::make_shared<CellView>(*new CellView(c,rowsCount)));
    for(auto &p: persons){
        tableView->appendRowInCell(c,std::make_shared<RowView>(*new RowView(r, *p)));
        r++;
        if(r >= rowsCount){
            r = 0;
            tableView->appendCell(std::make_shared<CellView>(*new CellView(++c,rowsCount)));
        }
    }
    page->appendInBody(*tableView);
    return page;
}
Page* PageGenerator::generateStartPage(){

}

Page* PageGenerator::generateUserPage(UserData userData){
    Page *page =  new Page();
    page->appendInBody(*new TextView("test", Type::H4, BClass::TEXT_NORMAL, "hello world"));
    return page;
}

