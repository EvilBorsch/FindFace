//
// Created by Сергей Петренко on 2019-11-07.
//

#ifndef CPPROJECT_PAGE_H
#define CPPROJECT_PAGE_H

#include <Views/View/View.h>
#include <Views/SecondaryView/SecondaryView.h>
#include <Views/TextView/TextView.h>
#include <string.h>

class Page {
public:
    View *view;

    Page() {
        view = new View("main", Type::DIV);
        makeTemplate();
    }

    void makeTemplate() {

        view->append(*new View("html", Type::HTML));

        view->append(*new View("head", Type::HEAD));

        view->appendInSubview("head",*new SecondaryView("metaUTF",Type::META,std::vector<Attribute>{Attribute("charset","UTF-8")}));
        view->appendInSubview("head",*new SecondaryView("metaVP",Type::META,std::vector<Attribute>{
            Attribute("name","viewport"),
            Attribute("content","width=device-width, initial-scale=1, shrink-to-fit=no"),
            Attribute("name","description"),
            Attribute("name","author")
        }));

        view->appendInSubview("head", (*new TextView("title", Type::TITLE,
                                                     "НАЙТИЛИЦО")));
        view->appendInSubview("head",
                              *new SecondaryView("attributesForCSS0",Type::LINK,std::vector<Attribute>{
                                  Attribute("href","vendor/fontawesome-free/css/all.min.css"),
                                  Attribute("rel","stylesheet"),
                                  Attribute("type","text/css")
                                                 }));
        view->appendInSubview("head",
                              *new SecondaryView("attributesForFonts0",Type::LINK,std::vector<Attribute>{
                                      Attribute("href","https://fonts.googleapis.com/css?family=Montserrat:400,700"),
                                      Attribute("rel","stylesheet"),
                                      Attribute("type","text/css")
                              }));
        view->appendInSubview("head",
                              *new SecondaryView("attributesForFonts1",Type::LINK,std::vector<Attribute>{
                                      Attribute("href","https://fonts.googleapis.com/css?family=Lato:400,700,400italic,700italic"),
                                      Attribute("rel","stylesheet"),
                                      Attribute("type","text/css")
                              }));
        view->appendInSubview("head",
                              *new SecondaryView("attributesForTheme",Type::LINK,std::vector<Attribute>{
                                      Attribute("href","css/freelancer.min.css"),
                                      Attribute("rel","stylesheet")
                              }));

        view->appendInSubview("html", *new View("body", Type::BODY));
    }

    void appendInBody(ContainerView &containerView) {
        view->appendInSubview("body", containerView);
    }

    std::string toString() {
        std::string res;
        res += "<!DOCTYPE html>\n";
        res += view->toString(0);
        return res;
    }
};


#endif //CPPROJECT_PAGE_H
