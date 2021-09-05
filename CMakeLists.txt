cmake_minimum_required(VERSION 3.10)

# set the project information
project(esoteric VERSION 0.0.1)

# setup the C++ compiler
set(CMAKE_CXX_COMPILER g++)

# set C++ flags
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")

# get all C++ files
file(GLOB_RECURSE SOURCES *.cc)

# add the executable
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${INCLUDE})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 14)

# install command
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION /usr/local/bin)
