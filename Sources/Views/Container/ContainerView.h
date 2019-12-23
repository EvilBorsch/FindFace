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



enum class Type : uint8_t {
    HTML,
    BODY,
    IMG,
    DIV,
    H4,
    H2,
    H1,
    A,
    P,
    UL,
    LI,
    TABLE,
    ROW,
    CELL,
    TITLE,
    META,
    LINK,
    HEAD,
    SCRIPT,
    NAV,
    HEADER,
    SECTION,
    I,
    FOOTER,
    SPAN,
    INPUT,
    LABEL,
    FORM,
    BUTTON




};

inline const char *enumToString(Type t) {
    switch (t) {
        case Type::HTML :
            return "html";

        case Type::BODY :
            return "body";

        case Type::A :
            return "a";

        case Type::P:
            return "p";

        case Type::IMG :
            return "img";

        case Type::DIV :
            return "div";

        case Type::H1 :
            return "h1";

        case Type::H2 :
            return "h2";

        case Type::H4 :
            return "h4";

        case Type::UL :
            return "ul";

        case Type::LI :
            return "li";

        case Type::TABLE :
            return "table";

        case Type::ROW :
            return "th";

        case Type::CELL :
            return "tr";

        case Type::TITLE :
            return "title";

        case Type::LINK :
            return "link";

        case Type::META :
            return "meta";

        case Type::HEAD :
            return "head";

        case Type::SCRIPT :
            return "script";

        case Type::NAV :
            return "nav";

        case Type::HEADER :
            return "header";

        case Type::SECTION :
            return "section";

        case Type::FOOTER :
            return "footer";

        case Type::I :
            return "i";

        case Type::SPAN :
            return "span";

        case Type::INPUT :
            return "input";

        case Type::LABEL :
            return "label";

        case Type::FORM :
            return "form";

        case Type::BUTTON :
            return "button";

        default:
            return "[Unknown type]";
    }
}

enum class BClass : uint8_t {
    CARD_DECK,
    CARD_MB4_SHADOW,
    CARD_BODY,
    CARD_HEADER,
    TEXT_NORMAL,
    MB4,
    MB4_UC,
    MB4_UPCASE,
    LIST_ITEM,
    TABLE,
    MAIN_NAVBAR,
    NAVBAR_SCROLL_TRIGGER,
    NAVBAR_COLLPAPSE,
    NAVBAR_ML,
    NAVBAR_ITEM,
    NAVBAR_LINK,
    CONTAINER,
    MASTHEAD_PRIMARY_CENTER,
    FLEX_COLUMN,
    MASTHEAD_AVATAR,
    MASTHEAD_HEADING,
    DECORATION_DCDL,
    DECORATION_DCL,
    DECORATION_DCI,
    DECORATION_FFS,
    SECTION_PORTFOLIO,
    SECTION_HEADING,
    SECTION_FILE,
    SECTION_FILE_HEADING,
    INGR,
    INGR_PR,
    INGR_TEXT,
    F_CUSTOM,
    F_CUSTOM_INPUT,
    F_CUSTOM_LABEL,
    PAGE_SECTION,
    FOOTER_TEXT,
    MB0_LEAD








};

inline const char *enumToString(BClass b) {
    switch (b) {
        case BClass::CARD_DECK :
            return "card-deck mb-3 text-center";

        case BClass::CARD_BODY :
            return "card-body";

        case BClass::CARD_HEADER :
            return "card-header";

        case BClass::CARD_MB4_SHADOW :
            return "card mb-4 shadow-sm";

        case BClass::TEXT_NORMAL :
            return "my-0 font-weight-normal";

        case BClass::MB4 :
            return "mb-4";

        case BClass::MB4_UC:
            return "text-uppercase mb-4";

        case BClass::LIST_ITEM:
            return "list-group-item";

        case BClass::TABLE :
            return "table";

        case BClass::MAIN_NAVBAR:
            return"navbar navbar-expand-lg bg-secondary text-uppercase fixed-top";

        case BClass ::NAVBAR_SCROLL_TRIGGER:
            return"navbar-brand js-scroll-trigger";

        case BClass::NAVBAR_COLLPAPSE:
            return "collapse navbar-collapse";

        case BClass::NAVBAR_ML:
            return "navbar-nav ml-auto";

        case BClass::NAVBAR_ITEM:
            return "nav-item mx-0 mx-lg-1";

        case BClass::NAVBAR_LINK:
            return "nav-link py-3 px-0 px-lg-3 rounded js-scroll-trigger";

        case BClass::CONTAINER:
            return "container";

        case BClass::MASTHEAD_PRIMARY_CENTER:
            return "masthead bg-primary text-white text-center";

        case BClass::FLEX_COLUMN:
            return "container d-flex align-items-center flex-column";

        case BClass::MASTHEAD_AVATAR :
            return "masthead-avatar mb-5";

        case BClass::MASTHEAD_HEADING :
            return "masthead-heading text-uppercase mb-0";

        case BClass::DECORATION_DCDL :
            return "divider-custom divider-light";

        case BClass::DECORATION_DCL :
            return "divider-custom-line";

        case BClass::DECORATION_DCI :
            return "divider-custom-icon";

        case BClass::DECORATION_FFS :
            return "fas fa-star";

        case BClass::SECTION_PORTFOLIO:
            return "page-section portfolio";

        case BClass::SECTION_FILE:
            return "page-section bg-primary text-white mb-0";

        case BClass::SECTION_HEADING:
            return "page-section-heading text-center text-uppercase text-secondary mb-0";

        case BClass::SECTION_FILE_HEADING:
            return "page-section-heading text-center text-uppercase text-white";

        case BClass ::INGR:
            return "input-group";

        case BClass ::INGR_PR:
            return "input-group";

        case BClass ::INGR_TEXT:
            return "input-group";

        case BClass ::F_CUSTOM:
            return "custom-file";

        case BClass ::F_CUSTOM_INPUT:
            return "custom-file";

        case BClass ::F_CUSTOM_LABEL:
            return " custom-file-label";

        case BClass::PAGE_SECTION:
            return "page-section";

        case BClass::FOOTER_TEXT:
            return " footer text-center";

        case BClass::MB4_UPCASE:
            return "text-uppercase mb-4";

        case BClass::MB0_LEAD:
            return "lead mb-0";

        default:
            return "[Unknown class]";
    }
}

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

    ContainerView(std::string n, Type t, std::string c);
    ContainerView(std::string n, Type t, std::string c, std::string id);


};


#endif //CPPROJECT_CONTAINERVIEW_H
