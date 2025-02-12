#ifndef STATISTIC_H
#define STATISTIC_H

#include "people.h"

// 获取联系人总数
int getTotalContacts(const PNode* head);

// 打印分组信息
void printGroupMembers(const Group* groupHead);

// 释放联系人链表内存
void freeContactList(PNode*& head);

// 释放分组链表内存
void freeGroupList(Group*& groupHead);

#endif // STATISTIC_H
