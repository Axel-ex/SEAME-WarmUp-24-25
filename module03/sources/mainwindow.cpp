#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "AddContactDialog.hpp"
#include "Contact.hpp"
#include "Phonebook.hpp"
#include <QMessageBox>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qitemselectionmodel.h>
#include <QtCore/qobject.h>
#include <QtGui/qstandarditemmodel.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qpushbutton.h>

MainWindow::MainWindow(QWidget* parent, PhoneBook* phonebook)
    : QMainWindow(parent), ui(new Ui::MainWindow), _phonebook(phonebook)
{
    ui->setupUi(this);

    // Initialize QStandardItemModel with col header
    _contactModel = new QStandardItemModel(this);
    _contactModel->setHorizontalHeaderLabels({"Name", "Phone number", "Email"});

    // set the model for the QTableView
    ui->contactList->setModel(_contactModel);

    // Connect the button's clicked() signal to slots of the MainWindow object
    connect(ui->addButton, &QPushButton::clicked, this,
            &MainWindow::onAddButtonClicked);
    connect(ui->removeButton, &QPushButton::clicked, this,
            &MainWindow::onRemoveButtonClicked);

    // connect the signals of the mainWindow object to the corresponding slots
    // of the phonebook
    connect(this, &MainWindow::addContactSignal, _phonebook,
            &PhoneBook::addContact);
    connect(this, &MainWindow::removeContactSignal, _phonebook,
            &PhoneBook::removeContact);

    // connect the phonebook response signals to teh corresponding slots in
    // maiwindow
    connect(phonebook, &PhoneBook::contactAdded, this,
            &MainWindow::onAddContact);
    connect(phonebook, &PhoneBook::contactRemoved, this,
            &MainWindow::onRemoveContact);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::onAddButtonClicked()
{
    // Create the AddContactDialog
    AddContactDialog dialog(this);

    // Connect the dialog’s contactDataEntered signal to MainWindow's
    // onContactDataEntered slot
    connect(&dialog, &AddContactDialog::contactDataEntered, _phonebook,
            &PhoneBook::addContact);

    // Display the dialog as a modal window
    dialog.exec();
}

void MainWindow::onRemoveButtonClicked()
{
    QItemSelectionModel* selectionModel = ui->contactList->selectionModel();
    QModelIndexList selectedRows = selectionModel->selectedRows();

    if (selectedRows.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "No data selected");
        return;
    }

    QModelIndex index = selectedRows.first();
    QString contactName = _contactModel->item(index.row(), 0)->text();

    emit removeContactSignal(contactName);
}

void MainWindow::onAddContact(const Contact& contact)
{
    QMessageBox::information(this, "Contact Added",
                             "The contact has been successfully added!");
    // add contact to the list displayed on screen
    _addContactToModel(contact);
}

void MainWindow::onRemoveContact(const QString& name)
{
    // Remove the selected row from the table view
    QItemSelectionModel* selectionModel = ui->contactList->selectionModel();
    QModelIndexList selectedRows = selectionModel->selectedRows();

    if (!selectedRows.isEmpty())
    {
        _contactModel->removeRow(selectedRows.first().row());
    }
}

void MainWindow::_addContactToModel(const Contact& contact)
{
    QList<QStandardItem*> rowItems;
    rowItems << new QStandardItem(QString::fromStdString(contact.getName()));
    rowItems << new QStandardItem(
        QString::fromStdString(contact.getNickname()));
    rowItems << new QStandardItem(QString::fromStdString(contact.getPhoneNb()));

    _contactModel->appendRow(rowItems);
}
