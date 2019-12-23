//
// Created by Сергей Петренко on 2019-11-07.
//

#ifndef CPPROJECT_CONTAINERVIEW_H
#define CPPROJECT_CONTAINERVIEW_H

#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <UserData/UserData.h>
#include "HtmlAttributes.h"


class ContainerView {
protected:
    std::string name;
    std::string type;
    std::string _class;
    std::string id;
    std::string action;

public:
    std::vector<std::reference_wrapper<ContainerView>> subviews;


    virtual std::string toString(int depth) = 0;

    virtual std::string toStringOpen(int depth) = 0;

    virtual std::string toStringClose(int depth) = 0;

    virtual bool append(ContainerView &mView) = 0;

    virtual bool
    appendInSubview(std::string subviewName, ContainerView &mView) = 0;

    virtual bool removeSubview(std::string subviewName) = 0;

    virtual void destroy() = 0;

    std::string getName();

    std::string getType();

    std::string getClass();

    std::string getId();

    std::string getAction();

    ContainerView() = default;

    ContainerView(std::string containerName, Type containerType, std::string containerClass);
    ContainerView(std::string containerName, Type containerType, std::string containerClass, std::string containerId);


};


#endif //CPPROJECT_CONTAINERVIEW_H
