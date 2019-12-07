//
// Created by Сергей Петренко on 2019-11-16.
//

#include "TableView.h"

TableView::TableView(std::string mName, int mRows, int mCells) {
    type = enumToString(Type::TABLE);
    _class = enumToString(BClass::TABLE);
    name = mName;
    rowsCount = mRows;
    cellsCount = mCells;
    append(*new View("tablediv", Type::DIV, BClass::CARD_DECK));
}


std::string TableView::toString(int depth) {
    std::string res;
    if (depth == 0) {
        res += "<" + type + " class=\"" + _class + "\"> <tbody>\n\n";
        depth++;
    }
    if (!cells.empty()) {
        for (std::shared_ptr<CellView> v: cells) {
            res += v->toStringOpen(depth);
            depth++;
            if (!v->rows.empty()) {
                res += v->toString(depth);
            }
            res += v->toStringClose(--depth);
        }
    }
    if (--depth == 0) {
        res += "</tbody> </" + type + ">\n\n";
    }
    return res;

}

std::string TableView::toStringOpen(int depth) {
    std::string res;
    for (int i = 0; i < 3 * depth; i++) {
        res += " ";
    }
    res += "<" + type + " class=\"" + _class + "\"> <tbody>\n\n";
    return res;
}

std::string TableView::toStringClose(int depth) {
    std::string res;
    for (int i = 0; i < 3 * depth; i++) {
        res += " ";
    }
    res += "</tbody> </" + type + ">\n\n";
    return res;
}


bool TableView::append(ContainerView &mView) {
    subviews.emplace_back(mView);
}

void TableView::appendCell(std::shared_ptr<CellView> mView) {

    if (cells.size() < cellsCount) {

        cells.push_back(mView);
        mView->setIndex(cells.size());
    }
}

void TableView::appendCells(std::vector<std::shared_ptr<CellView>> mViews) {

    if (cells.size() + mViews.size() <= cellsCount) {
        for (std::shared_ptr<CellView> cellView : mViews) {
            cells.push_back(cellView);
            cellView->setIndex(cells.size());
        }
    }
}

bool TableView::appendInSubview(std::string subviewName, ContainerView &mView) {

}

bool TableView::appendRowInCell(int cellIndex, std::shared_ptr<RowView> mView) {
    if (cellIndex <= cellsCount && cells.size() + 1 <= cellsCount) {
        if (cells[cellIndex]->rows.size() + 1 <= rowsCount) {
            cells[cellIndex]->rows.emplace_back(mView);
            return true;
        }
    }
    return false;
}

bool TableView::appendRowsInCell(int cellIndex,
                                 std::vector<std::shared_ptr<RowView>> mViews) {
    if (cellIndex <= cellsCount && cells.size() < cellsCount) {
        if (cells[cellIndex]->rows.size() + mViews.size() < cellsCount) {
            for (std::shared_ptr<RowView> &rowView: mViews) {
                cells[cellIndex]->appendRow(rowView);
                rowView->setIndex(cells[cellIndex]->rows.size());
            }
        }
    }
    return false;
}

bool TableView::removeSubview(std::string subviewName) {

}

void TableView::destroy() {

}

TableView::~TableView() {

}
