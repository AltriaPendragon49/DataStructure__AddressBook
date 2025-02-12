#include "del.h"
#include "ui_del.h"
#include "Delete.h"
#include "delpeople.h"
#include "delphone.h"
del::del(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::del)
{
    ui->setupUi(this);
}

del::~del()
{
    delete ui;
}

void del::on_pushButton_clicked()
{
    this->close();
    delpeople* delpeo=new delpeople();
    delpeo->show();

}


void del::on_pushButton_2_clicked()
{
    this->close();
    delphone *delnum=new delphone();
    delnum->show();
}

