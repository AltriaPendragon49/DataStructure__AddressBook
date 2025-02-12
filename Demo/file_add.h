#ifndef FILE_ADD_H
#define FILE_ADD_H

#include <QWidget>

namespace Ui {
class file_add;
}

class file_add : public QWidget
{
    Q_OBJECT

public:
    explicit file_add(QWidget *parent = nullptr);
    ~file_add();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::file_add *ui;
};

#endif // FILE_ADD_H
