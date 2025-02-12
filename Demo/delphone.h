#ifndef DELPHONE_H
#define DELPHONE_H

#include <QWidget>

namespace Ui {
class delphone;
}

class delphone : public QWidget
{
    Q_OBJECT

public:
    explicit delphone(QWidget *parent = nullptr);
    ~delphone();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::delphone *ui;
};

#endif // DELPHONE_H
