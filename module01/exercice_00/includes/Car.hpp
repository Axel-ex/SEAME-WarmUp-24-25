#pragma once

#include <ostream>
#include <string>

/**
 * @class Car
 * @brief Represents a car with a name and speed, implementing the "rule of
 * five" for efficient resource management and transfer of ownership.
 *
 * This class manages `std::string` resources for the car's name and speed,
 * using the rule of five to handle copying and moving in a
 * performance-conscious way:
 *
 * - **Copy Constructor**: Allows a new `Car` instance to be created as a copy
 * of another, duplicating the name and speed strings.
 *
 * - **Move Constructor** (noexcept): Transfers resources from a temporary `Car`
 *   (rvalue) to a new instance. Uses `std::move` to avoid deep copying,
 * improving efficiency especially with large strings.
 *
 * - **Copy Assignment Operator**: Assigns the name and speed of one `Car`
 * instance to another, carefully handling self-assignment and ensuring deep
 * copying of the strings.
 *
 * - **Move Assignment Operator**: Transfers ownership of resources from a
 * temporary `Car` to an existing instance. Nullifies the moved-from object's
 * state to maintain consistency and avoid double-free errors.
 *
 * - **Destructor**: Cleans up resources automatically when the `Car` object
 * goes out of scope, with `std::string` members cleaned up automatically.
 *
 * In this context, `&&` represents an rvalue reference, typically referring to
 * a temporary object. Move operations accepting rvalue references allow
 * efficient resource transfer without deep copying, which is useful when
 * dealing with resource-heavy data types.
 */

class Car
{
    public:
        Car(); // default constructor
        Car(const std::string& name, const std::string& speed);
        Car(Car&&) noexcept;            // move constructor
        Car(const Car&);                // copy constructor
        Car& operator=(Car&&) noexcept; // move assignement op
        Car& operator=(const Car&);     // copy assignment op
        ~Car();

        const std::string& getName(void) const;
        const std::string& getSpeed(void) const;

    private:
        std::string _name;
        std::string _speed;
};

std::ostream& operator<<(std::ostream& os, const Car& rhs);
