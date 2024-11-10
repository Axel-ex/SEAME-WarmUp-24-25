#pragma once

#include "../includes/Contact.hpp"
#include <string>
#include <vector>

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void execute(const std::string& command);

    private:
        std::vector<Contact> _contacts;
        std::vector<Contact> _bookmarked;

        // COMMAND
        void _add(void);
        void _search(void);
        void _remove(void);
        void _bookmark(void);

        // CHECKS
        bool _isInteger(const std::string& str);
        bool _isValidContact(const Contact& contact) const;
        bool _isValidIndex(size_t index) const;
        bool _isValidPhoneNumber(const std::string& phone_nb) const;
        void _removeContact(std::vector<Contact>::iterator it);
};
