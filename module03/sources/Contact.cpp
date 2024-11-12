#include "../includes/Contact.hpp"
#include <iostream>

Contact::Contact(const std::string& name, const std::string& nickname,
                 const std::string& phone_nb)
    : _name(name), _phone_nb(phone_nb), _nickname(nickname)
{
}

Contact::~Contact(void) {}

const std::string& Contact::getName(void) const { return _name; }

const std::string& Contact::getNickname(void) const { return _nickname; }

const std::string& Contact::getPhoneNb(void) const { return _phone_nb; }

std::ostream& operator<<(std::ostream& ofs, const Contact& contact)
{
    ofs << "name: " << contact.getName() << std::endl;
    ofs << "nickname: " << contact.getNickname() << std::endl;
    ofs << "phone number: " << contact.getPhoneNb() << std::endl;
    ofs << std::endl;

    return ofs;
}
