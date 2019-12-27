//
// Created by Сергей Петренко on 2019-12-05.
//

#ifndef CPPROJECT_PAGEDATA_H
#define CPPROJECT_PAGEDATA_H

#include<vector>
#include <StaticGeneration/Views/UserData/UserData.h>

enum class PageType : uint8_t {
    ONE_USER_PAGE,
    TABLE_OF_USERS,
    START_PAGE,

};
enum class Organize : uint8_t {
    ONE_LINE_VERTICAL,
    ONE_LINE_HORIZONTAL,
    RECT_HORIZONTAL,
    RECT_VERTICAL

};

class PageData {
public:

    std::vector<UserData *> userData;

    PageData(std::vector<UserData *> u, PageType t, Organize o);

    void setOrganizeType(Organize o);

    void setPageType(PageType o);

    PageType getpageType() {
        return type;
    }

    Organize getPageOrganizeType() {
        return organize;
    }

private:
    Organize organize;
    PageType type;
};


#endif //CPPROJECT_PAGEDATA_H
