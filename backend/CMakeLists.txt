cmake_minimum_required(VERSION 3.22)
project(fifteens-server)

add_executable(fifteens-server main.cpp)
target_link_libraries(fifteens-server PRIVATE main_sources simple-http-server-sources)

option(BUILD_TESTING "Enable tests" ON)
if(BUILD_TESTING)
    enable_testing()

    include(FetchContent)
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

add_subdirectory(fifteens)
add_subdirectory(simple-http-server)
