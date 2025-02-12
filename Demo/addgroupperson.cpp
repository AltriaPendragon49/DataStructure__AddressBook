#include "addgroupperson.h"
#include "ui_addgroupperson.h"
#include "mainwindow.h".h"
#include "search.h"
#include "QMessageBox"
#include "save_load.h"

addgroupperson::addgroupperson(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addgroupperson)
{
    ui->setupUi(this);
}

addgroupperson::~addgroupperson()
{
    delete ui;
}

QString addgroupperson::gettextBefore(){
    QString text=ui->Name->text();
    return text;
}

QString addgroupperson::gettextAfter(){
    QString text=ui->Newname->text();
    return text;
}

void addgroupperson::on_ok_clicked()
{
    QString groupname=gettextBefore();
    QString newperson=gettextAfter();
    PNode *person=Search_People(contactsHead,newperson);
    Group *group=Search_group(groupsHead,groupname);

    if(!person){
        QMessageBox::warning(nullptr,"错误","没有这个联系人！");
    }
    else if(!group){
        QMessageBox::warning(nullptr,"错误","没有这个分组！");
    }
    else{
        group->person.push_back(person->data.name);
        SaveGroupList1(groupsHead,"group.txt");

        QMessageBox::information(nullptr,"提示","修改成功！");
        this->close();
        MainWindow *p=new MainWindow();
        p->show();
    }
}


void addgroupperson::on_quit_clicked()
{
    this->close();
    MainWindow *p=new MainWindow();
    p->show();
}

