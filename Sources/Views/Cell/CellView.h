//
// Created by Сергей Петренко on 2019-12-02.
//

#ifndef CPPROJECT_CELLVIEW_H
#define CPPROJECT_CELLVIEW_H

#include "Container/ContainerView.h"
#include "Row/RowView.h"

class CellView : public ContainerView {
public:
    int rowsCount;;
    int index;
    std::vector<std::shared_ptr<RowView>> rows;

    explicit CellView(int mRows);

    CellView(int indx, int mRows);

    CellView(int indx, std::vector<std::shared_ptr<RowView>> rows);

    ~CellView();

    void setIndex(int indx);

    bool append(ContainerView &mView) override;

    void appendRow(std::shared_ptr<RowView> &mView);

    void appendRows(std::vector<std::shared_ptr<RowView>> mRows);

    bool removeSubview(std::string subviewName) override;

    bool
    appendInSubview(std::string subviewName, ContainerView &mView) override;

    void destroy() override;

    std::string toString(int depth) override;

    std::string toStringOpen(int depth) override;

    std::string toStringClose(int depth) override;


};


#endif //CPPROJECT_CELLVIEW_H
