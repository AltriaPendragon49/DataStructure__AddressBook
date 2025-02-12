#ifndef MODIFY_H
#define MODIFY_H

#include <QWidget>
#include "people.h"

namespace Ui {
class modify;
}

class modify : public QWidget
{
    Q_OBJECT

public:
    explicit modify(QWidget *parent = nullptr);
    ~modify();

private slots:
    void on_quit_clicked();

    void on_ModPeopleName_clicked();

    void on_ModPeopleNumber_clicked();

    void on_ModPeoplePosition_clicked();

    void on_ModPeopleAddress_clicked();

    void on_DeletePeopleNumber_clicked();

    void on_AddPeopleNumber_clicked();

private:
    Ui::modify *ui;
};

#endif // MODIFY_H
