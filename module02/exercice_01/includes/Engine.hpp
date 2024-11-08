#pragma once

#include "APart.hpp"

class Engine : public APart
{
    public:
        Engine() = default;
        Engine(Engine&& to_copy) = default;
        Engine(const Engine& to_copy) = default;
        Engine& operator=(Engine&& rhs) = default;
        Engine& operator=(const Engine& rhs) = default;
        ~Engine() = default;

        void print(void) const override;
};
