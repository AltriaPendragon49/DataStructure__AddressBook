#ifndef ADDCONTACT_H
#define ADDCONTACT_H

#include <QWidget>

namespace Ui {
class addContact;
}

class addContact : public QWidget
{
    Q_OBJECT

public:
    explicit addContact(QWidget *parent = nullptr);
    ~addContact();

private:
    Ui::addContact *ui;
};

#endif // ADDCONTACT_H
