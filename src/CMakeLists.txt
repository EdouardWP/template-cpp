# Look for headers in the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add executable for main_zipfs_containers.cpp
add_executable(zipfs_containers main_zipfs_containers.cpp)

# Add executable for main_zipfs_algorithms.cpp
add_executable(zipfs_algorithms main_zipfs_algorithms.cpp)

# Copy the text files to the build/bin directory after compiling
add_custom_command(TARGET zipfs_containers POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/src/balling.txt
        ${CMAKE_BINARY_DIR}/bin/balling.txt
)

add_custom_command(TARGET zipfs_algorithms POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/src/text.txt
        ${CMAKE_BINARY_DIR}/bin/text.txt
)
