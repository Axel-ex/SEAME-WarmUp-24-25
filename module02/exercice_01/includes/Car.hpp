#pragma once
#include "Break.hpp"
#include "Engine.hpp"
#include "Transmission.hpp"
#include "Wheel.hpp"

class Car
{
    public:
        Car();
        Car(Car&&);
        Car(const Car&);
        Car& operator=(Car&&);
        Car& operator=(const Car&);
        ~Car();

        void printParts(void) const;

        // getters for tests
        Engine* getEngine(void);
        Transmission* getTransmission(void);
        Break* getBreaks(void);
        Wheel* getWheels(void);

    private:
        Engine* _engine;
        Transmission* _transmission;
        Break* _breaks;
        Wheel* _wheels;
};
