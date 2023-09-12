cmake_minimum_required(VERSION 3.14)
project(search_engine)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include FetchContent configuration for nlohmann json
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.10.5
)
FetchContent_MakeAvailable(json)

# Create the main project executable
add_executable(
        search_engine
        main.cpp
        ConverterJSON.cpp
        ConverterJSON.h
        InvertedIndex.h
        InvertedIndex.cpp
        server.cpp
        index_test.cpp
)

# Link the executable with nlohmann_json
target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)

# Your hello_test setup
add_subdirectory(tests)  # Include the tests directory
