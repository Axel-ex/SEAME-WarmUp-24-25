cmake_minimum_required(VERSION 3.16)

project(QT_test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_PREFIX_PATH "/Users/Axel/Qt/6.8.0/macos")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Define source and header directories
set(src_dir sources/)
set(inc_dir includes/)

# Define source files separately
set(SOURCE_FILES
    ${src_dir}main.cpp
    ${src_dir}mainwindow.ui
	${src_dir}mainwindow.cpp
	${src_dir}Contact.cpp
	${src_dir}Phonebook.cpp
	${src_dir}AddContactDialog.cpp
)

# Define header files separately
set(HEADER_FILES
    ${inc_dir}mainwindow.h
	${inc_dir}Contact.hpp
	${inc_dir}Phonebook.hpp
	${inc_dir}AddContactDialog.hpp
)

# Add include directories for header files
include_directories(${inc_dir})

# Combine source and header files into PROJECT_SOURCES
set(PROJECT_SOURCES ${SOURCE_FILES} ${HEADER_FILES})


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(phonebook
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(phonebook SHARED ${PROJECT_SOURCES})
    else()
        add_executable(phonebook ${PROJECT_SOURCES})
    endif()
endif()

# Link Qt libraries
target_link_libraries(phonebook PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Set target properties for Mac/iOS if needed
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.phonebook)
endif()
set_target_properties(phonebook PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS phonebook
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalize executable for Qt 6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(phonebook)
endif()

