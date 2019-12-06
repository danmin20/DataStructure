#-------------------------------------------------
#
# Project created by QtCreator 2019-11-19T16:31:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proj
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    musictype.cpp \
    simplemusictype.cpp \
    usertype.cpp \
    account.cpp \
    search.cpp \
    addsong.cpp \
    deletesong.cpp \
    playsong.cpp \
    admin.cpp \
    application.cpp \
    mainwindow.cpp \
    display.cpp \
    assign.cpp \
    withdrawal.cpp \
    fileout.cpp

HEADERS += \
    musictype.h \
    simplemusictype.h \
    usertype.h \
    circularqueue.h \
    doublyiterator.h \
    doublylinkedlist.h \
    sortedlist.h \
    account.h \
    search.h \
    addsong.h \
    deletesong.h \
    playsong.h \
    admin.h \
    application.h \
    mainwindow.h \
    display.h \
    assign.h \
    withdrawal.h \
    fileout.h

FORMS += \
    account.ui \
    search.ui \
    addsong.ui \
    deletesong.ui \
    playsong.ui \
    admin.ui \
    application.ui \
    mainwindow.ui \
    display.ui \
    assign.ui \
    withdrawal.ui \
    fileout.ui

DISTFILES +=
