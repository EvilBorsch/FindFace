cmake_minimum_required(VERSION 3.8)
 
set (PROJECT KDDB) 
project (${PROJECT})  

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")

enable_testing()

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})


set (DIRECTORIES
	Base
	KD
	Tests
)

set (HEADERS 
	Base/BaseContainer.h
	Base/BaseDataStructure.h
	Base/BaseDBManager.h
	Base/BaseSearchEngine.h
	Base/BaseDB.h
	Base/BaseComporator.h
	Base/BaseMetrificator.h

	KD/Container.h
	KD/DB.h
	KD/DBManager.h
	KD/KDTree.h
	KD/SearchEngine.h
)
 
set (SOURCES 
	Base/BaseContainer.cpp
	Base/BaseDataStructure.cpp
	Base/BaseSearchEngine.cpp
	Base/BaseComporator.cpp
	Base/BaseMetrificator.cpp

	KD/Container.cpp
	KD/DB.cpp
	KD/DBManager.cpp
	KD/KDTree.cpp
	KD/SearchEngine.cpp
)

set (CONTAINER_TEST Tests/ContainerTest.cpp)
set (DBMANAGER_TEST Tests/DBManagerTest.cpp)
set (KDTREE_TEST Tests/KDTreeTest.cpp)
set (SEARCH_ENGINE_TEST Tests/SearchEngineTest.cpp)
set (DB_TEST Tests/DBTest.cpp)

include_directories(${DIRECTORIES})

add_library (${PROJECT} SHARED ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT} ${LIBMONGOCXX_LIBRARIES})
target_link_libraries(${PROJECT} ${LIBBSONCXX_LIBRARIES})


add_executable(runContainerTest ${CONTAINER_TEST})
target_link_libraries(runContainerTest ${PROJECT})
target_link_libraries(runContainerTest ${GTEST_LIBRARIES} pthread)

add_executable(runDBManagerTest ${DBMANAGER_TEST})
target_link_libraries(runDBManagerTest ${PROJECT})
target_link_libraries(runDBManagerTest ${GTEST_LIBRARIES} pthread)

add_executable(runKDTreeTest ${KDTREE_TEST})
target_link_libraries(runKDTreeTest ${PROJECT})
target_link_libraries(runKDTreeTest ${GTEST_LIBRARIES} pthread)

add_executable(runSearchEngineTest ${SEARCH_ENGINE_TEST})
target_link_libraries(runSearchEngineTest ${PROJECT})
target_link_libraries(runSearchEngineTest ${GTEST_LIBRARIES} pthread)

add_executable(runDBTest ${DB_TEST})
target_link_libraries(runDBTest ${PROJECT})
target_link_libraries(runDBTest ${GTEST_LIBRARIES} pthread)


add_test(runContainerTest "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/runContainerTest")
add_test(runDBManagerTest "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/runDBManagerTest")
add_test(runKDTreeTest "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/runKDTreeTest")
add_test(runSearchEngineTest "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/runSearchEngineTest")
add_test(runDBTest "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/runDBTest")

