#include "delpeoplenumber.h"
#include "ui_delpeoplenumber.h"
#include "mainwindow.h"
#include "search.h"
#include "QMessageBox"
#include "save_load.h"

delpeoplenumber::delpeoplenumber(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::delpeoplenumber)
{
    ui->setupUi(this);
}

delpeoplenumber::~delpeoplenumber()
{
    delete ui;
}

QString delpeoplenumber::gettextBefore(){
    QString text=ui->Name->text();
    return text;
}

QString delpeoplenumber::gettextAfter(){
    QString text=ui->numbers->text();
    return text;
}

void delpeoplenumber::on_ok_clicked()
{
    QString name=gettextBefore();
    QString numbers=gettextAfter();
    PNode *person=Search_People(contactsHead,name);

    if(!person){
        QMessageBox::warning(nullptr,"错误","对象为空！");
    }
    else{
        person->data.number.removeAll(numbers);
        SavePeopleList1(contactsHead,"people.txt");

        QMessageBox::information(nullptr,"提示","修改成功！");
        this->close();
        MainWindow *p=new MainWindow();
        p->show();
    }
}

void delpeoplenumber::on_quit_clicked()
{
    this->close();
    MainWindow *p=new MainWindow();
    p->show();
}

void delpeoplenumber::on_request_clicked(){
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
