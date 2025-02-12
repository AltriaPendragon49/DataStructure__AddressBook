#ifndef DELPEOPLENUMBER_H
#define DELPEOPLENUMBER_H

#include <QWidget>

namespace Ui {
class delpeoplenumber;
}

class delpeoplenumber : public QWidget
{
    Q_OBJECT

public:
    explicit delpeoplenumber(QWidget *parent = nullptr);
    ~delpeoplenumber();
private slots:
    void on_ok_clicked();
    void on_quit_clicked();
    void on_request_clicked();
    QString gettextBefore();
    QString gettextAfter();

private:
    Ui::delpeoplenumber *ui;
};

#endif // DELPEOPLENUMBER_H
