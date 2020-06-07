cmake_minimum_required(VERSION 3.17)
project(blueprint) # Change me!
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(main ${SOURCES})
