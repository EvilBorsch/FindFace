#include <vector>
#include "BaseComporator.h"

bool BaseComporator::operator()(const std::vector<double>& a, const std::vector<double>& b, const double& bias){
    return a[depth % a.size()] + bias < b[depth % b.size()];
}

bool BaseComporator::operator()(const double& a, const double& b){
    return a < b;
}

void BaseComporator::set_depth(const size_t &depth_){
	depth = depth_;
}

size_t BaseComporator::get_depth(){
	return depth;
}