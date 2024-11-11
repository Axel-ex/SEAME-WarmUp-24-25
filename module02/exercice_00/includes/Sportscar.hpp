#pragma once

#include "Car.hpp"

class SportsCar : public Car
{
    public:
        SportsCar();
        SportsCar(const std::string& make, const std::string& model,
                  const std::string& year);
        SportsCar(SportsCar&&) = default;
        SportsCar(const SportsCar&) = default;
        SportsCar& operator=(SportsCar&&) = default;
        SportsCar& operator=(const SportsCar&) = default;
        ~SportsCar() = default;

        void drive(void) const override;

    private:
        int _top_speed;
};
