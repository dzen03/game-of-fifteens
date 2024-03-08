file(GLOB_RECURSE sources CONFIGURE_DEPENDS
        *.cpp
        *.h
)

add_library(main_sources SHARED ${sources})
target_include_directories(main_sources PUBLIC .)
