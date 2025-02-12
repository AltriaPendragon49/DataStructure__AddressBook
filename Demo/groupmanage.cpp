#include "groupmanage.h"
#include "ui_groupmanage.h"
#include "mainwindow.h"
#include "modgroupname.h"
#include "addgroupperson.h"
#include "delgroupperson.h"

groupmanage::groupmanage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::groupmanage)
{
    ui->setupUi(this);
}

groupmanage::~groupmanage()
{
    delete ui;
}

void groupmanage::on_ModGroupName_clicked()
{
    this->close();
    modgroupname *p=new modgroupname();
    p->show();
}


void groupmanage::on_AddGroupPerson_clicked()
{
    this->close();
    addgroupperson *p=new addgroupperson();
    p->show();
}


void groupmanage::on_DeleteGroupPerson_clicked()
{
    this->close();
    delgroupperson *p=new delgroupperson();
    p->show();
}


void groupmanage::on_quit_clicked()
{
    this->close();
    MainWindow *p=new MainWindow();
    p->show();
}

