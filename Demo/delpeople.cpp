#include "delpeople.h"
#include "ui_delpeople.h"
#include "mainwindow.h"
#include "Delete.h"
#include "people.h"
#include "save_load.h"


delpeople::delpeople(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::delpeople)
{
    ui->setupUi(this);
}

delpeople::~delpeople()
{
    delete ui;
}

void delpeople::on_pushButton_clicked()
{
    QString delname=ui->delname->text();
    deletePeople(contactsHead,groupsHead,delname);
    SavePeopleList1(contactsHead,"people.txt");
    SaveGroupList1(groupsHead,"group.txt");
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void delpeople::on_pushButton_2_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

