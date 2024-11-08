#include "Car.hpp"
#include <iostream>

Car::Car(void) { std::cout << "Car default constructor called" << std::endl; }
Car::~Car(void) { std::cout << "Car destructor called" << std::endl; }

Car::Car(const std::string& make, const std::string& model,
         const std::string& year)
    : _make(make), _model(model), _year(year)
{
    std::cout << "Car constructor called" << std::endl;
}

// Move constructor
Car::Car(Car&& to_move) noexcept
    : _make(std::move(to_move._make)), _model(std::move(to_move._model)),
      _year(std::move(to_move._year))
{
    std::cout << "Car move constructor called" << std::endl;
    // Set the moved-from object to a neutral state
    to_move._make = "";
    to_move._model = "";
    to_move._year = "";
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
    _make = rhs._make;
    _model = rhs._model;
    _year = rhs._year;
    return *this;
}

Car& Car::operator=(Car&& rhs) noexcept
{
    if (this == &rhs)
        return *this;

    std::cout << "Car move assignement called" << std::endl;
    _make = std::move(rhs._make);
    _model = std::move(rhs._model);
    _year = std::move(rhs._year);

    rhs._make = "";
    rhs._model = "";
    rhs._year = "";

    return *this;
}

void Car::drive(void) const
{
    std::cout << "Driving " << _make << " " << _model << " " << _year
              << std::endl;
}

// GETTERS
const std::string& Car::getMake(void) const { return _make; }

const std::string& Car::getModel(void) const { return _model; }

const std::string& Car::getYear(void) const { return _year; }

std::ostream& operator<<(std::ostream& os, const Car& rhs)
{
    os << "make: " << rhs.getMake() << std::endl;
    os << "model: " << rhs.getModel() << std::endl;
    os << "year: " << rhs.getYear() << std::endl;

    return os;
}
