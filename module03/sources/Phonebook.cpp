#include "Phonebook.hpp"
#include <QtCore/qobject.h>

void PhoneBook ::addContact(const Contact& contact)
{
    _contacts.push_back(contact);
    emit contactAdded(contact);
}

void PhoneBook::removeContact(const QString& name)
{
    auto it = std::find_if(_contacts.begin(), _contacts.end(),
                           [&name](const Contact& contact)
                           { return contact.getName() == name; });

    if (it != _contacts.end())
    {
        _contacts.erase(it);
        emit contactRemoved(name);
    }
}
