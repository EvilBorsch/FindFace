//
// Created by Сергей Петренко on 2019-12-04.
//

#ifndef CPPROJECT_SECONDARYVIEW_H
#define CPPROJECT_SECONDARYVIEW_H
#include "View/View.h"
#include "Container/ContainerView.h"
class Attribute{
public:
    std::string key;
    std::string value;
    Attribute(std::string k, std::string v){
        key = k;
        value = v;
    }
};
class SecondaryView: public ContainerView   {
public:
    std::vector<Attribute> attributes;
    SecondaryView(std::string name, Type t, std::vector<Attribute> attr);

    std::string toStringOpen(int depth = 0) override;

    std::string toStringClose(int depth = 0) override;

    std::string toString(int depth = 0) override;


    bool appendInSubview(std::string subviewName, ContainerView& mView) override;

    void append(ContainerView &mView) override;

    void destroy() override;

    void removeSubview(std::string subviewName) override;

};


#endif //CPPROJECT_SECONDARYVIEW_H
