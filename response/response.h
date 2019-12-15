#include <boost/property_tree/ptree.hpp>
#include "url/url.h"
#include <boost/property_tree/json_parser.hpp>

class response {
private:
    boost::property_tree::ptree pt;
public:

    void parse(const std::string &st);

    explicit response(const std::string &st);

    boost::property_tree::ptree getData();


};
