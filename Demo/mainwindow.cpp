#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"select.h"
#include "del.h"
#include"Modify.h"
#include "creategroup.h"
#include "display.h"
#include <QMessageBox>
#include "statistic.h"
#include "searchwidget.h"
#include"groupmanage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFixedSize(1000, 600);
    ui->setupUi(this);

    //添加四列
    ui->twPeople->setColumnCount(4);
    QStringList horizantalList;
    horizantalList<<"姓名";
    horizantalList<<"职位";
    horizantalList<<"地址";
    horizantalList<<"电话";
    ui->twPeople->setHorizontalHeaderLabels(horizantalList);

    //display
    displayPeople(contactsHead);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayPeople(PNode* p)
{   while(p){
        int count = ui->twPeople->rowCount();
        ui->twPeople->setRowCount(count + 1);

        QTableWidgetItem* nameItem = new QTableWidgetItem(p->data.name);
        QTableWidgetItem* posiItem = new QTableWidgetItem(p->data.position);
        QTableWidgetItem* addItem = new QTableWidgetItem(p->data.address);

        // 将电话号码列表转换为以逗号分隔的字符串
        QString phoneNumbers = p->data.number.join(", ");
        QTableWidgetItem* phoneItem = new QTableWidgetItem(phoneNumbers);

        ui->twPeople->setItem(count, 0, nameItem);
        ui->twPeople->setItem(count, 1, posiItem);
        ui->twPeople->setItem(count, 2, addItem);
        ui->twPeople->setItem(count, 3, phoneItem); // 显示电话号码
        ui->twPeople->setColumnWidth(3, 500);
        p = p->next;
    }

}

void MainWindow::on_pushButton_clicked()
{
    this->close();
    select *p2=new select();
    p2->show();
}


void MainWindow::on_delp_clicked()
{
    this->close();
    del *delp=new del();
    delp->show();
}


void MainWindow::on_modp_clicked()
{
    this->close();
    modify *p=new modify();
    p->show();
}


void MainWindow::on_seap_clicked()
{
    this->close();
    searchWidget *sWidget =new searchWidget();
    sWidget->show();
}


void MainWindow::on_creg_clicked()
{
    this->close();
    createGroup *groupWidget =new createGroup;
    groupWidget->show();
}


void MainWindow::on_seeg_clicked()
{
    this->close();
    printGroupMembers(groupsHead);
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void MainWindow::on_modg_clicked()
{
    this->close();
    groupmanage *p=new groupmanage;
    p->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    int count = getTotalContacts(contactsHead);
    QString message = QString("总人数为：%1").arg(count);
    QMessageBox::information(this, "总人数统计", message);
    printGroupMembers(groupsHead);
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

}

