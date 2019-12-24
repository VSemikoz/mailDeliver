QT       += core
QT       += gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TEMPLATE = app
TARGET = mailDeliver


SOURCES += main.cpp\
    appendmailgroup.cpp \
    appendmailwindow.cpp \
    database.cpp \
    mailgroupsettings.cpp \
    mainwindow.cpp \
    settings.cpp \
    settingswindow.cpp

HEADERS  += mainwindow.h \
    appendmailgroup.h \
    appendmailwindow.h \
    database.h \
    mailgroupsettings.h \
    settings.h \
    settingswindow.h

FORMS    += mainwindow.ui \
    appendmailgroup.ui \
    appendmailwindow.ui \
    mailgroupsettings.ui \
    settingswindow.ui

