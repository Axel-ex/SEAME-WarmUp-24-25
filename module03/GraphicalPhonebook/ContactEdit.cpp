#include "ContactEdit.hpp"
#include "ui_contactedit.h"

ContactEdit::ContactEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactEdit)
{
    ui->setupUi(this);

    // Connect the dialog's buttonBox to accept and reject signals
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

ContactEdit::~ContactEdit()
{
    delete ui;
}

// Getter methods
QString ContactEdit::getFirstName() const {
    return ui->textEdit->toPlainText();
}

QString ContactEdit::getLastName() const {
    return ui->textEdit_2->toPlainText();
}

QString ContactEdit::getPhoneNumber() const {
    return ui->textEdit_3->toPlainText();
}

// Setter methods to pre-fill form fields for editing
void ContactEdit::setFirstName(const QString &firstName) {
    ui->textEdit->setText(firstName);
}

void ContactEdit::setLastName(const QString &lastName) {
    ui->textEdit_2->setText(lastName);
}

void ContactEdit::setPhoneNumber(const QString &phoneNumber) {
    ui->textEdit_3->setText(phoneNumber);
}
