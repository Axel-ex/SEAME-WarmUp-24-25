#include "Car.hpp"
#include "gtest/gtest.h"

TEST(Car, copy_constructor)
{
    Car my_car;
    Car other_car(my_car);

    // Ensure they are distinct objects
    ASSERT_NE(&other_car, &my_car);
    ASSERT_NE(my_car.getEngine(), other_car.getEngine());
    ASSERT_NE(my_car.getTransmission(), other_car.getTransmission());
    ASSERT_NE(my_car.getBreaks(), other_car.getBreaks());
    ASSERT_NE(my_car.getWheels(), other_car.getWheels());
}

TEST(Car, copy_assignment)
{
    Car my_car, other_car;

    other_car = my_car;

    // Ensure they are distinct objects
    ASSERT_NE(&other_car, &my_car);
    ASSERT_NE(my_car.getEngine(), other_car.getEngine());
    ASSERT_NE(my_car.getTransmission(), other_car.getTransmission());
    ASSERT_NE(my_car.getBreaks(), other_car.getBreaks());
    ASSERT_NE(my_car.getWheels(), other_car.getWheels());
}

TEST(Car, move_constructor)
{
    Car my_car;
    Car moved_car(std::move(my_car));

    // Ensure my_car was freed from its resources
    ASSERT_EQ(my_car.getEngine(), nullptr);
    ASSERT_EQ(my_car.getTransmission(), nullptr);
    ASSERT_EQ(my_car.getBreaks(), nullptr);
    ASSERT_EQ(my_car.getWheels(), nullptr);
}

TEST(Car, move_assignment)
{
    Car my_car, other_car;

    other_car = std::move(my_car);

    // Ensure my_car was freed from its resources
    ASSERT_EQ(my_car.getEngine(), nullptr);
    ASSERT_EQ(my_car.getTransmission(), nullptr);
    ASSERT_EQ(my_car.getBreaks(), nullptr);
    ASSERT_EQ(my_car.getWheels(), nullptr);
}

// Entry point for running the tests
int main(int argc, char** argv)
{
    // Initialize Google Test framework
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
