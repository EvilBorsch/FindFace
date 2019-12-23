//
// Created by Сергей Петренко on 2019-12-17.
//

#ifndef CPPROJECT_FORMVIEW_H
#define CPPROJECT_FORMVIEW_H


#include <StaticGeneration/Views/Container/ContainerView.h>

class FormView : public ContainerView{
    std::string action;
    std::string method;
    std::string enctype;

public:

    FormView(std::string formName, std::string formAction, std::string formMethod, std::string formEnctype){
        name = formName;
        action = formAction;
        method = formMethod;
        enctype = formEnctype;
    }
    std::string toStringOpen(int depth = 0) override;

    std::string toStringClose(int depth = 0) override;

    std::string toString(int depth = 0) override;

    std::string getMethod(){
        return method;
    }
    std::string getEnctype(){
        return enctype;
    }
    std::string getAction(){
        return action;
    }


    bool
    appendInSubview(std::string subviewName, ContainerView &mView) override;

    bool append(ContainerView &mView) override;

    bool removeSubview(std::string subviewName) override;

    void destroy() override;


};


#endif //CPPROJECT_FORMVIEW_H
