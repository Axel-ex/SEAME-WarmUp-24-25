#include "Car.hpp"
#include "Break.hpp"
#include "Engine.hpp"
#include "Transmission.hpp"

Car ::Car(void)
{
    _engine = new Engine();
    _transmission = new Transmission();
    _breaks = new Break[4];
    _wheels = new Wheel[4];
}

Car ::~Car(void)
{
    delete _engine;
    delete _transmission;
    delete[] _breaks;
    delete[] _wheels;
}

// Copy constructor (deep copy)
Car::Car(const Car& to_copy)
    : _engine(new Engine(*to_copy._engine)),
      _transmission(new Transmission(*to_copy._transmission)),
      _breaks(new Break[4]), _wheels(new Wheel[4])
{
    for (int i = 0; i < 4; ++i)
    {
        _breaks[i] = to_copy._breaks[i];
        _wheels[i] = to_copy._wheels[i];
    }
}

// Move constructor (shallow transfer)
Car::Car(Car&& to_move) noexcept
    : _engine(to_move._engine), _transmission(to_move._transmission),
      _breaks(to_move._breaks), _wheels(to_move._wheels)
{
    to_move._engine = nullptr;
    to_move._transmission = nullptr;
    to_move._breaks = nullptr;
    to_move._wheels = nullptr;
}

// Copy assignment
Car& Car::operator=(const Car& to_copy)
{
    if (this == &to_copy)
        return *this;

    // Release current resources
    delete _engine;
    delete _transmission;
    delete[] _breaks;
    delete[] _wheels;

    _engine = new Engine(*to_copy._engine);
    _transmission = new Transmission(*to_copy._transmission);
    _breaks = new Break[4];
    _wheels = new Wheel[4];

    for (int i = 0; i < 4; i++)
    {
        _breaks[i] = to_copy._breaks[i];
        _wheels[i] = to_copy._wheels[i];
    }

    return *this;
}

// Move assignment
Car& Car::operator=(Car&& to_move) noexcept
{
    if (this == &to_move)
        return *this;

    // Release current resources
    delete _engine;
    delete _transmission;
    delete[] _breaks;
    delete[] _wheels;

    _engine = to_move._engine;
    _transmission = to_move._transmission;
    _breaks = to_move._breaks;
    _wheels = to_move._wheels;

    to_move._engine = nullptr;
    to_move._transmission = nullptr;
    to_move._breaks = nullptr;
    to_move._wheels = nullptr;

    return *this;
}

void Car::printParts(void) const
{
    if (_engine)
        _engine->print();
    if (_transmission)
        _transmission->print();
    if (_breaks)
        for (int i = 0; i < 4; i++)
            _breaks[i].print();
    if (_wheels)
        for (int i = 0; i < 4; i++)
            _wheels[i].print();
}

// Getters
Engine* Car::getEngine(void) { return _engine; }

Transmission* Car::getTransmission(void) { return _transmission; }

Break* Car::getBreaks(void) { return _breaks; }

Wheel* Car::getWheels(void) { return _wheels; }
