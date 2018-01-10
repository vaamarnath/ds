# Basic CMake project
cmake_minimum_required(VERSION 2.8.11)

# Get the source name from the current directory
get_filename_component(source ${CMAKE_CURRENT_SOURCE_DIR} NAME)
get_filename_component(root_dir ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

# Name the project after the source
project(${source} CXX)

# Locate Boost libraries: unit_test_framework, date_time and regex
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.59 REQUIRED COMPONENTS unit_test_framework date_time regex)

include_directories(${root_dir})

# Enable C++11 features on gcc/clang
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

# Get a source filename from the source name by replacing -'s with _'s
string(REPLACE "-" "_" file ${source})

# Implementation could be only a header
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file}.cpp)
    set(source_cpp ${file}.cpp)
else()
    set(source_cpp "")
endif()

# Build executable from sources and headers
add_executable(${source} ${file}_test.cpp ${source_cpp} ${file}.h)

# We need boost includes
target_include_directories(${source} PRIVATE ${Boost_INCLUDE_DIRS})

# We need boost libraries
target_link_libraries(${source} ${Boost_LIBRARIES})

# Run the tests on every build
add_custom_command(TARGET ${source} POST_BUILD COMMAND ${source})
