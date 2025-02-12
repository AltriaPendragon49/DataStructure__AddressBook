#include "creategroup.h"
#include "ui_creategroup.h"
#include "create.h"
#include "save_load.h"
#include "people.h"
#include "mainwindow.h"

createGroup::createGroup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::createGroup)
{
    ui->setupUi(this);
}

createGroup::~createGroup()
{
    delete ui;
}

void createGroup::on_pushButton_clicked()
{
    this->close();
    QString group_name = ui->groupName->text();
    addGroup(groupsHead,group_name);
    SaveGroupList(groupsHead,"group.txt");
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void createGroup::on_pushButton_2_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

