#ifndef PEOPLE_H
#define PEOPLE_H

#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QWidget>
#include <QList>

class People
{
public:
    QString name;
    QList<QString> number;
    QString position;
    QString address;
};

class Group
{
public:
    QString name;
    QList<QString> person;
    Group* next;
};

class PNode
{
public:
    PNode *next;
    People data;
};

extern PNode* contactsHead;
extern Group* groupsHead;

#endif // PEOPLE_H
