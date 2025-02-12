#include "login.h"
#include "ui_login.h"
#include "save_load.h"

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
     ui->secretE->setEchoMode(QLineEdit::Password);
}

login::~login()
{
    delete ui;
}

void login::on_log_clicked()
{
    QString username=ui->userE->text();
    QString secret=ui->secretE->text();
    if(username=="b354"&&secret=="88888888")
    {
        this->close();

        MainWindow *addressBook=new MainWindow;
        addressBook->setWindowTitle("通讯录");
        addressBook->show();
        LoadPeopleList(contactsHead,"people.txt");
        LoadGroupList(groupsHead,"group.txt");
    }
    else
    {
        QMessageBox::information(this,"提示","登陆失败");
    }
}


void login::on_pushButton_2_clicked()
{
    this->close();
}

