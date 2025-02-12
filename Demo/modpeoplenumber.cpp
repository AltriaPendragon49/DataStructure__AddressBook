#include "modpeoplenumber.h"
#include "ui_modpeoplenumber.h"
#include "mainwindow.h"
#include "search.h"
#include "QMessageBox"
#include "save_load.h"

modpeoplenumber::modpeoplenumber(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::modpeoplenumber)
{
    ui->setupUi(this);
}

modpeoplenumber::~modpeoplenumber()
{
    delete ui;
}

QString modpeoplenumber::gettextBefore(){
    QString text=ui->Name->text();
    return text;
}

QString modpeoplenumber::gettextAfter(){
    QString text=ui->numbers->text();
    return text;
}

QString modpeoplenumber::gettextNewnumber(){
    QString text=ui->newnumber->text();
    return text;
}

void modpeoplenumber::on_ok_clicked()
{
    QString name=gettextBefore();
    QString numbers=gettextAfter();
    QString newnumber=gettextNewnumber();
    PNode *person=Search_People(contactsHead,name);

    if(!person){
        QMessageBox::warning(nullptr,"错误","对象为空！");
    }
    else{
        person->data.number.removeAll(numbers);
        person->data.number.push_back(newnumber);
        SavePeopleList1(contactsHead,"people.txt");

        QMessageBox::information(nullptr,"提示","修改成功！");
        this->close();
        MainWindow *p=new MainWindow();
        p->show();
    }
}

void modpeoplenumber::on_quit_clicked()
{
    this->close();
    MainWindow *p=new MainWindow();
    p->show();
}

void modpeoplenumber::on_request_clicked(){
    QString name=gettextBefore();
    PNode *person=Search_People(contactsHead,name);
    if(!person){
        QMessageBox::warning(nullptr,"错误","对象为空！");
    }
    else{
        QString phones = person->data.number.join(",");
        QMessageBox::information(nullptr, "联系人信息",
                                 "Name: " + person->data.name + "\n" +
                                 "Phones: " + phones + "\n" +
                                 "Position: " + person->data.position + "\n" +
                                 "Address: " + person->data.address);
    }
}
