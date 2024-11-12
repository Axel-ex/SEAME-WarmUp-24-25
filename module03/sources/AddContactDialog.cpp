#include "AddContactDialog.hpp"
#include <QLabel>
#include <QVBoxLayout>
#include <QtCore/qobject.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qdialog.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qpushbutton.h>

AddContactDialog::AddContactDialog(QWidget* parent) : QDialog(parent)
{
    // init the entities and make sure they have a parent for memory management.
    _nameEdit = new QLineEdit(this);
    _phonenumberEdit = new QLineEdit(this);
    _nicknameEdit = new QLineEdit(this);
    _submit = new QPushButton(this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Name:"));
    layout->addWidget(_nameEdit);
    layout->addWidget(new QLabel("Phone:"));
    layout->addWidget(_phonenumberEdit);
    layout->addWidget(new QLabel("nickname:"));
    layout->addWidget(_nicknameEdit);
    layout->addWidget(_submit);

    connect(_submit, &QPushButton::clicked, this,
            &AddContactDialog::onConfirmButtonClicked);
}

void AddContactDialog::onConfirmButtonClicked()
{
    // Create a Contact object with the entered data
    Contact contact(_nameEdit->text().toStdString(),
                    _phonenumberEdit->text().toStdString(),
                    _nicknameEdit->text().toStdString());

    // Emit the signal with the new contact
    emit contactDataEntered(contact);

    // Close the dialog
    accept();
}

void AddContactDialog::accept()
{
    // perform the logic here before accepting.
    QDialog::accept();
}
