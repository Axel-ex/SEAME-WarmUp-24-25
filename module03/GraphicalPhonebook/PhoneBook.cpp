#include "PhoneBook.hpp"
#include "ContactEdit.hpp"
#include "ui_mainwindow.h"
#include <QMessageBox>

Phonebook::Phonebook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // connections
    connect(ui->pushButton, &QPushButton::clicked, this, &Phonebook::addContact);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Phonebook::editContact);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Phonebook::deleteContact);

    updateContactCount();
}

Phonebook::~Phonebook()
{
    delete ui;
}

void Phonebook::addContact() {
    ContactEdit contactDialog(this);

    if (contactDialog.exec() == QDialog::Accepted) {
        QString firstName = contactDialog.getFirstName();
        QString lastName = contactDialog.getLastName();
        QString phoneNumber = contactDialog.getPhoneNumber();

        if (isPhoneNumberDuplicate(phoneNumber)) {
            QMessageBox::warning(this, "Validation Error", "Phone number is already in use.");
            return;
        }

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(firstName));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(lastName));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(phoneNumber));

        updateContactCount();
    }
}

void Phonebook::editContact() {
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {

        ContactEdit contactDialog(this);
        contactDialog.setFirstName(ui->tableWidget->item(row, 0)->text());
        contactDialog.setLastName(ui->tableWidget->item(row, 1)->text());
        contactDialog.setPhoneNumber(ui->tableWidget->item(row, 2)->text());

        if (contactDialog.exec() == QDialog::Accepted) {
            QString newPhoneNumber = contactDialog.getPhoneNumber();
            QString currentPhoneNumber = ui->tableWidget->item(row, 2)->text();

            if (newPhoneNumber != currentPhoneNumber && isPhoneNumberDuplicate(newPhoneNumber)) {
                QMessageBox::warning(this, "Validation Error", "Phone number is already in use.");
                return;
            }

            ui->tableWidget->item(row, 0)->setText(contactDialog.getFirstName());
            ui->tableWidget->item(row, 1)->setText(contactDialog.getLastName());
            ui->tableWidget->item(row, 2)->setText(contactDialog.getPhoneNumber());
        }
    }
}

void Phonebook::deleteContact()
{
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        ui->tableWidget->removeRow(row);
        updateContactCount();
    }
}

bool Phonebook::isPhoneNumberDuplicate(const QString &phoneNumber) {
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        QTableWidgetItem* item = ui->tableWidget->item(i, 2);
        if (item && item->text() == phoneNumber) {
            return true;  // duplicate found
        }
    }
    return false;
}

void Phonebook::updateContactCount()
{
    int count = ui->tableWidget->rowCount();
    ui->lcdNumber->display(count);
}
