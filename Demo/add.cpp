#include "add.h"
#include "ui_add.h"
#include "mainwindow.h"
#include "create.h"
#include"save_load.h"

add::add(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}

void add::gettxt()
{

    QString s0= ui->lineEdit->text();
    QString s1= ui->lineEdit_2->text();
    QString s2= ui->lineEdit_3->text();
    QStringList s3 = ui->lineEdit_4->text().split(',');
    addContact(contactsHead,s0,s1,s2,s3);
    SavePeopleList1(contactsHead,"people.txt");
    //printContacts(contactsHead);
}
void add::on_pushButton_2_clicked()
{
    this->close();

    // 显示主窗口
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void add::on_pushButton_clicked()
{
    this->gettxt();
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

