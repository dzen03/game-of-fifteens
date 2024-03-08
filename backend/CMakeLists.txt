cmake_minimum_required(VERSION 3.22)
project(fifteens-server)

add_executable(fifteens-server main.cpp)
target_link_libraries(fifteens-server PRIVATE main_sources)

option(BUILD_TESTING "Enable tests" ON)
if(BUILD_TESTING)
    enable_testing()
endif()

add_subdirectory(fifteens)
#add_subdirectory(simple-http-server)
