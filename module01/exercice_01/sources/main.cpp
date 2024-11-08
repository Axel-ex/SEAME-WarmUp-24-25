#include "Car.hpp"
#include "Sportscar.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
    SportsCar my_car = SportsCar("Tesla", "S", "2024");

    my_car.drive();

    return EXIT_SUCCESS;
}
