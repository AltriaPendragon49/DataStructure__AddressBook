#include "file_add.h"
#include "ui_file_add.h"
#include "people.h"
#include"save_load.h"
#include "mainwindow.h"

file_add::file_add(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::file_add)
{
    ui->setupUi(this);
}

file_add::~file_add()
{
    delete ui;
}

void file_add::on_pushButton_clicked()
{       PNode *pp=nullptr;
    QString file_name=ui->lineEdit->text();
    LoadPeopleList(pp,file_name);
    this->close();
    SavePeopleList(pp,"people.txt");
    LoadPeopleList(contactsHead,"people.txt");
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void file_add::on_pushButton_2_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

