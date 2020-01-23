#include "WebCrowler/AbstractClasses/AbstractAPI.h"
#include "WebCrowler/NetService/NetService.h"

#pragma once

class OkAPI : public AbstractAPI {
private:
    std::string token;
public:
    std::vector<url> getPhotoUrlsById(const url &url) override;

    explicit OkAPI(const std::string &app_key);

    void login() override;

};