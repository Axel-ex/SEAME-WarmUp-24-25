#include "Sportscar.hpp"
#include <cstdlib>
#include <memory> // For smart pointers

// Memory leak: the pointer was allocated but not freed
// Dangling pointer: the pointer was freed but not nullified. It still points to
// a memory location that was deallocated.

int main(void)
{
    // Memory Leak Example (using raw pointer, manually allocating memory)
    SportsCar* my_car = new SportsCar("Tesla", "S", "2024");
    my_car->drive(); // Calling a method on the raw pointer

    // Memory leak: if we did not call delete, so the memory allocated to
    // 'my_car' is never freed.
    delete my_car;

    // Dangling Pointer Example (using raw pointer)
    // After calling delete, the memory is freed, but 'my_car' is still pointing
    // to that invalid memory. Uncommenting the following lines would cause
    // undefined behavior (dangling pointer).
    // my_car->drive();
    // Accessing a deleted pointer leads to undefined behavior.

    // Using Smart Pointer to Avoid Memory Leaks and Dangling Pointers
    // std::unique_ptr automatically deletes the object when it goes out of
    // scope.
    std::unique_ptr<SportsCar> smart_car =
        std::make_unique<SportsCar>("Ferrari", "488", "2022");

    // Smart pointer calls drive() just like a raw pointer, but it automatically
    // handles memory management.
    smart_car->drive(); // Calls method on the unique pointer

    // No need to call delete. 'smart_car' will automatically clean up memory
    // when it goes out of scope.

    return EXIT_SUCCESS;
}
