#ifndef CREATE_H
#define CREATE_H

#include "people.h"

void addContact(PNode*& head, const QString& name, const QString& position, const QString& address, const QStringList& phoneNumbers);
void printContacts(const PNode* head);
void addGroup(Group*& groupHead, const QString& groupName);
void addPersonToGroup(Group* groupHead, const QString& groupName, const QString& personName);

#endif // CREATE_H
