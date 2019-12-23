//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_ROWVIEW_H
#define CPPROJECT_ROWVIEW_H

#include <Views/View/View.h>

class RowView : public View {
public:
    int index{};
    std::string scope;

    explicit RowView(int indx);

    RowView(int indx, ContainerView &containerView);

    ~RowView();

    explicit RowView(ContainerView &containerView);

    void setIndex(int indx);
};


#endif //CPPROJECT_ROWVIEW_H
