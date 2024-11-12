#include "mainwindow.h"

#include "Phonebook.hpp"
#include <QApplication>
#include <QtCore/qobject.h>

int main(int argc, char* argv[])
{
    PhoneBook phonebook;

    QApplication a(argc, argv);
    MainWindow w(nullptr, &phonebook);
    w.show();
    return a.exec();
}
