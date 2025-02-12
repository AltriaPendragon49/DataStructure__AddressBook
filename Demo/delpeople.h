#ifndef DELPEOPLE_H
#define DELPEOPLE_H

#include <QWidget>

namespace Ui {
class delpeople;
}

class delpeople : public QWidget
{
    Q_OBJECT

public:
    explicit delpeople(QWidget *parent = nullptr);
    ~delpeople();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::delpeople *ui;
};

#endif // DELPEOPLE_H
