//
// Created by Сергей Петренко on 2019-12-02.
//

#ifndef CPPROJECT_CELLVIEW_H
#define CPPROJECT_CELLVIEW_H

#include "Container/ContainerView.h"
#include "Row/RowView.h"

class CellView: public ContainerView  {
public:
    int rowsCount;;
    int index;
    std::vector<RowView> rows;

    CellView(int mRows);
    CellView(int indx,int mRows);
    CellView(int indx, std::vector<RowView> rows);
    void setIndex(int indx);
    void append(ContainerView &mView);
    void appendRow(RowView &mView);
    void appendRows(std::vector<RowView> mRows);
    void removeSubview(std::string subviewName);
    bool appendInSubview(std::string subviewName, ContainerView& mView);
    void destroy();

    std::string toString(int depth);
    std::string toStringOpen(int depth);
    std::string toStringClose(int depth);



};


#endif //CPPROJECT_CELLVIEW_H
