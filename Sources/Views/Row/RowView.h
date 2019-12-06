//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_ROWVIEW_H
#define CPPROJECT_ROWVIEW_H


#include "Container/ContainerView.h"

class RowView: public ContainerView{
public:
    int index;
    std::string scope;
    RowView(int indx);
    RowView(int indx, ContainerView& containerView);
    RowView( ContainerView& containerView);
    void setIndex(int indx);
    std::string toString(int depth = 0) override;
    std::string toStringOpen(int depth);
    std::string toStringClose(int depth);
    void append(ContainerView &mView);
    bool appendInSubview(std::string subviewName, ContainerView& mView);
    void removeSubview(std::string subviewName);
    void destroy();
};



#endif //CPPROJECT_ROWVIEW_H
