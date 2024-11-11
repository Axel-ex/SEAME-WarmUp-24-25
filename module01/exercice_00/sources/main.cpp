#include "Car.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
    Car my_car("Tesla", "super fast");

    std::cout << my_car;

    return EXIT_SUCCESS;
}
