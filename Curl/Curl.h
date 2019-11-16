#include <string>
#include "../response/response.h"
#pragma once

class Curl {
public:
    response request(std::string url);
};