QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Delete.cpp \
    Modify.cpp \
    Sort.cpp \
    add.cpp \
    addgroupperson.cpp \
    addpeoplenumber.cpp \
    create.cpp \
    creategroup.cpp \
    del.cpp \
    delgroupperson.cpp \
    delpeople.cpp \
    delpeoplenumber.cpp \
    delphone.cpp \
    display.cpp \
    file_add.cpp \
    groupmanage.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    modgroupname.cpp \
    modpeopleaddress.cpp \
    modpeoplename.cpp \
    modpeoplenumber.cpp \
    modpeopleposition.cpp \
    people.cpp \
    random.cpp \
    save_load.cpp \
    search.cpp \
    searchwidget.cpp \
    select.cpp \
    statistic.cpp

HEADERS += \
    Delete.h \
    Modify.h \
    Sort.h \
    add.h \
    addgroupperson.h \
    addpeoplenumber.h \
    address_book.h \
    create.h \
    creategroup.h \
    del.h \
    delgroupperson.h \
    delpeople.h \
    delpeoplenumber.h \
    delphone.h \
    display.h \
    file_add.h \
    groupmanage.h \
    login.h \
    mainwindow.h \
    modgroupname.h \
    modpeopleaddress.h \
    modpeoplename.h \
    modpeoplenumber.h \
    modpeopleposition.h \
    people.h \
    random.h \
    save_load.h \
    search.h \
    searchwidget.h \
    select.h \
    statistic.h

FORMS += \
    add.ui \
    addgroupperson.ui \
    addpeoplenumber.ui \
    creategroup.ui \
    del.ui \
    delgroupperson.ui \
    delpeople.ui \
    delpeoplenumber.ui \
    delphone.ui \
    file_add.ui \
    groupmanage.ui \
    login.ui \
    mainwindow.ui \
    modgroupname.ui \
    modify.ui \
    modpeopleaddress.ui \
    modpeoplename.ui \
    modpeoplenumber.ui \
    modpeopleposition.ui \
    searchwidget.ui \
    select.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
