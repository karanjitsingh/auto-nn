cmake_minimum_required(VERSION 3.8)
project(auto_nn)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        2048/game.cpp
        main.cpp
        README.md
        settings.json)

add_executable(auto_nn ${SOURCE_FILES})