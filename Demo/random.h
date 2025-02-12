#ifndef RANDOM_H
#define RANDOM_H

#include"QString"
#include <QCoreApplication>
#include <QString>
#include <QList>
#include <QRandomGenerator>
#include"people.h"

QString generateRandomChineseName();
QString generateRandomNumber(int length);
People generateRandomPeople();
QString generateRandomPosition();
QString generateRandomAddress();

#endif // RANDOM_H
