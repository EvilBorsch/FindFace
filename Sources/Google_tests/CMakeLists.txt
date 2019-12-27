project(Google_tests)
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


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
        ${CMAKE_MODULE_PATH}/Views/Sample/

        ${CMAKE_MODULE_PATH}/Page/
        ${CMAKE_MODULE_PATH}/PageGenerator/
        ${CMAKE_MODULE_PATH}/PageManager/
        ${CMAKE_MODULE_PATH}/PageData/
        )
include_directories(${ALL_SOURCES})
include_directories(${ALL_HEADERS})

add_executable(Google_Tests_run ViewTests.cpp SecondaryViewTests.cpp TextViewTests.cpp ImageViewTests.cpp FormViewTests.cpp )
target_link_libraries(Google_Tests_run gtest gtest_main)