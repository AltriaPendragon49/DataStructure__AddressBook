#include "mainwindow.h"
#include "people.h"
#include "display.h"
#include"save_load.h"

#include <QApplication>
#include <login.h>
int main(int argc, char *argv[])
{   LoadPeopleList(contactsHead,"people.txt");
    QApplication a(argc, argv);
    login w;
    w.setWindowTitle("通讯录");
    w.show();
    return a.exec();
}
