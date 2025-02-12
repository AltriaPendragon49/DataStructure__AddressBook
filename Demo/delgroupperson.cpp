#include "delgroupperson.h"
#include "ui_delgroupperson.h"
#include "search.h"
#include "QMessageBox"
#include "save_load.h"
#include "mainwindow.h"

delgroupperson::delgroupperson(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::delgroupperson)
{
    ui->setupUi(this);
}

delgroupperson::~delgroupperson()
{
    delete ui;
}

QString delgroupperson::gettextBefore(){
    QString text=ui->Groupname->text();
    return text;
}

QString delgroupperson::gettextAfter(){
    QString text=ui->Personname->text();
    return text;
}


void delgroupperson::on_ok_clicked()
{
    QString groupname=gettextBefore();
    QString personname=gettextAfter();
    PNode *person=Search_People(contactsHead,personname);
    Group *group=Search_group(groupsHead,groupname);

    if(!person){
        QMessageBox::warning(nullptr,"错误","没有这个联系人！");
    }
    else if(!group){
        QMessageBox::warning(nullptr,"错误","没有这个分组！");
    }
    else{
        group->person.removeAll(person->data.name);
        SaveGroupList1(groupsHead,"group.txt");

        QMessageBox::information(nullptr,"提示","修改成功！");
        this->close();
        MainWindow *p=new MainWindow();
        p->show();
    }
}

void delgroupperson::on_quit_clicked()
{
    this->close();
    MainWindow *p=new MainWindow();
    p->show();
}

