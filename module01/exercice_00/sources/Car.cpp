#include "Car.hpp"
#include <iostream>

Car::Car(void) { std::cout << "Car default constructor called" << std::endl; }
Car::~Car(void) { std::cout << "Car destructor called" << std::endl; }

Car::Car(const std::string& name, const std::string& speed)
    : _name(name), _speed(speed)
{
    std::cout << "Car constructor called" << std::endl;
}

// Move constructor
Car::Car(Car&& to_move) noexcept
    : _name(std::move(to_move._name)), _speed(std::move(to_move._speed))
{
    std::cout << "Car move constructor called" << std::endl;
    // Set the moved-from object to a neutral state
    to_move._name = "";
    to_move._speed = "";
}

Car::Car(const Car& to_copy)
{
    std::cout << "Car copy constructor called" << std::endl;
    *this = to_copy;
}

Car& Car::operator=(const Car& rhs)
{
    if (this == &rhs)
        return *this;

    std::cout << "Car copy assignement called" << std::endl;
    _name = rhs._name;
    _speed = rhs._speed;
    return *this;
}

Car& Car::operator=(Car&& rhs) noexcept
{
    if (this == &rhs)
        return *this;

    std::cout << "Car move assignement called" << std::endl;
    _name = std::move(rhs._name);
    _speed = std::move(rhs._speed);

    rhs._name = "";
    rhs._speed = "";

    return *this;
}

// GETTERS
const std::string& Car::getName(void) const { return _name; }

const std::string& Car::getSpeed(void) const { return _speed; }

std::ostream& operator<<(std::ostream& os, const Car& rhs)
{
    os << "name: " << rhs.getName() << std::endl;
    os << "speed: " << rhs.getSpeed() << std::endl;

    return os;
}
