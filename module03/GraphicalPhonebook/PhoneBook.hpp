#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class Phonebook : public QMainWindow
{
    Q_OBJECT

public:
    explicit Phonebook(QWidget *parent = nullptr);
    bool isPhoneNumberDuplicate(const QString &phoneNumber);
    ~Phonebook();

private slots:
    void addContact();
    void editContact();
    void deleteContact();

private:
    Ui::MainWindow *ui;

    void updateContactCount();
};

#endif // PHONEBOOK_HPP
