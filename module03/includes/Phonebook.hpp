#pragma once

#include "Contact.hpp"
#include <QObject>
#include <QtCore/qobject.h>
#include <QtCore/qtmetamacros.h>
#include <vector>

class PhoneBook : public QObject
{
        Q_OBJECT

    public:
        PhoneBook() = default;
        ~PhoneBook() = default;

    public slots:
        void addContact(const Contact& contact);
        void removeContact(const QString& name);

    signals:
        void contactAdded(const Contact& contact);
        void contactRemoved(const QString& name);

    private:
        std::vector<Contact> _contacts;
};
