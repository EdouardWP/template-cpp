# Fetch and configure GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Include directories for headers
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include)

# Link GoogleTest library
link_libraries(GTest::gtest_main)

# Compile the new test file and link against the necessary libraries
add_executable(test_zipfs test_zipfs.cpp)
target_link_libraries(test_zipfs)

# Register the tests with GoogleTest
gtest_discover_tests(test_zipfs)
