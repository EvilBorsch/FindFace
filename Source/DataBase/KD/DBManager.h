#pragma once

#include <string>
#include <memory>

#include <bsoncxx/builder/stream/document.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#include "DataBase/Base/BaseDBManager.h"
#include "DataBase/Base/BaseContainer.h"
#include "Container.h"
#include "DataBase/Base/BaseDBManager.h"
#include "DataBase/Base/BaseDataStructure.h"

class DBManager: public BaseDBManager{
public:

	DBManager(mongocxx::v_noabi::collection collection_);

	void save_container(BaseContainer *container_ptr);

	BaseContainer* get_container(const std::string &id);
	BaseContainer* get_free_container();

	BaseContainer* get_free_kd_tree(DBManager *db_manager, size_t max_containers_count);
	BaseContainer* get_kd_tree(const std::string &id, DBManager *db_manager, size_t max_containers_count);

private:

	mongocxx::v_noabi::collection collection;
};
