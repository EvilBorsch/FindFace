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

class TableView : public ContainerView {
private:
    int rowsCount;
    int cellsCount;
    std::string name;
    std::vector<std::shared_ptr<CellView>> cells;
public:


    TableView(std::string mName, int mRows, int mCells);

    ~TableView();

    std::string toString(int depth) override;

    std::string toStringOpen(int depth) override;

    std::string toStringClose(int depth) override;

    bool append(ContainerView &mView) override;

    void appendCell(std::shared_ptr<CellView> mView);

    void appendCells(std::vector<std::shared_ptr<CellView>> mViews);

    bool
    appendInSubview(std::string subviewName, ContainerView &mView) override;

    bool appendRowInCell(int cellIndex, std::shared_ptr<RowView> mView);

    bool appendRowsInCell(int cellIndex,
                          std::vector<std::shared_ptr<RowView>> mViews);

    bool removeSubview(std::string subviewName) override;

    void destroy() override;

};


#endif //CPPROJECT_TABLEVIEW_H
