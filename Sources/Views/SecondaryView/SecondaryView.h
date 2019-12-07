//
// Created by Сергей Петренко on 2019-12-04.
//

#ifndef CPPROJECT_SECONDARYVIEW_H
#define CPPROJECT_SECONDARYVIEW_H

#include "View/View.h"
#include <utility>
#include <Container/ContainerView.h>

class Attribute {
public:
    std::string key;
    std::string value;

    Attribute(std::string k, std::string v) {
        key = std::move(k);
        value = std::move(v);
    }
};

class SecondaryView : public ContainerView {
public:
    std::vector<Attribute> attributes;

    SecondaryView(std::string name, Type t, std::vector<Attribute> attr);

    ~SecondaryView();

    std::string toStringOpen(int depth) override;

    std::string toStringClose(int depth) override;

    std::string toString(int depth) override;


    bool
    appendInSubview(std::string subviewName, ContainerView &mView) override;

    bool append(ContainerView &mView) override;

    void destroy() override;

    bool removeSubview(std::string subviewName) override;

};


#endif //CPPROJECT_SECONDARYVIEW_H
