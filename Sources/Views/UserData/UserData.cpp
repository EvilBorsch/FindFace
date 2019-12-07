//
// Created by Сергей Петренко on 2019-12-05.
//

#include "UserData.h"
UserData::UserData(std::string slg, std::string fn, std::string sn, std::string img, int a){
    slug = slg;
    firstName = fn;
    secondName = sn;
    age = a;
    imageUrl = img;
}