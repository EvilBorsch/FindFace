//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_TEXTVIEW_H
#define CPPROJECT_TEXTVIEW_H

#include <Container/ContainerView.h>

class TextView : public ContainerView {
private:
    std::string text;

public:
    bool append(ContainerView &mView) override;

    bool
    appendInSubview(std::string subviewName, ContainerView &mView) override;

    bool removeSubview(std::string subviewName) override;

    void destroy() override;

    TextView(std::string n, Type t, BClass c, std::string txt);

    TextView(std::string n, Type t, std::string txt);

    ~TextView();

    void setText(std::string mText);

    std::string getText();

    std::string toStringOpen(int depth) override;

    std::string toStringClose(int depth) override;

    std::string toString(int depth) override;

};


#endif //CPPROJECT_TEXTVIEW_H
