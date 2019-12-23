cmake_minimum_required(VERSION 3.14)
project(FindFace)

set(-DBOOST_LOG_DYN_LINK=/usr/local/Cellar/boost/1.71.0/include/boost/log/trivial.hpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Sources)
set(GTESTS ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Google_tests)


include_directories(${CMAKE_MODULE_PATH})
include_directories(${CMAKE_MODULE_PATH}/Views)
include_directories(${CMAKE_MODULE_PATH}/PageData)
include_directories(${CMAKE_MODULE_PATH}/Page)
include_directories(${CMAKE_MODULE_PATH}/PageGenerator)
include_directories(${CMAKE_MODULE_PATH}/PageManager)

set(ALL_SOURCES
        ${CMAKE_MODULE_PATH}/Views/SecondaryView/SecondaryView.cpp
        ${CMAKE_MODULE_PATH}/Views/UserData/UserData.cpp
        ${CMAKE_MODULE_PATH}/Views/Container/ContainerView.cpp
        ${CMAKE_MODULE_PATH}/Views/Cell/CellView.cpp
        ${CMAKE_MODULE_PATH}/Views/Row/RowView.cpp
        ${CMAKE_MODULE_PATH}/Views/ImageView/ImageView.cpp
        ${CMAKE_MODULE_PATH}/Views/TableView/TableView.cpp
        ${CMAKE_MODULE_PATH}/Views/TextView/TextView.cpp
        ${CMAKE_MODULE_PATH}/Views/View/View.cpp
        ${CMAKE_MODULE_PATH}/Views/PersonView/PersonView.cpp

        ${CMAKE_MODULE_PATH}/Views/Form/FormView.cpp

        ${CMAKE_MODULE_PATH}/Page/Page.cpp
        ${CMAKE_MODULE_PATH}/PageGenerator/PageGenerator.cpp
        ${CMAKE_MODULE_PATH}/PageManager/PageManager.cpp
        ${CMAKE_MODULE_PATH}/PageData/PageData.cpp

        )


set(ALL_VIEWS_HEADERS

        ${CMAKE_MODULE_PATH}/Views/UserData/
        ${CMAKE_MODULE_PATH}/Views/Container/
        ${CMAKE_MODULE_PATH}/Views/Cell/
        ${CMAKE_MODULE_PATH}/Views/Row/
        ${CMAKE_MODULE_PATH}/Views/ImageView/
        ${CMAKE_MODULE_PATH}/Views/TableView/
        ${CMAKE_MODULE_PATH}/Views/TextView/
        ${CMAKE_MODULE_PATH}/Views/View/
        ${CMAKE_MODULE_PATH}/Views/PersonView/
        ${CMAKE_MODULE_PATH}/Views/SecondaryView/

        ${CMAKE_MODULE_PATH}/Views/Form/

        ${CMAKE_MODULE_PATH}/Page/
        ${CMAKE_MODULE_PATH}/PageGenerator/
        ${CMAKE_MODULE_PATH}/PageManager/
        ${CMAKE_MODULE_PATH}/PageData/
        )
include_directories(${ALL_SOURCES})
include_directories(${ALL_HEADERS})



find_package(Boost)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(FindFace  ${CMAKE_MODULE_PATH}/main.cpp ${ALL_SOURCES} )

target_link_libraries(FindFace ${Boost_LIBRARIES})


add_subdirectory(Sources/Google_tests)

