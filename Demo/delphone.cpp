#include "delphone.h"
#include "ui_delphone.h"
#include "people.h"
#include "save_load.h"
#include "Delete.h"
#include "mainwindow.h"


delphone::delphone(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::delphone)
{
    ui->setupUi(this);
}

delphone::~delphone()
{
    delete ui;
}

void delphone::on_pushButton_clicked()
{
    QString num=ui->lineEdit->text();
    deletePhone(contactsHead,num);
    SavePeopleList1(contactsHead,"people.txt");
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void delphone::on_pushButton_2_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

