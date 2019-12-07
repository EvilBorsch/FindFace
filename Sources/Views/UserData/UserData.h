//
// Created by Сергей Петренко on 2019-12-05.
//

#ifndef CPPROJECT_USERDATA_H
#define CPPROJECT_USERDATA_H

#include<string>

class UserData{
public:
    std::string slug;
    std::string firstName;
    std::string secondName;
    std::string imageUrl;
    int age;

    UserData(std::string slg, std::string fn, std::string sn, std::string img, int a);
};


#endif //CPPROJECT_USERDATA_H
