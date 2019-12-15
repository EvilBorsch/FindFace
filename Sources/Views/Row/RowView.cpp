//
// Created by Сергей Петренко on 2019-11-16.
//

#include "RowView.h"


RowView::RowView(int indx) {
    type = enumToString(Type::ROW);
    scope = "scope";
    index = indx;
}

RowView::RowView(int indx, ContainerView &containerView) {
    type = enumToString(Type::ROW);
    scope = "scope";
    index = indx;
    append(containerView);
}

RowView::RowView(ContainerView &containerView) {
    type = enumToString(Type::ROW);
    scope = "scope";
    append(containerView);
}

void RowView::setIndex(int indx) {
    index = indx;
}

RowView::~RowView() {

}

