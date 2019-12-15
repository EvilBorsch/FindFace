#include "AbstractClasses/AbstractAPI.h"
#include "NetService/NetService.h"

#pragma once

class FacebookAPI : public AbstractAPI {
private:
    std::string token;
    std::string app_key;
    std::string secret_key;
public:
    std::vector<url> getPhotoUrlsById(const url &mUrl) override;

    FacebookAPI(const std::string &mapp_key, const std::string &msecret_key);

    void login() override;


};