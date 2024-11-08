#pragma once

#include "APart.hpp"

class Wheel : public APart
{
    public:
        Wheel() = default;
        Wheel(Wheel&&) = default;
        Wheel(const Wheel&) = default;
        Wheel& operator=(Wheel&&) = default;
        Wheel& operator=(const Wheel&) = default;
        ~Wheel() = default;

        void print(void) const override;
};
