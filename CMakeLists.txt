cmake_minimum_required(VERSION 3.5.0)
project(PetRock VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)
add_executable(PetRock main.cpp)

include(CTest)
enable_testing()

