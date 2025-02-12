#include "statistic.h"
#include <QMessageBox>

// 获取联系人总数
int getTotalContacts(const PNode* head) {
    int count = 0;
    while (head) {
        ++count;
        head = head->next;
    }
    return count ;
}

void printGroupMembers(const Group* groupHead) {
    QString allGroupsInfo;
    groupHead = groupHead->next;
    while (groupHead) {
        QString members;
        for (const auto& memberName : groupHead->person) {
            members.append(memberName + "\n");
        }

        allGroupsInfo.append("Group: " + groupHead->name + "\n" + "Members:\n" + members + "\n");

        groupHead = groupHead->next;
    }

    if (!allGroupsInfo.isEmpty()) {
        QMessageBox::information(nullptr, "All Group Members", allGroupsInfo);
    } else {
        QMessageBox::information(nullptr, "No Groups", "There are no groups.");
    }
}


// 释放联系人链表内存
void freeContactList(PNode*& head) {
    PNode* current = head;
    while (current != nullptr) {
        PNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr; // 将头指针设置为nullptr，避免悬挂指针
}

// 释放分组链表内存
void freeGroupList(Group*& groupHead) {
    while (groupHead != nullptr) {
        Group* temp = groupHead;
        groupHead = groupHead->next;
        delete temp;
    }
    groupHead = nullptr; // 将头指针设置为nullptr，避免悬挂指针
}
