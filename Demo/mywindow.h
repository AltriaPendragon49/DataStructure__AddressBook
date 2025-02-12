#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>

namespace Ui {
class Mywindow;
}

class Mywindow : public QWidget
{
    Q_OBJECT

public:
    explicit Mywindow(QWidget *parent = nullptr);
    ~Mywindow();

private:
    Ui::Mywindow *ui;
};

#endif // MYWINDOW_H
