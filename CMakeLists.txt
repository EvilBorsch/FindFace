cmake_minimum_required(VERSION 3.15)
project(kursach_final)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${CMAKE_MODULE_PATH})
include_directories(${CMAKE_MODULE_PATH}/AbstractClasses)
include_directories(${CMAKE_MODULE_PATH}/API)
include_directories(${CMAKE_MODULE_PATH}/Crowler)
include_directories(${CMAKE_MODULE_PATH}/Id_list_generator_strategy)
include_directories(${CMAKE_MODULE_PATH}/NetService)
include_directories(${CMAKE_MODULE_PATH}/response)
include_directories(${CMAKE_MODULE_PATH}/url)

set(ALL_SOURCES
        ${CMAKE_MODULE_PATH}/API/FacebookAPI.cpp
        ${CMAKE_MODULE_PATH}/API/OkAPI.cpp
        ${CMAKE_MODULE_PATH}/API/VkAPI.cpp
        ${CMAKE_MODULE_PATH}/Id_list_generator_strategy/Facebook_id_list_generator_strategy.cpp
        ${CMAKE_MODULE_PATH}/Id_list_generator_strategy/Vk_id_list_generator_strategy.cpp
        ${CMAKE_MODULE_PATH}/Id_list_generator_strategy/Ok_id_list_generator_strategy.cpp
        ${CMAKE_MODULE_PATH}/NetService/NetService.cpp
        ${CMAKE_MODULE_PATH}/response/response.cpp
        ${CMAKE_MODULE_PATH}/Crowler/Crowler.cpp
        )

set(ALL_VIEWS_HEADERS
        ${CMAKE_MODULE_PATH}/AbstractClasses/
        ${CMAKE_MODULE_PATH}/API/
        ${CMAKE_MODULE_PATH}/Crowler/
        ${CMAKE_MODULE_PATH}/Id_list_generator_strategy/
        ${CMAKE_MODULE_PATH}/NetService/
        ${CMAKE_MODULE_PATH}/response/
        ${CMAKE_MODULE_PATH}/url/

        )


include_directories(${ALL_SOURCES})
include_directories(${ALL_HEADERS})

add_executable(kursach_final ${CMAKE_MODULE_PATH}/main.cpp ${ALL_SOURCES})


add_subdirectory(Google_tests)

find_package(Boost COMPONENTS system filesystem REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(kursach_final ${Boost_LIBRARIES})

set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(kursach_final ${CURL_LIBRARIES})



