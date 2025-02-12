#include <QString>
#include <QList>
#include "Sort.h"

bool compareGroupByName(const Group* a, const Group* b) {
    return a->name < b->name;
}

void sort_groups(Group* group) {
    Group* head = group;
    Group** tail = &head;

    while (group != nullptr) {
        group->person.sort();
        group = group->next;
    }

    QList<Group*> groupList;
    group = head;
    while (group != nullptr) {
        groupList.push_back(group);
        Group* nextGroup = group->next;
        group->next = nullptr;
        group = nextGroup;
    }
    std::sort(groupList.begin(), groupList.end(), compareGroupByName);
    for (auto sortedGroup : groupList) {
        *tail = sortedGroup;
        tail = &sortedGroup->next;
    }
}

void sort_people(PNode* p) {
    PNode* head = p;
    PNode** tail = &head;

    QList<PNode*> peopleList;
    while (p != nullptr) {
        peopleList.push_back(p);
        PNode* nextPNode = p->next;
        p->next = nullptr;
        p = nextPNode;
    }

    std::sort(peopleList.begin(), peopleList.end(), [](const PNode* a, const PNode* b) {
        return a->data.name.compare(b->data.name, Qt::CaseInsensitive) < 0;
    });

    for (auto sortedPNode : peopleList) {
        *tail = sortedPNode;
        tail = &sortedPNode->next;
    }
}
