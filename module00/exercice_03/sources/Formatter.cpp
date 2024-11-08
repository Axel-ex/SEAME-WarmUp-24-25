#include "Formatter.hpp"
#include <iostream>
#include <string>

void Formatter::clearScreen() { std::cout << CLEAR; }

void Formatter::printBaner(const std::string& title)
{
    int width = 50;
    int padding = (width - title.size() - 2) / 2;
    if (padding < 0)
        padding = 0;

    std::cout << std::string(width, '*') << std::endl;

    std::cout << '*' << std::string(padding, ' ') << title
              << std::string(width - title.size() - padding - 2, ' ') << '*'
              << std::endl;
    std::cout << std::string(width, '*') << std::endl;
}

void Formatter::printMenu()
{
    std::cout << "Enter one of the following command: " << std::endl;
    std::cout << "\t- SEARCH\n\t- ADD\n\t- REMOVE\n\t- BOOKMARK\n\t- EXIT\n";
}

void Formatter::pressEnter(void)
{
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore(10000, '\n');
    clearScreen();
}

void Formatter::printError(const std::string& message)
{
    std::cerr << RED << "Error: " << RESET << message << std::endl;
}
