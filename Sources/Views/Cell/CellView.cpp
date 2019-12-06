//
// Created by Сергей Петренко on 2019-12-02.
//

#include "CellView.h"

CellView::CellView(int mRows){
    type = enumToString(Type::CELL);
    rowsCount = mRows;
}
CellView::CellView(int indx,int mRows){
    type = enumToString(Type::CELL);
    rowsCount = mRows;
    index = indx;

}

CellView::CellView(int indx, std::vector<RowView> rows){
    type = enumToString(Type::CELL);
    rowsCount = rows.size();
    index = indx;
    appendRows(rows);
}

void CellView::setIndex(int indx){
    index = indx;
}

std::string CellView::toString(int depth){
    std::string res;
    if(depth == 0){
        res += "<"+type +">\n\n";
        depth++;
    }
    if(!rows.empty()) {
        for (RowView &v: rows) {
            res += v.toStringOpen(depth);
            depth++;
            if (!v.subviews.empty()) {
                res += v.toString(depth);
            }
            res+=v.toStringClose(--depth);
        }
    }
    if(--depth == 0){
        res += " </"+type+">\n\n";
    }
    return res;

}

std::string CellView::toStringOpen(int depth){
    std::string res;
    for(int i=0;i<3*depth;i++){
        res+=" ";
    }
    res += "<"+type +"> \n\n";
    return res;
}
std::string CellView::toStringClose(int depth){
    std::string res;
    for(int i=0;i<3*depth;i++){
        res+=" ";
    }
    res += "</"+type+">\n\n";
    return res;
}


void CellView::append(ContainerView &mView){
    subviews.push_back(mView);
}
void CellView::appendRow(RowView &mView){
    rows.push_back(mView);
}

void CellView::appendRows(std::vector<RowView> mRows){
    if(rows.size() + mRows.size() <= rowsCount) {
        for(RowView& rowView : mRows){
            rows.push_back(rowView);
            rowView.setIndex(rows.size());
        }
    }
}

bool CellView::appendInSubview(std::string subviewName, ContainerView& mView){

}
void  CellView::removeSubview(std::string subviewName){

}
void CellView::destroy(){

}