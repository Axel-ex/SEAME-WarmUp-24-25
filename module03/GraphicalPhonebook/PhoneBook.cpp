#include "PhoneBook.hpp"
#include "ContactEdit.hpp"
#include "ui_mainwindow.h"

Phonebook::Phonebook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // Connect the buttons to their respective slots
    connect(ui->pushButton, &QPushButton::clicked, this, &Phonebook::addContact);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Phonebook::editContact);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Phonebook::deleteContact);

    updateContactCount();
}

Phonebook::~Phonebook()
{
    delete ui;
}

// Add a new contact to the table
void Phonebook::addContact()
{
    ContactEdit contactDialog(this);
    if (contactDialog.exec() == QDialog::Accepted) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // Get data from the ContactEdit dialog and populate the new row
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(contactDialog.getFirstName()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(contactDialog.getLastName()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(contactDialog.getPhoneNumber()));

        updateContactCount();
    }
}

// Edit an existing contact
void Phonebook::editContact()
{
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        // Create the dialog and pre-fill with current contact data
        ContactEdit contactDialog(this);
        contactDialog.setFirstName(ui->tableWidget->item(row, 0)->text());
        contactDialog.setLastName(ui->tableWidget->item(row, 1)->text());
        contactDialog.setPhoneNumber(ui->tableWidget->item(row, 2)->text());

        // Open the dialog and update the table if the user accepts
        if (contactDialog.exec() == QDialog::Accepted) {
            ui->tableWidget->item(row, 0)->setText(contactDialog.getFirstName());
            ui->tableWidget->item(row, 1)->setText(contactDialog.getLastName());
            ui->tableWidget->item(row, 2)->setText(contactDialog.getPhoneNumber());
        }
    }
}

// Delete the selected contact
void Phonebook::deleteContact()
{
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        ui->tableWidget->removeRow(row);
        updateContactCount();
    }
}

// Update the LCD display to show the total number of contacts
void Phonebook::updateContactCount()
{
    int count = ui->tableWidget->rowCount();
    ui->lcdNumber->display(count);
}
