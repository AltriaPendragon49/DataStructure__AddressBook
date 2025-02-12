#ifndef MODPEOPLENUMBER_H
#define MODPEOPLENUMBER_H

#include <QWidget>

namespace Ui {
class modpeoplenumber;
}

class modpeoplenumber : public QWidget
{
    Q_OBJECT

public:
    explicit modpeoplenumber(QWidget *parent = nullptr);
    ~modpeoplenumber();

private slots:
    void on_ok_clicked();
    void on_quit_clicked();
    void on_request_clicked();
    QString gettextBefore();
    QString gettextAfter();
    QString gettextNewnumber();

private:
    Ui::modpeoplenumber *ui;
};

#endif // MODPEOPLENUMBER_H
