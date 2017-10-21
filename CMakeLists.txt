cmake_minimum_required(VERSION 3.8)
project(auto_nn)

find_package (OpenNN)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        2048/game.cpp
        main.cpp
        NeuralNetwork/nn.cpp 2048/game.h)

add_executable(auto_nn ${SOURCE_FILES})