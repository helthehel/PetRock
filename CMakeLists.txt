cmake_minimum_required(VERSION 3.5.0)
project(PetRock VERSION 0.1.0 LANGUAGES C CXX)

#SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
#SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
include_directories(include)
link_directories(SDL2, SDL2_image, SDL2_ttf, SDL2_mixer, SDL2main)
add_executable(PetRock main.cpp Window.cpp UIElements.cpp)

include(CTest)
enable_testing()

