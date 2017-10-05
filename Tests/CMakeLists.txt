project(tests)

cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

find_package(Threads REQUIRED)

set(Tests_SRCS
    main.cpp
    Tests.cpp
    ../Sets.cpp
    ../Logger.cpp)

add_executable(tests ${Tests_SRCS})
target_link_libraries(tests
    ${GTEST_LIBRARIES}
    Threads::Threads)

add_test(AllTests tests)
