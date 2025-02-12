#ifndef ADDPEOPLENUMBER_H
#define ADDPEOPLENUMBER_H

#include <QWidget>

namespace Ui {
class addpeoplenumber;
}

class addpeoplenumber : public QWidget
{
    Q_OBJECT

public:
    explicit addpeoplenumber(QWidget *parent = nullptr);
    ~addpeoplenumber();

private slots:
    void on_ok_clicked();
    void on_quit_clicked();
    QString gettextBefore();
    QString gettextAfter();

private:
    Ui::addpeoplenumber *ui;
};

#endif // ADDPEOPLENUMBER_H
