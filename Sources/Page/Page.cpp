//
// Created by Сергей Петренко on 2019-11-07.
//

#include "Page.h"

//Page::Page(){
//    view = new View("main", Type::DIV);
//    makeTemplate();
//}
//
//void Page::makeTemplate(){
//
//    view->append(*new View("html",Type::HTML));
//    view->appendInSubview("html",
//                          *new SecondaryView("meta",
//                                             Type::META,
//                                             std::vector<Attribute>{
//                                                     Attribute("charset","UTF-8")
//                                             }));
//    view->appendInSubview("html",(*new TextView("title",Type::TITLE,"FINDFACE")));
//    view->appendInSubview("html",
//                          *new SecondaryView("attributes",
//                                             Type::LINK, std::vector<Attribute>{
//                                          Attribute("rel","stylesheet"),
//                                          Attribute("href","https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"),
//                                          Attribute("integrity","sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T"),
//                                          Attribute("crossorigin","anonymous")
//                                  }));
//
//    view->appendInSubview("html",* new View("body",Type::BODY));
//}
//
//void Page::appendInBody(ContainerView& containerView){
//    view->appendInSubview("body", containerView);
//}
//
//std::string Page::toString(){
//    std::string res;
//    res += "<!DOCTYPE html>\n";
//    res+=view->toString(0);
//    return res;
//}