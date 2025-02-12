#ifndef CREATEGROUP_H
#define CREATEGROUP_H

#include <QWidget>

namespace Ui {
class createGroup;
}

class createGroup : public QWidget
{
    Q_OBJECT

public:
    explicit createGroup(QWidget *parent = nullptr);
    ~createGroup();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::createGroup *ui;
};

#endif // CREATEGROUP_H
