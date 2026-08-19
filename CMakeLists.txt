cmake_minimum_required(VERSION 3.28)
project(CMakeChess LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(
    CMakeChess 
    src/main.cpp
    src/Game.cpp
    src/Board.cpp
    src/Piece.cpp
    src/Coordinate.cpp
)
target_include_directories(CMakeChess PRIVATE include)
target_compile_features(CMakeChess PRIVATE cxx_std_17)
target_link_libraries(CMakeChess PRIVATE SFML::Graphics)

set_property(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} 
    PROPERTY VS_STARTUP_PROJECT CMakeChess
)