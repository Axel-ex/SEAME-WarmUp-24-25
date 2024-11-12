#ifndef CONTACTEDIT_HPP
#define CONTACTEDIT_HPP

#include <QDialog>

namespace Ui {
class ContactEdit;
}

class ContactEdit : public QDialog
{
    Q_OBJECT

public:
    explicit ContactEdit(QWidget *parent = nullptr);
    ~ContactEdit();

    // Getter methods to retrieve user input
    QString getFirstName() const;
    QString getLastName() const;
    QString getPhoneNumber() const;

    // Setter methods to pre-fill the form for editing
    void setFirstName(const QString &firstName);
    void setLastName(const QString &lastName);
    void setPhoneNumber(const QString &phoneNumber);

private:
    Ui::ContactEdit *ui;
};

#endif // CONTACTEDIT_HPP
