#pragma once

#include <ostream>
#include <string>

class Car
{
    public:
        Car(); // default constructor
        Car(const std::string& make, const std::string& model,
            const std::string& year);
        Car(Car&&) noexcept;            // move constructor
        Car(const Car&);                // copy constructor
        Car& operator=(Car&&) noexcept; // move assignement op
        Car& operator=(const Car&);     // copy assignment op
        virtual ~Car();

        const std::string& getMake(void) const;
        const std::string& getModel(void) const;
        const std::string& getYear(void) const;

        virtual void drive(void) const;

    private:
        std::string _make;
        std::string _model;
        std::string _year;
};

std::ostream& operator<<(std::ostream& os, const Car& rhs);
