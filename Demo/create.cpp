#include "create.h"
#include <QInputDialog>
#include <QMessageBox>

void addContact(PNode*& head, const QString& name, const QString& position, const QString& address, const QStringList& phoneNumbers) {
    // 创建并填充 People 对象
    People newPerson;
    newPerson.name = name;
    newPerson.position = position;
    newPerson.address = address;
    newPerson.number = phoneNumbers;  // Convert QStringList to std::vector<std::string>

    // 创建新节点
    PNode* newNode = new PNode();
    newNode->data = newPerson;
    newNode->next = nullptr;

    // 如果链表为空（只有头节点），插入新节点作为第一个元素
    if (head == nullptr) {
        head = newNode;
        head->next=nullptr;
        return;
    }

    // 如果链表不为空，找到最后一个节点
    PNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // 将新节点插入到链表末尾
    current->next = newNode;
}



// 打印联系人信息
void printContacts(const PNode* head) {
    head = head->next;
    while (head) {
        QString phones = head->data.number.join(" ");

        QMessageBox::information(nullptr, "Contact Information",
                                 "Name: " + head->data.name + "\n" +
                                     "Phones: " + phones + "\n" +
                                     "Position: " + head->data.position + "\n" +
                                     "Address: " + head->data.address);

        head = head->next;
    }
}

// 添加分组
void addGroup(Group*& groupHead, const QString& groupName) {
    // 如果头节点为空，则创建一个哨兵节点
    if (groupHead == nullptr) {
        groupHead = new Group{ "", {}, nullptr };
    }

    // 在哨兵节点之后添加新组
    Group* newGroup = new Group{ groupName, {}, groupHead->next };
    groupHead->next = newGroup;
}

// 添加联系人到分组
void addPersonToGroup(Group* groupHead, const QString& groupName, const QString& personName) {
    // 从哨兵节点的下一个节点开始搜索
    Group* current = groupHead ? groupHead->next : nullptr;

    while (current && current->name != groupName) {
        current = current->next;
    }
    if (current) {
        current->person.push_back(personName);
    }
}
