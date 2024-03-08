include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

FILE(GLOB_RECURSE test_sources CONFIGURE_DEPENDS
        *.cpp
)
foreach(test_source IN LISTS test_sources)
    string(REPLACE "/" ";" name_components ${test_source})
    list(GET name_components -1 name)
    string(REGEX REPLACE "\\.cpp$" "" name ${name})
    list(APPEND test_targets test_${name})

    add_executable(test_${name} ${test_source})
    target_link_libraries(test_${name} PRIVATE main_sources GTest::gtest_main)

    gtest_discover_tests(test_${name})
endforeach()

add_executable(all_gtest ${test_sources})
target_link_libraries(all_gtest PRIVATE main_sources GTest::gtest_main)
gtest_discover_tests(all_gtest)
