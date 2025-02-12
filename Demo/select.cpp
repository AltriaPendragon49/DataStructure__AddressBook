#include "select.h"
#include "people.h"
#include "ui_select.h"
#include"add.h"
#include"file_add.h"
#include"save_load.h"
#include "mainwindow.h"
#include "random.h"
#include "create.h"

select::select(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::select)
{
    ui->setupUi(this);
}

select::~select()
{
    delete ui;
}

void select::on_pushButton_3_clicked()
{
    this->close();
    add* p1=new add();
    p1->show();
}


void select::on_pushButton_2_clicked()
{
    this->close();
    file_add* p1=new file_add();
    p1->show();
}


void select::on_pushButton_clicked()
{
    this->close();
    People randomPerson = generateRandomPeople();
    addContact(contactsHead,randomPerson.name,randomPerson.position,randomPerson.address,randomPerson.number);
    SavePeopleList1(contactsHead,"people.txt");
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

