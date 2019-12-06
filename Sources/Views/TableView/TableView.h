//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_TABLEVIEW_H
#define CPPROJECT_TABLEVIEW_H

#include <vector>
#include "Container/ContainerView.h"
#include "Row/RowView.h"
#include "Cell/CellView.h"
#include "View/View.h"

class TableView: public ContainerView{
public:
    int rowsCount;
    int cellsCount;
    std::string name;
    std::vector<CellView> cells;

    TableView(std::string mName,int mRows, int mCells);
    std::string toString(int depth);
    std::string toStringOpen(int depth);
    std::string toStringClose(int depth);
    void append(ContainerView &mView);
    void appendCell(CellView &mView);
    void appendCells(std::vector<CellView> mViews);
    bool appendInSubview(std::string subviewName, ContainerView& mView) override ;
    bool appendRowInCell(int cellIndex, RowView& mView);
    bool appendRowsInCell(int cellIndex, std::vector<RowView> mViews);
    void removeSubview(std::string subviewName) override;
    void destroy() override;

};


#endif //CPPROJECT_TABLEVIEW_H
