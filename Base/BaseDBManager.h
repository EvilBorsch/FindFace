#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "BaseContainer.h"

class BaseDBManager{
public:

	virtual void save_container(BaseContainer *container_ptr) = 0;
	virtual BaseContainer* get_container(const std::string &id) = 0;
	virtual BaseContainer* get_free_container() = 0;
};
