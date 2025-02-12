#include "save_load.h"
#include <QFile>
#include <QTextStream>
#include <QInputDialog>
#include <QMessageBox>

void SavePeopleList(PNode* head, const QString& filename) {
    QFile file(filename);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        PNode* current = head;  // ??????????
        while (current != nullptr) {
            // ??? QString::fromStdString ??? std::string
            out << QString::fromStdString(current->data.name.toStdString()) << ","
                << QString::fromStdString(current->data.position.toStdString()) << ","
                << QString::fromStdString(current->data.address.toStdString());

            for (const auto& number : current->data.number) {
                out << "," << QString::fromStdString(number.toStdString());
            }
            out << Qt::endl;  // ??? Qt::endl ???? endl
            current = current->next;
        }
        file.close();
    }
}
void SavePeopleList1(PNode* head, const QString& filename) {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        PNode* current = head;  // ??????????
        while (current != nullptr) {
            // ??? QString::fromStdString ??? std::string
            out << QString::fromStdString(current->data.name.toStdString()) << ","
                << QString::fromStdString(current->data.position.toStdString()) << ","
                << QString::fromStdString(current->data.address.toStdString());

            for (const auto& number : current->data.number) {
                out << "," << QString::fromStdString(number.toStdString());
            }
            out << Qt::endl;  // ??? Qt::endl ???? endl
            current = current->next;
        }
        file.close();
    }
}

void SaveGroupList(Group* head, const QString& filename) {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        Group* current = head->next;  // ??????????
        while (current != nullptr) {
            out << current->name;

            for (const auto& person : current->person) {
                out << "," << person;
            }
            out << Qt::endl;  // ??? Qt::endl ???? endl
            current = current->next;
        }
        file.close();
    }
}
void SaveGroupList1(Group* head, const QString& filename) {
    if(head==nullptr)
        return;
    QFile file(filename);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        Group* current = head->next;  // ??????????
        while (current != nullptr) {
            out << current->name;

            for (const auto& person : current->person) {
                out << "," << person;
            }
            out << Qt::endl;  // ??? Qt::endl ???? endl
            current = current->next;
        }
        file.close();
    }
}
void LoadPeopleList(PNode*& head, const QString& filename) {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line;

        // ???????????????????
        head = nullptr;
        PNode* tail = nullptr;

        while (!(line = in.readLine()).isNull()) {
            QStringList tokens = line.split(",");
            PNode* newNode = new PNode;

            // ??????????????
            newNode->data.name = tokens.value(0);
            newNode->data.position = tokens.value(1);
            newNode->data.address = tokens.value(2);
            newNode->data.number = tokens.mid(3);

            newNode->next = nullptr;

            // ?????????????????
            if (head == nullptr) {
                head = newNode;  // ???????????????????????
                tail = newNode;  // ??????????
            } else {
                tail->next = newNode;  // ?????????????????
                tail = newNode;  // ?????????
            }
        }
        file.close();
    }
}

void LoadGroupList(Group*& head, const QString& filename) {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line;

        // ???????????????????
        head = nullptr;
        Group* tail = nullptr;

        while (!(line = in.readLine()).isNull()) {
            QStringList tokens = line.split(",");
            Group* newNode = new Group;

            // ??????????????
            newNode->name = tokens.value(0);
            newNode->person = tokens.mid(1);

            newNode->next = nullptr;

            // ?????????????????
            if (head == nullptr) {
                head = newNode;  // ???????????????????????
                tail = newNode;  // ??????????
            } else {
                tail->next = newNode;  // ?????????????????
                tail = newNode;  // ?????????
            }
        }
        file.close();
    }
}
