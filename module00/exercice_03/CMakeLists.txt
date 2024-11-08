cmake_minimum_required(VERSION 3.16)

project(phonebook)
set (CMAKE_CXX_FLAGS "-Wall -Wextra -g")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(src_dir sources/)
set(inc_dir includes/)

set(srcs
	${src_dir}main.cpp
	${src_dir}Phonebook.cpp
	${src_dir}Contact.cpp
	${src_dir}Formatter.cpp)

add_executable(phonebook
  ${srcs})

#look for header files inside of the includes folder
target_include_directories(phonebook PRIVATE ${CMAKE_SOURCE_DIR}/includes)
