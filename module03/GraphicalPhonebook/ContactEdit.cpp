#include "ContactEdit.hpp"
#include "ui_contactedit.h"
#include <QMessageBox>

ContactEdit::ContactEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactEdit)
{
    ui->setupUi(this);

    // Manually handle the acceptance of the dialog
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &ContactEdit::onAccept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

ContactEdit::~ContactEdit()
{
    delete ui;
}

QString ContactEdit::getFirstName() const {
    return ui->textEdit->toPlainText();
}

QString ContactEdit::getLastName() const {
    return ui->textEdit_2->toPlainText();
}

QString ContactEdit::getPhoneNumber() const {
    return ui->textEdit_3->toPlainText();
}

void ContactEdit::setFirstName(const QString &firstName) {
    ui->textEdit->setText(firstName);
}

void ContactEdit::setLastName(const QString &lastName) {
    ui->textEdit_2->setText(lastName);
}

void ContactEdit::setPhoneNumber(const QString &phoneNumber) {
    ui->textEdit_3->setText(phoneNumber);
}

void ContactEdit::onAccept()
{
    if (!validateFirstName()) {
        QMessageBox::warning(this, "Validation Error", "First name can't be empty!");
        reject();
        return;
    }

    if (!validatePhoneNumber()) {
        QMessageBox::warning(this, "Validation Error", "Invalid Phone Number!");
        reject();
        return;
    }
    accept();
}

bool ContactEdit::validateFirstName()
{
    return !getFirstName().trimmed().isEmpty();
}

bool ContactEdit::validatePhoneNumber() {
    QString phoneNumber = getPhoneNumber().trimmed();

    if (phoneNumber.isEmpty()) {
        return false;
    }

    bool isValid = phoneNumber.toInt() != 0 || phoneNumber == "0";

    return isValid;
}

