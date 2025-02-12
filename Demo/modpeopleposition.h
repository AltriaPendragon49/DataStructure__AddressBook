#ifndef MODPEOPLEPOSITION_H
#define MODPEOPLEPOSITION_H

#include <QWidget>

namespace Ui {
class modpeopleposition;
}

class modpeopleposition : public QWidget
{
    Q_OBJECT

public:
    explicit modpeopleposition(QWidget *parent = nullptr);
    ~modpeopleposition();

private slots:
    void on_ok_clicked();
    QString gettextBefore();
    QString gettextAfter();
    void on_quit_clicked();

private:
    Ui::modpeopleposition *ui;
};

#endif // MODPEOPLEPOSITION_H
