#include <string>
#include <vector>
#pragma once

using std::string,std::vector;

class AbstractAPI{
public:
    virtual vector<string> get_photo_urls_by_id(const string& url)=0;
    virtual vector<string> get_friends_urls_by_id(const string& url)=0;
    virtual vector<string> get_group_participants(const string& url)=0;
    virtual ~AbstractAPI()= default;


};