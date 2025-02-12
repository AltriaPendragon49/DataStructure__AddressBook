#include "modpeoplename.h"
#include "ui_modpeoplename.h"
#include "search.h"
#include "mainwindow.h"
#include "modify.h"
#include "save_load.h"
#include <QMessageBox>

ModPeopleName::ModPeopleName(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModPeopleName)
{
    ui->setupUi(this);
}

ModPeopleName::~ModPeopleName()
{
    delete ui;
}

QString ModPeopleName::gettextBefore(){
    QString text=ui->BeforeName->text();
    return text;
}

QString ModPeopleName::gettextAfter(){
    QString text=ui->AfterName->text();
    return text;
}

void ModPeopleName::on_ok_clicked()
{
    QString beforename=gettextBefore();
    QString aftername=gettextAfter();
    PNode *person=Search_People(contactsHead,beforename);

    if(!person){
        QMessageBox::warning(nullptr,"错误","对象为空！");
    }
    else{
        person->data.name=aftername;
        SavePeopleList1(contactsHead,"people.txt");

        QMessageBox::information(nullptr,"提示","修改成功！");
        this->close();
        MainWindow *p=new MainWindow();
        p->show();
    }
}

void ModPeopleName::on_quit_clicked()
{
    this->close();
    modify *p=new modify();//返回修改界面
    p->show();
}

