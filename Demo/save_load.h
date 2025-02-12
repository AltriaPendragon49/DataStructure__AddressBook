#include "people.h"
#include <QFile>
#include <QTextStream>

void SavePeopleList(PNode* head, const QString& filename);
void SavePeopleList1(PNode* head, const QString& filename);


void SaveGroupList(Group* head, const QString& filename);
void SaveGroupList1(Group* head, const QString& filename);

void LoadPeopleList(PNode*& head, const QString& filename);

void LoadGroupList(Group*& head, const QString& filename);
