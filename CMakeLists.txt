cmake_minimum_required(VERSION 3.14)
project(search_engine)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(index_test.cpp
        ${CMAKE_SOURCE_DIR}/src/InvertedIndex.cpp
        ${CMAKE_SOURCE_DIR}/src/server.cpp)

include(FetchContent)

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.10.5)

FetchContent_MakeAvailable(json)

add_executable(
        search_engine  # Define your main executable target here
        src/main.cpp
        src/ConverterJSON.cpp
        include/ConverterJSON.h
        include/InvertedIndex.h src/InvertedIndex.cpp tests/index_test.cpp src/server.cpp)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)

# Your hello_test setup
add_executable(
        hello_test
        tests/hello_test.cc
        include/InvertedIndex.h tests/index_test.cpp src/InvertedIndex.cpp include/server.h)

target_link_libraries(
        hello_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
