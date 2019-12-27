//
// Created by Сергей Петренко on 2019-11-07.
//

#ifndef CPPROJECT_PAGE_H
#define CPPROJECT_PAGE_H

#include <StaticGeneration/Views/View/View.h>
#include <StaticGeneration/Views/SecondaryView/SecondaryView.h>
#include <StaticGeneration/Views/TextView/TextView.h>
#include <string.h>

class Page {
public:
    View *view;

    Page();

    void makeTemplate();

    void appendInBody(ContainerView &containerView);

    std::string toString();
};


#endif //CPPROJECT_PAGE_H
