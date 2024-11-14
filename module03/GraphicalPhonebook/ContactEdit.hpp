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

    QString getFirstName() const;
    QString getLastName() const;
    QString getPhoneNumber() const;

    void setFirstName(const QString &firstName);
    void setLastName(const QString &lastName);
    void setPhoneNumber(const QString &phoneNumber);

private slots:
    void onAccept();

private:
    Ui::ContactEdit *ui;

    bool validateFirstName();
    bool validatePhoneNumber();
};

#endif // CONTACTEDIT_HPP
