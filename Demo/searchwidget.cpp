#include "searchwidget.h"
#include "ui_searchwidget.h"
#include "mainwindow.h"
searchWidget::searchWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::searchWidget)
{
    setFixedSize(1000, 600);
    ui->setupUi(this);

    ui->twPeople->setColumnCount(4);
    QStringList horizantalList;
    horizantalList<<"姓名";
    horizantalList<<"职位";
    horizantalList<<"地址";
    horizantalList<<"电话";
    ui->twPeople->setHorizontalHeaderLabels(horizantalList);
}

searchWidget::~searchWidget()
{
    delete ui;
}
void searchWidget::searchforname(PNode* p,QString name)
{
    ui->twPeople->setRowCount(0); // 清空表格
    while(p){
        if(p->data.name==name){
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
        }
    p = p->next;
    }
}
void searchWidget::searchforPhone(PNode* p, QStringList phone) {
    ui->twPeople->setRowCount(0); // 清空表格
    while (p) {
        // 遍历每个联系人的电话号码
        for (const QString& number : p->data.number) {
            // 如果电话号码列表中包含该号码
            if (phone.contains(number)) {
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
                ui->twPeople->setItem(count, 3, phoneItem);

                break; // 找到匹配项后跳出当前电话号码的循环
            }
        }
        p = p->next;
    }
}


void searchWidget::searchforPosition(PNode* p,QString position)
{
    ui->twPeople->setRowCount(0); // 清空表格
    while(p){
        if(p->data.position==position){
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
        }
        p = p->next;
    }
}

void searchWidget::searchforAddress(PNode* p,QString address)
{
    ui->twPeople->setRowCount(0); // 清空表格
    while(p){
        if(p->data.address==address){
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
        }
        p = p->next;
    }

}
void searchWidget::on_pushButton_3_clicked()
{
    QString name= ui->nameE->text();
    searchforname(contactsHead,name);

    //QString phone= ui->phoneE->text();
    //QString position= ui->positionE->text();
    //QString address= ui->addressE->text();

}


void searchWidget::on_pushButton_4_clicked()
{
    QStringList phone = ui->phoneE->text().split(",");

    searchforPhone(contactsHead,phone);
}


void searchWidget::on_pushButton_2_clicked()
{
    QString position= ui->positionE->text();
    searchforPosition(contactsHead,position);
}


void searchWidget::on_pushButton_clicked()
{
    QString address= ui->addressE->text();

    searchforAddress(contactsHead,address);
}


void searchWidget::on_pushButton_5_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}
