#include <string>
#include <vector>
#include "url/url.h"

#pragma once


class AbstractAPI {
public:
    virtual std::vector<url> getPhotoUrlsById(const url &m_url) = 0;


    virtual void login() = 0;

    virtual ~AbstractAPI() = default;

    AbstractAPI() = default;

};