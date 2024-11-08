#pragma once

#include "APart.hpp"

class Break : public APart
{
    public:
        Break() = default;
        Break(Break&&) = default;
        Break(const Break&) = default;
        Break& operator=(Break&&) = default;
        Break& operator=(const Break&) = default;
        ~Break() = default;

        void print(void) const override;
};
