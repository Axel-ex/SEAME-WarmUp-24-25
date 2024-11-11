#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Formatter.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <regex>
#include <string>

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

/**
 * @brief match a command with the appropriated method
 *
 * @param command
 */
void PhoneBook::execute(const std::string& command)
{
    if (command == "ADD")
        _add();
    else if (command == "SEARCH")
        _search();
    else if (command == "BOOKMARK")
        _bookmark();
    else if (command == "REMOVE")
        _remove();
    else
    {
        Formatter::printError("Invalid command");
        Formatter::pressEnter();
    }
}

/**
 * @brief adds a contact if valid
 */
void PhoneBook::_add(void)
{
    std::string name, nickname, phone_number;

    Formatter::clearScreen();
    Formatter::printBaner("ADD");

    std::cout << "Enter the name: ";
    std::getline(std::cin, name);
    std::cout << "Enter a nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter a phone number: ";
    std::getline(std::cin, phone_number);

    Contact new_contact = Contact(name, nickname, phone_number);
    if (!_isValidContact(new_contact))
    {
        Formatter::pressEnter();
        return;
    }

    _contacts.push_back(Contact(name, nickname, phone_number));
    std::cout << "Contact " << name << " succefully created" << std::endl;
    Formatter::pressEnter();
}

/**
 * @brief display all contacts and all informations of a selected contact.
 */
void PhoneBook::_search(void)
{
    Formatter::clearScreen();
    Formatter::printBaner("SEARCH");

    // display all contacts
    for (size_t i = 0; i < _contacts.size(); i++)
        std::cout << i << " - " << _contacts[i].getName() << std::endl;
    std::cout << "Enter the index of the contact you want to look up"
              << std::endl;
    std::string index_str;
    std::getline(std::cin, index_str);
    size_t index = std::atoi(index_str.c_str());

    // display selected contact if exist
    if (_isValidIndex(index))
    {
        Formatter::clearScreen();
        Formatter::printBaner("CONTACT");
        std::cout << _contacts[index] << std::endl;
    }
    else
    {
        Formatter::printError("Invalid index");
        Formatter::pressEnter();
        return;
    }

    // Prompt for bookmarking
    std::cout << "Would you like to mark this contact as bookmark? y-n"
              << std::endl;
    std::string answer;
    std::getline(std::cin, answer);
    if (answer == "y")
        _bookmarked.push_back(_contacts[index]);
    Formatter::pressEnter();
}

/**
 * @brief Remove a contact by index or phone number.
 */
void PhoneBook::_remove(void)
{
    std::string input;

    Formatter::clearScreen();
    Formatter::printBaner("REMOVE");
    std::cout
        << "Enter the index or phone number of the contact you want to remove:"
        << std::endl;
    std::getline(std::cin, input);

    // Check if the input is a phone number
    if (_isValidPhoneNumber(input))
    {
        // Find and remove by phone number
        auto it = std::find_if(_contacts.begin(), _contacts.end(),
                               [&](const Contact& contact)
                               { return contact.getPhoneNb() == input; });

        if (it != _contacts.end())
            _removeContact(it);
        else
        {
            Formatter::printError("Phone number not found");
            Formatter::pressEnter();
        }
        return;
    }

    // Treat input as index and remove if valid
    size_t index = std::atoi(input.c_str());
    if (_isValidIndex(index) && _isInteger(input))
        _removeContact(_contacts.begin() + index);
    else
    {
        Formatter::printError("Invalid index");
        Formatter::pressEnter();
    }
}

/**
 * @brief Display bookmarked contacts
 */
void PhoneBook::_bookmark(void)
{
    Formatter::clearScreen();
    Formatter::printBaner("BOOKMARK");

    for (size_t i = 0; i < _bookmarked.size(); i++)
        std::cout << i << " - " << _bookmarked[i].getName() << std::endl;

    Formatter::pressEnter();
}

/**
 * @brief Validate a contact. check for empty name, invalid phone number format
 * and duplicate phone number.
 *
 * @param new_contact
 * @return
 */
bool PhoneBook::_isValidContact(const Contact& new_contact) const
{
    const std::regex phone_pattern(R"(^\d{9}$)");

    if (new_contact.getName().empty())
    {
        Formatter::printError("An empty name is not allowed");
        return false;
    }
    if (!std::regex_match(new_contact.getPhoneNb(), phone_pattern))
    {
        Formatter::printError("Invalid phone number format");
        return false;
    }
    for (auto contact : _contacts)
    {
        if (contact.getPhoneNb() == new_contact.getPhoneNb())
        {
            Formatter::printError(
                "The phone number you entered already exists");
            return false;
        }
    }
    return true;
}

/**
 * @brief Check if the input is a 9-digit phone number.
 */
bool PhoneBook::_isValidPhoneNumber(const std::string& input) const
{
    const std::regex phone_pattern(R"(^\d{9}$)");
    return std::regex_match(input, phone_pattern);
}

bool PhoneBook::_isValidIndex(size_t index) const
{
    return index < _contacts.size();
}

/**
 * @brief Remove contact by iterator and print success message.
 */
void PhoneBook::_removeContact(std::vector<Contact>::iterator it)
{
    std::string contact_name = it->getName();
    _contacts.erase(it);

    // Find and remove the contact from the bookmarked list
    auto bookmarked_it = std::find_if(
        _bookmarked.begin(), _bookmarked.end(), [&](const Contact& contact)
        { return contact.getName() == contact_name; });

    if (bookmarked_it != _bookmarked.end())
        _bookmarked.erase(bookmarked_it);

    std::cout << contact_name << " successfully deleted!" << std::endl;
    Formatter::pressEnter();
}

// Check if input is a valid integer
bool PhoneBook::_isInteger(const std::string& str)
{
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}
