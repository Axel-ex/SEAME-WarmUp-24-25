#include <cstring>
#include <iostream>
#include <string>

void print_usage(void)
{
    std::cout << "Invalid number of arguments provided: ./convert "
              << std::endl;
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv)
{
    if (argc <= 3)
        print_usage();

    std::string command = argv[1];
    std::string str = argv[2];

    for (int i = 3; i < argc; i++)
        str += " " + std::string(argv[i]);

    if (command == "up" || command == "down")
    {
        if (command == "up")
            for (char letter : str)
                std::cout << static_cast<char>(std::toupper(letter));
        else if (command == "down")
            for (char letter : str)
                std::cout << static_cast<char>(std::tolower(letter));
        std::cout << std::endl;
    }
    else
        std::cout << "Error: unrecognized command" << std::endl;
}
