cmake_minimum_required(VERSION 3.8)
 
set (PROJECT KDDB) 
 
project (${PROJECT}) 

find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")

set (DIRECTORIES
	Base
	KD
)

set (HEADERS 
	Base/BaseContainer.h
	Base/BaseDataStructure.h
	Base/BaseDBManager.h
	Base/BaseSearchEngine.h
	Base/BaseDB.h

	KD/Container.h
	KD/DB.h
	KD/DBManager.h
	KD/KDTree.h
	KD/SearchEngine.h
)
 
set (SOURCES 
	Base/BaseContainer.cpp
	Base/BaseDataStructure.cpp
	Base/BaseDB.cpp
	Base/BaseSearchEngine.cpp

	KD/Container.cpp
	KD/DB.cpp
	KD/DBManager.cpp
	KD/KDTree.cpp
	KD/SearchEngine.cpp
)

include_directories(${DIRECTORIES})
add_library (${PROJECT} SHARED ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT} ${LIBMONGOCXX_STATIC_LIBRARIES} ${LIBBSONCXX_STATIC_LIBRARIES})


