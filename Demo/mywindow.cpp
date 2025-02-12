#include "mywindow.h"
#include "ui_mywindow.h"

Mywindow::Mywindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Mywindow)
{
    ui->setupUi(this);
}

Mywindow::~Mywindow()
{
    delete ui;
}
