#include "Sportscar.hpp"
#include <iostream>

SportsCar::SportsCar(void) : Car(), _top_speed(250)
{
    std::cout << "SportsCar constructor called" << std::endl;
}

SportsCar::SportsCar(const std::string& make, const std::string& model,
                     const std::string& year)
    : Car(make, model, year), _top_speed(250)
{
}

void SportsCar::drive(void) const
{
    Car::drive();
    std::cout << "top speed: " << _top_speed << std::endl;
}

int SportsCar::getTopSpeed(void) const { return _top_speed; }

void SportsCar::setTopSpeed(int speed) { _top_speed = speed; }
