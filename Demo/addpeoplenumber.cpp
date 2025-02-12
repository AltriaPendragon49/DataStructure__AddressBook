#include "addpeoplenumber.h"
#include "ui_addpeoplenumber.h"
#include "mainwindow.h"
#include "search.h"
#include "QMessageBox"
#include "save_load.h"

addpeoplenumber::addpeoplenumber(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addpeoplenumber)
{
    ui->setupUi(this);
}

addpeoplenumber::~addpeoplenumber()
{
    delete ui;
}

QString addpeoplenumber::gettextBefore(){
    QString text=ui->Name->text();
    return text;
}

QString addpeoplenumber::gettextAfter(){
    QString text=ui->Newnumber->text();
    return text;
}

void addpeoplenumber::on_ok_clicked()
{
    QString name=gettextBefore();
    QString newnumber=gettextAfter();
    PNode *person=Search_People(contactsHead,name);

    if(!person){
        QMessageBox::warning(nullptr,"错误","对象为空！");
    }
    else{
        person->data.number.push_back(newnumber);
        SavePeopleList1(contactsHead,"people.txt");

        QMessageBox::information(nullptr,"提示","修改成功！");
        this->close();
        MainWindow *p=new MainWindow();
        p->show();
    }
}

void addpeoplenumber::on_quit_clicked()
{
    this->close();
    MainWindow *p=new MainWindow();
    p->show();
}

