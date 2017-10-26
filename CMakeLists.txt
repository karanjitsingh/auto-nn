cmake_minimum_required(VERSION 3.8)
project(auto_nn)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        2048/Two048.cpp
        main.cpp
        NeuralNetwork/NeuralNetwork.cpp 2048/Two048.h GA/Genotype.cpp GA/Genotype.h NeuralNetwork/NeuralNetwork.h GA/GA.cpp GA/GA.h)

add_executable(auto_nn ${SOURCE_FILES})
add_subdirectory(OpenNN)