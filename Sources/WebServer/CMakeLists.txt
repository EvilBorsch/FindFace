cmake_minimum_required(VERSION 3.14)
project(CPProject)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

find_package(poco REQUIRED)
include_directories(${POCO_INCLUDE_DIRS})

find_package(Poco REQUIRED COMPONENTS Foundation Net Zip)
include_directories(${POCO_INCLUDE_DIRS})
#add_executable(testPythonInC main.cpp poco.h poco.cpp)
#target_link_libraries(testPythonInC PUBLIC Poco::Foundation Poco::Zip Poco::Net)

find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH_REQUEST ${CMAKE_CURRENT_SOURCE_DIR}/HttpRequest)
set(CMAKE_MODULE_PATH_RESPONSE ${CMAKE_CURRENT_SOURCE_DIR}/HttpResponse)
set(CMAKE_MODULE_PATH_LRU ${CMAKE_CURRENT_SOURCE_DIR}/LRU)
set(CMAKE_MODULE_PATH_SERVER ${CMAKE_CURRENT_SOURCE_DIR}/Server)


set(ALL_SOURCES
        ${CMAKE_MODULE_PATH_REQUEST}/HttpRequest.cpp
        ${CMAKE_MODULE_PATH_RESPONSE}/HttpResponse.cpp
        ${CMAKE_MODULE_PATH_LRU}/LRU.cpp
        ${CMAKE_MODULE_PATH_SERVER}/Server.cpp
        )


set(ALL_VIEWS_HEADERS
        ${CMAKE_MODULE_PATH_REQUEST}/HttpRequest/
        ${CMAKE_MODULE_PATH_RESPONSE}/HttpResponse/
        ${CMAKE_MODULE_PATH_LRU}/LRU/
        ${CMAKE_MODULE_PATH_SERVER}/Server/

        )
include_directories(${ALL_SOURCES})
include_directories(${ALL_HEADERS})

add_executable(CPProject.out  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp ${ALL_SOURCES} )

add_subdirectory(Google_tests)