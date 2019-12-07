#pragma once

#include <string>
#include <memory>

#include <bsoncxx/builder/stream/document.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#include "BaseDBManager.h"
#include "BaseContainer.h"
#include "Container.h"

class DBManager: public BaseDBManager{
public:

	DBManager(mongocxx::v_noabi::collection collection_);

	void save_container(BaseContainer *container_ptr);

	Container* get_container(const std::string &id);
	Container* get_free_container();

private:

	mongocxx::v_noabi::collection collection;
};
