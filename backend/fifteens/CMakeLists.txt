set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs)
include_directories(libs)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

