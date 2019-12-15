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


enum class BClass : uint8_t {
    CARD_DECK,
    CARD_MB4_SHADOW,
    CARD_BODY,
    CARD_HEADER,
    TEXT_NORMAL,
    MB4,
    LIST_ITEM,
    TABLE,

};
enum class Type : uint8_t {
    HTML,
    BODY,
    IMG,
    DIV,
    H4,
    UL,
    LI,
    TABLE,
    ROW,
    CELL,
    TITLE,
    META,
    LINK,
    HREF,
    INTEGRITY,
    CROSSORIGIN,
    HEAD,
};

inline const char *enumToString(Type t) {
    switch (t) {
        case Type::HTML :
            return "html";

        case Type::BODY :
            return "body";
        case Type::IMG :
            return "img";

        case Type::DIV :
            return "div";

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

        default:
            return "[Unknown type]";
    }
}

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

        case BClass::LIST_ITEM:
            return "list-group-item";

        case BClass::TABLE :
            return "table";

        default:
            return "[Unknown class]";
    }
}

class ContainerView {
protected:
    std::string name;
    std::string type;
    std::string _class;

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

    ContainerView() = default;

    ContainerView(std::string n, Type t, std::string c);


};


#endif //CPPROJECT_CONTAINERVIEW_H
