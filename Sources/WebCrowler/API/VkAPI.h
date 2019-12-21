#include "WebCrowler/AbstractClasses/AbstractAPI.h"
#include "WebCrowler/NetService/NetService.h"

#pragma once

class VkAPI : public AbstractAPI {
private:
    std::string token;
    std::string app_key;
public:

    std::vector<url> getPhotoUrlsById(const url &url) override;


    explicit VkAPI(const std::string &app_key);


    void login() override;

};