//
// Created by Сергей Петренко on 2019-12-21.
//

#include "Serializator.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

std::string Serializator::userToJson(UserData *userData) {
    ptree pt;
        pt.put ("slug", userData->slug);
        pt.put ("fname", userData->firstName);
        pt.put ("sname", userData->secondName);
        pt.put ("age", userData->age);
        pt.put ("url", userData->imageUrl);
    std::ostringstream buf;
    write_json (buf, pt, false);
    std::string json = buf.str();
    return json;

}

std::string Serializator::usersToJson(std::vector<UserData *> userData) {
    ptree mainPt;
    for(auto& user: userData){
        ptree chlildPt;
        chlildPt.put ("fname", user->firstName);
        chlildPt.put ("sname", user->secondName);
        chlildPt.put ("age", user->age);
        chlildPt.put ("url", user->imageUrl);
        mainPt.add_child(user->slug, chlildPt);
    }
    std::ostringstream buf;
    write_json (buf, mainPt, false);
    std::string json = buf.str(); // {"foo":"bar"}
    return json;
}
