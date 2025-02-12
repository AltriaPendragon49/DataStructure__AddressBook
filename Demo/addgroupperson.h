#ifndef ADDGROUPPERSON_H
#define ADDGROUPPERSON_H

#include <QWidget>

namespace Ui {
class addgroupperson;
}

class addgroupperson : public QWidget
{
    Q_OBJECT

public:
    explicit addgroupperson(QWidget *parent = nullptr);
    ~addgroupperson();

private slots:
    void on_ok_clicked();
    void on_quit_clicked();
    QString gettextBefore();
    QString gettextAfter();

private:
    Ui::addgroupperson *ui;
};

#endif // ADDGROUPPERSON_H
