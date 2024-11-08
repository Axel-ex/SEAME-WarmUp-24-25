cmake_minimum_required(VERSION 3.8)

# Set the project name for the tests
set(This my_car_tests)

# Define test sources
set(Sources
    test.cpp
)

# Create the test executable
add_executable(${This} ${Sources})


# Link the test executable with the my_car_lib library and gtest_main
target_link_libraries(${This}
    PRIVATE
    my_car_lib  # Link with the main library
    gtest_main  # Link with GoogleTest main
)

# Add a test entry for CTest
add_test(
    NAME ${This}  # Give a unique name to the test
    COMMAND ${This}  # Specify the test executable to run
)
