# -------------------------------------------------
# Project created by QtCreator 2009-12-31T10:10:55
# -------------------------------------------------
QT += core \
    gui
# qt5 needs the widgets because most elements are now in widgets
contains(QT_VERSION, ^5\\..\\..*) {
	QT += widgets
}
TARGET = qtimetracker
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    taskdialog.cpp
HEADERS += mainwindow.h \
    taskdialog.h \
    mytreewidget.h
FORMS += mainwindow.ui \
    taskdialog.ui

target.path = /usr/local/bin
INSTALLS += target

RESOURCES += \
    qtimetrackerresourcefile.qrc
