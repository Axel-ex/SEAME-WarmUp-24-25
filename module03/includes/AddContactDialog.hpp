#pragma once

#include "Contact.hpp"
#include "QDialog"
#include <QLineEdit>
#include <QObject>
#include <QPushButton>
#include <QWidget>

class AddContactDialog : public QDialog
{

        Q_OBJECT

    public:
        AddContactDialog(QWidget* parent = nullptr);
        ~AddContactDialog() = default;

        void accept() override;

    signals:
        void contactDataEntered(const Contact& contact);

    public slots:
        void onConfirmButtonClicked();

    private:
        QLineEdit* _nameEdit;
        QLineEdit* _phonenumberEdit;
        QLineEdit* _nicknameEdit;
        QPushButton* _submit;
};
