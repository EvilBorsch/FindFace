#include <string>
#include <vector>
#include "../url/url.h"
#pragma once



class AbstractAPI {
public:
    virtual std::vector<url> getPhotoUrlsById(const url &m_url) = 0;

    virtual std::vector<url> getFriendsUrlsById(const url &m_url) = 0;

    virtual std::vector<url> getGroupParticipants(const url &m_url) = 0;

    virtual void login(std::string app_key) = 0;
    virtual ~AbstractAPI() = default;

    AbstractAPI() = default;

};