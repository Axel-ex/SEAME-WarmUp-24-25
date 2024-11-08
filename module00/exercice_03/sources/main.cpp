#include "Formatter.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

int main(void)
{
    PhoneBook phonebook;

    while (true)
    {
        Formatter::clearScreen();
        Formatter::printBaner("PHONEBOOK");
        Formatter::printMenu();
        std::string command;

        if (!std::getline(std::cin, command))
        { // Check for EOF or input failure
            std::cout << "\nEOF detected. Exiting phonebook." << std::endl;
            break;
        }
        if (command == "EXIT")
            break;

        phonebook.execute(command);
    }

    return EXIT_SUCCESS;
}
