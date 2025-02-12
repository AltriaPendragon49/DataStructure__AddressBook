#ifndef SORT_H
#define SORT_H

#include "people.h"

bool compareGroupByName(const Group* a, const Group* b);
void sort_groups(Group* group);
void sort_people(PNode* p);

#endif //SORT_H
