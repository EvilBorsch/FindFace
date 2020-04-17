#include <vector>
#include <cmath>
#include <iostream>
#include "BaseMetrificator.h"

double BaseMetrificator::operator()(const std::vector<double>& a, const std::vector<double>& b){
    double answer = 0.0;
    for(size_t c = 0; c < a.size(); ++c){
    	double dist = a[c] - b[c];
    	answer += dist * dist;	
    }
	return answer > 0.0 ? std::sqrt(answer) : 0.0;
}