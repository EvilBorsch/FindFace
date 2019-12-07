#include <iostream>
#include <url.h>
#include <response.h>

#pragma once


class AbstractNetService {
public:
    virtual response request(url m_url) = 0;
};