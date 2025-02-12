#include "modify.h"
#include "ui_modify.h"
#include "mainwindow.h"
#include "QMessageBox"
#include "modpeoplename.h"
#include "modpeopleaddress.h"
#include "modpeopleposition.h"
#include "modpeoplenumber.h"
#include "addpeoplenumber.h"
#include "delpeoplenumber.h"

modify::modify(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::modify)
{
    ui->setupUi(this);
}

modify::~modify()
{
    delete ui;
}

void modify::on_quit_clicked()
{
    this->close();
    MainWindow *p=new MainWindow;
    p->show();
}

void modify::on_ModPeopleName_clicked()
{
    this->close();
    ModPeopleName *mpn=new ModPeopleName;
    mpn->show();
}


void modify::on_ModPeopleNumber_clicked()
{
    this->close();
    modpeoplenumber *p=new modpeoplenumber;
    p->show();
}


void modify::on_ModPeoplePosition_clicked()
{
    this->close();
    modpeopleposition *p=new modpeopleposition;
    p->show();
}


void modify::on_ModPeopleAddress_clicked()
{
    this->close();
    modpeopleaddress *p=new modpeopleaddress;
    p->show();
}

void modify::on_DeletePeopleNumber_clicked()
{
    this->close();
    delpeoplenumber *p=new delpeoplenumber;
    p->show();
}


void modify::on_AddPeopleNumber_clicked()
{
    this->close();
    addpeoplenumber *p=new addpeoplenumber;
    p->show();
}

