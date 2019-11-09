project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(Google_Tests_run API_tests.cpp ../API/VkAPI.h ../API/VkAPI.cpp
        ../Id_list_generator_strategy/Vk_id_list_generator_strategy.h
        ../Id_list_generator_strategy/Vk_id_list_generator_strategy.cpp ../API/OkAPI.cpp ../API/OkAPI.h
        ../Id_list_generator_strategy/Ok_id_list_generator_strategy.cpp
        ../Id_list_generator_strategy/Ok_id_list_generator_strategy.h
        ../API/FacebookAPI.cpp ../API/FacebookAPI.h
        ../Id_list_generator_strategy/Facebook_id_list_generator_strategy.cpp
        ../Id_list_generator_strategy/Facebook_id_list_generator_strategy.h
        ../Curl/Curl.h ../Curl/Curl.cpp ../Crowler/Crowler.h ../Crowler/Crowler.cpp ../Id_list_generator_strategy/Ok_id_list_generator_strategy_friends_method.cpp ../Id_list_generator_strategy/Ok_id_list_generator_strategy_friends_method.h)
target_link_libraries(Google_Tests_run gtest gtest_main)