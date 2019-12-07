#include "response.h"

boost::property_tree::ptree response::getData() {
    return pt;
}

response::response(const std::string &st) {
    parse(st);
}

void response::parse(const std::string &st) {
    std::stringstream ss(st);
    boost::property_tree::read_json(ss, pt);
}

