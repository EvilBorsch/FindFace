//
// Created by Сергей Петренко on 2019-11-07.
//

#ifndef CPPROJECT_VIEW_H
#define CPPROJECT_VIEW_H
#include "Container/ContainerView.h"



class View: public ContainerView{
public:
    View()= default;
    View(std::string n, Type t, BClass c);
    View(std::string n, Type t);

    std::string toStringOpen(int depth = 0) override;

    std::string toStringClose(int depth = 0) override;

    std::string toString(int depth = 0) override;


    bool appendInSubview(std::string subviewName, ContainerView& mView) override;

    void append(ContainerView &mView) override;

    void removeSubview(std::string subviewName) override;
    void destroy () override;

};

#endif //CPPROJECT_VIEW_H
