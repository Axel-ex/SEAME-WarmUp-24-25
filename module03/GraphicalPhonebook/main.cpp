#include "PhoneBook.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Phonebook w;
    w.show();
    return a.exec();
}
