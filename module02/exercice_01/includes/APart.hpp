#pragma once

class APart
{
    public:
        APart();                                 // Default constructor
        APart(APart&& to_move) = default;        // Move constructor
        APart(const APart& to_copy) = default;   // Copy constructor
        APart& operator=(APart&& rhs) = default; // Move assignment operator
        APart&
        operator=(const APart& rhs) = default; // Copy assignment operator
        virtual ~APart(); // Virtual destructor for polymorphic cleanup

        virtual void
        print() const = 0; // Pure virtual function for derived classes
};
