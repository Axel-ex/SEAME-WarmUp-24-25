#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <QMainWindow>
#include <QStandardItemModel>
#include <QtCore/qobject.h>
#include <QtGui/qstandarditemmodel.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        MainWindow(QWidget* parent, PhoneBook* phonebooK);
        ~MainWindow();

    private slots:
        void onAddButtonClicked();
        void onRemoveButtonClicked();

        void onAddContact(const Contact& contact);
        void onRemoveContact(const QString& name);

    signals:
        void addContactSignal(const Contact& new_contact);
        void removeContactSignal(const QString& name);

    private:
        Ui::MainWindow* ui;
        PhoneBook* _phonebook;
        QStandardItemModel* _contactModel;

        void _addContactToModel(const Contact& contact);
};
#endif // MAINWINDOW_H
