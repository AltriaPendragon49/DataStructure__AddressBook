#include"people.h"
#include <QCoreApplication>
#include <QString>
#include <QList>
#include <QRandomGenerator>
QStringList chineseNames = {
    "张三", "李四", "王五", "赵六", "周七",
};
QStringList positions = {
    "软件工程师", "产品经理", "市场专员", "销售经理",
    "人力资源专员", "财务主管", "行政助理", "技术支持"
};
QStringList addresses = {
"四川省雅安市","贵州省贵阳市","辽宁沈阳","辽宁大连"
};

// 生成随机的中文名字
QString generateRandomChineseName() {
    int index = QRandomGenerator::global()->bounded(chineseNames.size());
    return chineseNames.at(index);
}

// 生成随机的数字字符串
QString generateRandomNumber(int length) {
    QString possibleNumbers("0123456789");
    QString randomNumber;
    for (int i = 0; i < length; ++i) {
        int index = QRandomGenerator::global()->bounded(possibleNumbers.length());
        randomNumber.append(possibleNumbers.at(index));
    }
    return randomNumber;
}
QString generateRandomPosition() {
    int index = QRandomGenerator::global()->bounded(positions.size());
    return positions.at(index);
}
QString generateRandomAddress() {
    int index = QRandomGenerator::global()->bounded(addresses.size());
    return addresses.at(index);
}
// 生成随机的 People 对象
People generateRandomPeople() {
    People person;

    // 随机生成中文名字
    person.name = generateRandomChineseName();

    // 随机生成电话号码列表
    int numberOfPhones = QRandomGenerator::global()->bounded(1, 4); // 假设每个人有 1 到 3 个电话号码
    for (int i = 0; i < numberOfPhones; ++i) {
        person.number.append(generateRandomNumber(11)); // 假设电话号码长度为 11
    }

    // 随机生成职位
    person.position = generateRandomPosition();

    // 随机生成地址
    person.address = generateRandomAddress();

    return person;
}
