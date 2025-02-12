#ifndef DELGROUPPERSON_H
#define DELGROUPPERSON_H

#include <QWidget>

namespace Ui {
class delgroupperson;
}

class delgroupperson : public QWidget
{
    Q_OBJECT

public:
    explicit delgroupperson(QWidget *parent = nullptr);
    ~delgroupperson();

private slots:
    void on_ok_clicked();
    void on_quit_clicked();
    QString gettextBefore();
    QString gettextAfter();

private:
    Ui::delgroupperson *ui;
};

#endif // DELGROUPPERSON_H
