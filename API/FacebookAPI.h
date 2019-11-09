#include "../AbstractClasses/AbstractAPI.h"
#include "../Curl/Curl.h"
#pragma once

class FacebookAPI: public AbstractAPI{
private:
    Curl curler;
    string token;
public:
    vector<string> get_photo_urls_by_id(const string& url) override ;
    vector<string> get_friends_urls_by_id(const string& url) override ;
    vector<string> get_group_participants(const string& url) override ;
    explicit FacebookAPI(const string& app_key);

};