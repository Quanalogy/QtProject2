#-------------------------------------------------
#
# Project created by QtCreator 2016-05-11T16:18:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
TARGET = SemesterprojektPI
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    MenuWidget.cpp \
    AddUser.cpp \
    AdfaerdsStyring.cpp \
    AendreBrugerprofil.cpp \
    Aktivitetssimulering.cpp \
    EnhedsHaandtering.cpp \
    Lysstyring.cpp \
    MainPage.cpp \
    StackedLayout.cpp

HEADERS  += MainWindow.h \
    MenuWidget.h \
    AddUser.h \
    AdfaerdsStyring.h \
    AendreBrugerprofil.h \
    Aktivitetssimulering.h \
    EnhedsHaandtering.h \
    Lysstyring.h \
    MainPage.h \
    StackedLayout.h
FORMS    += mainwindow.ui
