//
// Created by Сергей Петренко on 2019-11-07.
//

#include "Page.h"

Page::Page() {
    view = new View("main", Type::DIV);
    makeTemplate();
}

void Page::makeTemplate() {

    view->append(*new View("html", Type::HTML));

    view->appendInSubview("html", *new View("head", Type::HEAD));

    view->appendInSubview("head",*new SecondaryView("metaUTF",Type::META,std::vector<Attribute>{Attribute("charset","UTF-8")}));
    view->appendInSubview("head",*new SecondaryView("metaVP",Type::META, std::vector<Attribute>{
            Attribute("name","viewport")
    }));
    view->appendInSubview("head",*new SecondaryView("metaVP",Type::META,std::vector<Attribute>{
            Attribute("content","width=device-width, initial-scale=1, shrink-to-fit=no"),
    }));
    view->appendInSubview("head",*new SecondaryView("metaVP",Type::META,std::vector<Attribute>{
            Attribute("name","description"),
    }));
    view->appendInSubview("head",*new SecondaryView("metaVP",Type::META,std::vector<Attribute>{
            Attribute("name","author")
    }));

    view->appendInSubview("head", (*new TextView("title", Type::TITLE,
                                                 "НАЙТИЛИЦО")));

    view->appendInSubview("head",
                          *new SecondaryView("attributesForCSS0",Type::LINK,std::vector<Attribute>{
                                  Attribute("rel","stylesheet"),
                                  Attribute("href","https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"),
                                  Attribute("integrity","sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T"),
                                  Attribute("crossorigin", "anonymous")
                          }));

    view->appendInSubview("head",
                          *new SecondaryView("attributesForCSS0",Type::LINK,std::vector<Attribute>{
                                  Attribute("href","/Static/vendor/fontawesome-free/css/all.min.css"),
                                  Attribute("rel","stylesheet"),
                                  Attribute("type","/text/css")
                          }));
    view->appendInSubview("head",
                          *new SecondaryView("attributesForFonts0",Type::LINK,std::vector<Attribute>{
                                  Attribute("href","https://fonts.googleapis.com/css?family=Montserrat:400,700"),
                                  Attribute("rel","stylesheet"),
                                  Attribute("type","/text/css")
                          }));
    view->appendInSubview("head",
                          *new SecondaryView("attributesForFonts1",Type::LINK,std::vector<Attribute>{
                                  Attribute("href","https://fonts.googleapis.com/css?family=Lato:400,700,400italic,700italic"),
                                  Attribute("rel","stylesheet"),
                                  Attribute("type","/text/css")
                          }));
    view->appendInSubview("head",
                          *new SecondaryView("attributesForTheme",Type::LINK,std::vector<Attribute>{
                                  Attribute("href","https://cdnjs.cloudflare.com/ajax/libs/startbootstrap-freelancer/5.1.3/css/freelancer.min.css"),
                                  Attribute("rel","stylesheet")
                          }));


    view->appendInSubview("head",
                          *new SecondaryView("jsScripts0",Type::SCRIPT,std::vector<Attribute>{
                                  Attribute("src","https://cdnjs.cloudflare.com/ajax/libs/angular.js/1.3.14/angular.min.js"),
                          }));

    view->appendInSubview("html", *new View("body", Type::BODY));
}

void Page::appendInBody(ContainerView &containerView) {
    view->appendInSubview("body", containerView);
}

std::string Page::toString() {
    std::string res;
    res += "<!DOCTYPE html>\n";
    res += view->toString(0);
    return res;
}