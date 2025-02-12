#ifndef SEARCH_H
#define SEARCH_H

#include "people.h"

PNode* Search_Number(PNode p, const QString& temp);
PNode* Search_People(PNode*& p, const QString& temp);
Group* Search_group( Group*& G, const QString& name);

#endif // SEARCH_H
