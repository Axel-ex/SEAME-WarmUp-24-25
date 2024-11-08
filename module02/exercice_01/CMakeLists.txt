cmake_minimum_required(VERSION 3.16)

set(This my_car)
project(${This})
set (CMAKE_CXX_FLAGS "-Wall -Wextra -g")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(src_dir sources/)
set(inc_dir includes/)

set(srcs
	${src_dir}main.cpp
	${src_dir}Car.cpp
	${src_dir}Break.cpp
	${src_dir}Engine.cpp
	${src_dir}Transmission.cpp
	${src_dir}Wheel.cpp
)

add_executable(${This}
  ${srcs})

#look for header files inside of the includes folder
target_include_directories(${This} PRIVATE ${inc_dir})

# Enable testing
enable_testing()

# Use FetchContent to download GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

# Add the main library that will be linked with tests
add_library(${This}_lib STATIC ${srcs})

# Link the main library with necessary include directories
target_include_directories(${This}_lib PUBLIC ${inc_dir})

# Add the test directory
add_subdirectory(test)

