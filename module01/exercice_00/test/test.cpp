#include "Car.hpp"
#include "gtest/gtest.h"

TEST(Car, copy_constructor)
{
    Car my_car("Tesla", "super_fast");
    Car other_car(my_car);

    ASSERT_EQ(other_car.getName(), my_car.getName());
    ASSERT_EQ(other_car.getSpeed(), my_car.getSpeed());

    // Ensure they are distinct objects
    ASSERT_NE(&other_car, &my_car);
}

TEST(Car, copy_assignment)
{
    Car my_car("Tesla", "super_fast");
    Car other_car("Opel", "very_slow");

    other_car = my_car;
    ASSERT_EQ(other_car.getName(), my_car.getName());
    ASSERT_EQ(other_car.getSpeed(), my_car.getSpeed());

    // Ensure they are distinct objects
    ASSERT_NE(&other_car, &my_car);
}

TEST(Car, move_constructor)
{
    Car my_car("Tesla", "super_fast");
    Car moved_car(std::move(my_car));

    // Ensure moved_car has the original data
    ASSERT_EQ(moved_car.getName(), "Tesla");
    ASSERT_EQ(moved_car.getSpeed(), "super_fast");

    // Check that my_car is in a neutral state (moved-from state)
    ASSERT_EQ(my_car.getName(), "");
    ASSERT_EQ(my_car.getSpeed(), "");
}

TEST(Car, move_assignment)
{
    Car my_car("Tesla", "super_fast");
    Car other_car("Opel", "very_slow");

    other_car = std::move(my_car);

    // Ensure other_car has the data from my_car
    ASSERT_EQ(other_car.getName(), "Tesla");
    ASSERT_EQ(other_car.getSpeed(), "super_fast");

    // Check that my_car is in a neutral state (moved-from state)
    ASSERT_EQ(my_car.getName(), "");
    ASSERT_EQ(my_car.getSpeed(), "");
}

// Entry point for running the tests
int main(int argc, char** argv)
{
    // Initialize Google Test framework
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
