//
// Created by Сергей Петренко on 2019-12-21.
//

#ifndef CPPROJECT_SERIALIZATOR_H
#define CPPROJECT_SERIALIZATOR_H


#include "UserData/UserData.h"

class Serializator {
public:
    std::string userToJson(UserData *userData);
    std::string usersToJson(std::vector<UserData*> userData);
};


#endif //CPPROJECT_SERIALIZATOR_H
