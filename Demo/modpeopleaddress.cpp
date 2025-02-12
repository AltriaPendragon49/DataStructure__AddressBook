#include "modpeopleaddress.h"
#include "ui_modpeopleaddress.h"
#include "mainwindow.h"
#include "search.h"
#include "QMessageBox"
#include "save_load.h"

modpeopleaddress::modpeopleaddress(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::modpeopleaddress)
{
    ui->setupUi(this);
}

modpeopleaddress::~modpeopleaddress()
{
    delete ui;
}

QString modpeopleaddress::gettextBefore(){
    QString text=ui->Name->text();
    return text;
}

QString modpeopleaddress::gettextAfter(){
    QString text=ui->Address->text();
    return text;
}

void modpeopleaddress::on_ok_clicked()
{
    QString name=gettextBefore();
    QString address=gettextAfter();
    PNode *person=Search_People(contactsHead,name);

    if(!person){
        QMessageBox::warning(nullptr,"错误","对象为空！");
    }
    else{
        person->data.address=address;
        SavePeopleList1(contactsHead,"people.txt");

        QMessageBox::information(nullptr,"提示","修改成功！");
        this->close();
        MainWindow *p=new MainWindow();
        p->show();
    }
}

void modpeopleaddress::on_quit_clicked()
{
    this->close();
    MainWindow *p=new MainWindow();
    p->show();
}

