#ifndef MODPEOPLEADDRESS_H
#define MODPEOPLEADDRESS_H

#include <QWidget>

namespace Ui {
class modpeopleaddress;
}

class modpeopleaddress : public QWidget
{
    Q_OBJECT

public:
    explicit modpeopleaddress(QWidget *parent = nullptr);
    ~modpeopleaddress();

private slots:
    void on_ok_clicked();
    void on_quit_clicked();
    QString gettextBefore();
    QString gettextAfter();
private:
    Ui::modpeopleaddress *ui;
};

#endif // MODPEOPLEADDRESS_H
