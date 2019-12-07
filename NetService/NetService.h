#include <string>
#include "response/response.h"
#include "url/url.h"

#pragma once

class NetService {
public:
    response request(url m_url);
};