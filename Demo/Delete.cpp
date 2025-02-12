#include "Delete.h"
#include <QInputDialog>
#include <QMessageBox>

void deletePeople(PNode*& P, Group*& G,QString name)
{
    //QString name = QInputDialog::getText(nullptr, "Delete People", "Enter name:");
    PNode* cur = P;
    PNode* t = cur;
    Group* gno = G;
    Group* tt;

    while (cur != nullptr && cur->data.name != name)
    {
        t = cur;
        cur = cur->next;
    }

    if (cur != nullptr && cur->data.name == name) {
        if(cur==P)
        {   P=P->next;
            delete cur;
            cur=nullptr;
        }
        else
        {
            t->next = cur->next;
            delete cur;
            cur = nullptr;
        }
        QMessageBox::information(nullptr, "Deletion Successful", "Person deleted successfully.");
    }
    else {
        QMessageBox::information(nullptr, "Person Not Found", "Person not found.");
    }

    for (; gno != nullptr;) {
        gno->person.removeAll(name);
        gno = gno->next;
    }
}
void deletePhone(PNode*& P,QString n)
{
    //QString n = QInputDialog::getText(nullptr, "Delete Phone", "Enter phone number:");
    PNode* cur = P;

    while (cur != nullptr) {
        cur->data.number.removeAll(n);
        cur = cur->next;
    }
}
