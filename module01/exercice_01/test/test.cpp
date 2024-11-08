#include "Car.hpp"
#include "Sportscar.hpp"
#include "gtest/gtest.h"

TEST(Car, copy_constructor)
{
    Car my_car("Tesla", "S", "2024");
    Car other_car(my_car);

    ASSERT_EQ(other_car.getMake(), my_car.getMake());
    ASSERT_EQ(other_car.getModel(), my_car.getModel());
    ASSERT_EQ(other_car.getYear(), my_car.getYear());

    // Ensure they are distinct objects
    ASSERT_NE(&other_car, &my_car);
}

TEST(Car, copy_assignment)
{
    Car my_car("Tesla", "S", "2024");
    Car other_car("Opel", "Corsa", "2006");

    other_car = my_car;
    ASSERT_EQ(other_car.getMake(), my_car.getMake());
    ASSERT_EQ(other_car.getModel(), my_car.getModel());
    ASSERT_EQ(other_car.getYear(), my_car.getYear());

    // Ensure they are distinct objects
    ASSERT_NE(&other_car, &my_car);
}

TEST(Car, move_constructor)
{
    Car my_car("Tesla", "S", "2024");
    Car moved_car(std::move(my_car));

    // Ensure moved_car has the original data
    ASSERT_EQ(moved_car.getMake(), "Tesla");
    ASSERT_EQ(moved_car.getYear(), "2024");

    // Check that my_car is in a neutral state (moved-from state)
    ASSERT_EQ(my_car.getModel(), "");
    ASSERT_EQ(my_car.getMake(), "");
    ASSERT_EQ(my_car.getYear(), "");
}

TEST(Car, move_assignment)
{
    Car my_car("Tesla", "S", "2024");
    Car other_car("Opel", "Corsa", "2006");

    other_car = std::move(my_car);

    // Ensure other_car has the data from my_car
    ASSERT_EQ(other_car.getMake(), "Tesla");
    ASSERT_EQ(other_car.getModel(), "S");
    ASSERT_EQ(other_car.getYear(), "2024");

    // Check that my_car is in a neutral state (moved-from state)
    ASSERT_EQ(my_car.getModel(), "");
    ASSERT_EQ(my_car.getMake(), "");
    ASSERT_EQ(my_car.getYear(), "");
}

TEST(SportsCar, constructor)
{
    Car my_car = SportsCar("Tesla", "S", "2024");

    ASSERT_EQ(my_car.getMake(), "Tesla");
    ASSERT_EQ(my_car.getYear(), "2024");
}

TEST(Sportscar, setter)
{
    SportsCar my_car;

    my_car.setTopSpeed(30);
    ASSERT_EQ(my_car.getTopSpeed(), 30);
}

// Entry point for running the tests
int main(int argc, char** argv)
{
    // Initialize Google Test framework
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
