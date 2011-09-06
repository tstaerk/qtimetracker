# -------------------------------------------------
# Project created by QtCreator 2009-12-31T10:10:55
# -------------------------------------------------
QT += core \
    gui
TARGET = qtimetracker
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    taskdialog.cpp
HEADERS += mainwindow.h \
    taskdialog.h
FORMS += mainwindow.ui \
    taskdialog.ui

target.path = /usr/local/bin
INSTALLS += target
