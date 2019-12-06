//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_TEXTVIEW_H
#define CPPROJECT_TEXTVIEW_H

#include "Container/ContainerView.h"

class TextView: public ContainerView{
private:
    std::string text;

public:
    void append(ContainerView &mView);
    bool appendInSubview(std::string subviewName, ContainerView& mView);
    void removeSubview(std::string subviewName);
    void destroy();
    TextView(std::string n, Type t, BClass c, std::string txt);
    TextView(std::string n, Type t, std::string txt);
    void setText(std::string mText);
    std::string getText();
    std::string toStringOpen(int depth = 0) override;
    std::string toStringClose(int depth = 0) override;
    std::string toString(int depth = 0) override;

};


#endif //CPPROJECT_TEXTVIEW_H
