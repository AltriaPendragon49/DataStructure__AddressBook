#include "search.h"

PNode* Search_Number(PNode p, const QString& temp) {
    PNode* cur = p.next;
    while (cur != nullptr) {
        for (auto it = cur->data.number.begin(); it != cur->data.number.end(); ++it) {
            if (temp == *it) {
                return cur;
            }
        }
        cur = cur->next;
    }
    return nullptr;
}

PNode* Search_People(PNode*& p, const QString& temp) {
    PNode* cur = p;
    while (cur != nullptr && temp != cur->data.name) {
        cur = cur->next;
    }
    if (cur == nullptr) {
        // Use QMessageBox for displaying messages in Qt
        // QMessageBox::information(nullptr, "Not Found", "Person not found.");
        return nullptr;
    } else {
        return cur;
    }
}

Group* Search_group( Group*& G, const QString& name) {
    Group* cur = G;
    while (cur != nullptr) {
        if (cur->name == name) {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}
