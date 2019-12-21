#include <string>
#include "WebCrowler/response/response.h"
#include "WebCrowler/url/url.h"

#pragma once

class NetService {
public:
    response request(url m_url);
};