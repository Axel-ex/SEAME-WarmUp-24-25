#pragma once

#include <string>

#define CLEAR "\033[2J\033[1;1H"
#define RED "\033[38;5;196m"
#define YELLOW "\033[38;5;226m"
#define RESET "\033[0m"

namespace Formatter
{
void clearScreen(void);
void printMenu(void);
void printBaner(const std::string& title);
void pressEnter(void);
void printError(const std::string& message);

} // namespace Formatter
