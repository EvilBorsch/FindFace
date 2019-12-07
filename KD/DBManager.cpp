#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include <bsoncxx/builder/stream/document.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>


#include "DBManager.h"
#include "Container.h"
#include "BaseContainer.h"



DBManager::DBManager(mongocxx::v_noabi::collection collection_):collection(collection_){}

void DBManager::save_container(BaseContainer *container){

    bsoncxx::builder::stream::document buff_doc{};
        
    auto set_container = buff_doc << "$set"
    << bsoncxx::builder::stream::open_document;

    container->save(set_container);

    bsoncxx::v_noabi::document::value container_doc = set_container << bsoncxx::builder::stream::close_document
    << bsoncxx::builder::stream::finalize;

    bsoncxx::stdx::optional<bsoncxx::document::value> found_container = collection.find_one(
        bsoncxx::builder::stream::document{} << "_id"
        << bsoncxx::oid{bsoncxx::stdx::string_view{container->id}}
        << bsoncxx::builder::stream::finalize
    );

    if(found_container){
        collection.update_one(found_container.value().view(), container_doc.view());
    }
    else{
        //TODO
        collection.insert_one(container_doc.view());
    }
}

Container* DBManager::get_container(const std::string &id){
    bsoncxx::stdx::optional<bsoncxx::document::value> container_doc = collection.find_one(
        bsoncxx::builder::stream::document{} << "_id"
        << bsoncxx::oid{bsoncxx::stdx::string_view{id}}
        << bsoncxx::builder::stream::finalize
    );

    Container *container(new Container(id));

    if(container_doc){

        container->load(container_doc->view());
    }
    else{
        //TODO
    }

    return(container);
}


Container* DBManager::get_free_container(){
    bsoncxx::builder::stream::document document{};
    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = collection.insert_one(document.view());
    std::string id = result.value().inserted_id().get_oid().value.to_string();
    return new Container(id);
}