cmake_minimum_required(VERSION 3.5)
project(DefendTheSpire)

set(CMAKE_CXX_STANDARD 20)

# Disable raylib examples and tests if you don't need them.
set(BUILD_EXAMPLES OFF CACHE BOOL "Disable raylib examples")
set(BUILD_TESTING OFF CACHE BOOL "Disable raylib tests")

# Add the raylib subdirectory from its location on disk.
add_subdirectory("C:/raylib/raylib" raylib_build)

# Create an executable using main.cpp.
add_executable(DefendTheSpire main.cpp
    Draw.cpp
        TowerManager.cpp
        globals.cpp
        game.cpp
        game.h
        TowerManager.h
        Creeps.cpp
        Creeps.h
)


# Link your executable to the raylib target.
target_link_libraries(DefendTheSpire PRIVATE raylib)
