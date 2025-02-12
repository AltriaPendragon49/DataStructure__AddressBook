#ifndef SELECT_H
#define SELECT_H

#include <QWidget>

namespace Ui {
class select;
}

class select : public QWidget
{
    Q_OBJECT

public:
    explicit select(QWidget *parent = nullptr);
    ~select();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::select *ui;
};

#endif // SELECT_H
