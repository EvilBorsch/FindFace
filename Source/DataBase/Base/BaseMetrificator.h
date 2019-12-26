#pragma once
#include <vector>

class BaseMetrificator{

public:
	double virtual operator()(const std::vector<double>& a, const std::vector<double>& b);
};
