#pragma once

#include "APart.hpp"

class Transmission : APart
{
    public:
        Transmission() = default;
        Transmission(Transmission&&) = default;
        Transmission(const Transmission&) = default;
        Transmission& operator=(Transmission&&) = default;
        Transmission& operator=(const Transmission&) = default;
        ~Transmission() = default;

        void print(void) const override;
};
