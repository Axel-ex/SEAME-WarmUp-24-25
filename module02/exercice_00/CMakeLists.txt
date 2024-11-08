
cmake_minimum_required(VERSION 3.16)

set(This my_car)
project(${This})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set source and include directories
set(src_dir sources/)
set(inc_dir includes/)

# Define sources
set(srcs
    ${src_dir}main.cpp
    ${src_dir}Car.cpp
	${src_dir}SportsCar.cpp
)

# Create the main executable
add_executable(${This} ${srcs})

# Look for header files inside of the includes folder
target_include_directories(${This} PRIVATE ${inc_dir})

