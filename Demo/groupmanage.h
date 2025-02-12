#ifndef GROUPMANAGE_H
#define GROUPMANAGE_H

#include <QWidget>

namespace Ui {
class groupmanage;
}

class groupmanage : public QWidget
{
    Q_OBJECT

public:
    explicit groupmanage(QWidget *parent = nullptr);
    ~groupmanage();

private slots:
    void on_ModGroupName_clicked();

    void on_AddGroupPerson_clicked();

    void on_DeleteGroupPerson_clicked();

    void on_quit_clicked();

private:
    Ui::groupmanage *ui;
};

#endif // GROUPMANAGE_H
