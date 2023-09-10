# Create a test executable for index_test.cpp
add_executable(
        index_test
        index_test.cpp
        ${CMAKE_SOURCE_DIR}/src/InvertedIndex.cpp
        ${CMAKE_SOURCE_DIR}/src/server.cpp
)

# Link the test executable with Google Test and your main project library
target_link_libraries(index_test PRIVATE gtest_main search_engine_lib)

# Create a test executable for hello_test.cc
add_executable(
        hello_test
        hello_test.cc
        index_test.cpp
        server_tests.cpp
        ${CMAKE_SOURCE_DIR}/src/InvertedIndex.cpp
        ${CMAKE_SOURCE_DIR}/src/server.cpp
)

# Link the test executable with Google Test and your main project library
target_link_libraries(hello_test PRIVATE gtest_main search_engine_lib)

# Include Google Test for running tests
include(GoogleTest)
gtest_discover_tests(index_test)
gtest_discover_tests(hello_test)
