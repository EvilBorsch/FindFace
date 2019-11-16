#include <vector>
#include <string>
#include <iostream>
#include "../url/url.h"

#pragma once


class AbstractIdListGeneratorStrategy {
private:

public:
    virtual std::vector<url> generate() = 0;

    virtual ~AbstractIdListGeneratorStrategy() = default;

    std::vector<url> loadUrls(std::string path) {
        return {};
    };
};