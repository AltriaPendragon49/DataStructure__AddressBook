#include "modgroupname.h"
#include "ui_modgroupname.h"
#include "search.h"
#include "mainwindow.h"
#include "save_load.h"
#include <QMessageBox>

modgroupname::modgroupname(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::modgroupname)
{
    ui->setupUi(this);
}

modgroupname::~modgroupname()
{
    delete ui;
}

QString modgroupname::gettextBefore(){
    QString text=ui->BeforeName->text();
    return text;
}

QString modgroupname::gettextAfter(){
    QString text=ui->AfterName->text();
    return text;
}

void modgroupname::on_ok_clicked()
{
    QString before=gettextBefore();
    QString after=gettextAfter();
    Group *group=Search_group(groupsHead,before);

    if(!group){
        QMessageBox::warning(nullptr,"错误","对象为空！");
    }
    else{
        group->name=after;
        SaveGroupList1(groupsHead,"group.txt");

        QMessageBox::information(nullptr,"提示","修改成功！");
        this->close();
        MainWindow *p=new MainWindow();
        p->show();
    }
}

void modgroupname::on_quit_clicked()
{
    this->close();
    MainWindow *p=new MainWindow();
    p->show();
}
