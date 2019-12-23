#pragma once
#include <vector>

class BaseComporator{
public:

    bool virtual operator()(const std::vector<double>& a, const std::vector<double>& b, const double& bias = 0);
    bool virtual operator()(const double& a, const double& b);

    void virtual set_depth(const size_t &depth);
    size_t virtual get_depth();

protected:
	size_t depth = 0;
};