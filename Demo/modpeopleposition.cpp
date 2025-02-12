#include "modpeopleposition.h"
#include "ui_modpeopleposition.h"
#include "mainwindow.h"
#include "search.h"
#include "QMessageBox"
#include "save_load.h"

modpeopleposition::modpeopleposition(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::modpeopleposition)
{
    ui->setupUi(this);
}

modpeopleposition::~modpeopleposition()
{
    delete ui;
}

QString modpeopleposition::gettextBefore(){
    QString text=ui->Name->text();
    return text;
}

QString modpeopleposition::gettextAfter(){
    QString text=ui->Position->text();
    return text;
}


void modpeopleposition::on_ok_clicked()
{
    QString name=gettextBefore();
    QString position=gettextAfter();
    PNode *person=Search_People(contactsHead,name);

    if(!person){
        QMessageBox::warning(nullptr,"错误","对象为空！");
    }
    else{
        person->data.position=position;
        SavePeopleList1(contactsHead,"people.txt");

        QMessageBox::information(nullptr,"提示","修改成功！");
        this->close();
        MainWindow *p=new MainWindow();
        p->show();
    }
}


void modpeopleposition::on_quit_clicked()
{
    this->close();
    MainWindow *p=new MainWindow();
    p->show();
}

