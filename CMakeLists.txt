cmake_minimum_required(VERSION 2.6)
project(sets_objects)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(sets_objects main.cpp Sets.cpp)

install(TARGETS sets_objects RUNTIME DESTINATION bin)
