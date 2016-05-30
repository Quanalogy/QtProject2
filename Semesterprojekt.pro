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

# So wiringPi include files can be found during compile
INCLUDEPATH    += /usr/local/include

# To link the wiringPi library when making the executable
LIBS += -L/usr/local/lib -lwiringPi

SOURCES += main.cpp \
	SendOnX10.cpp \
	Worker.cpp \
	CodeSender.cpp \
	QMainApp.cpp \
	LoginDialog.cpp\
    MenuWidgets/MenuWidget.cpp \
    MenuWidgets/AddUser.cpp \
    MenuWidgets/AdfaerdsStyring.cpp \
    MenuWidgets/AendreBrugerprofil.cpp \
    MenuWidgets/Aktivitetssimulering.cpp \
    MenuWidgets/EnhedsHaandtering.cpp \
    MenuWidgets/Lysstyring.cpp \
    MenuWidgets/MainPage.cpp \


HEADERS  += SendOnX10.h \
	User.h \
	Clock.h \
	Worker.h \
	CodeSender.h \
	Globals.h \
	QMainApp.h \
	LoginDialog.h \
	MenuWidgets/MenuWidget.h \
    MenuWidgets/AddUser.h \
    MenuWidgets/AdfaerdsStyring.h \
    MenuWidgets/AendreBrugerprofil.h \
    MenuWidgets/Aktivitetssimulering.h \
    MenuWidgets/EnhedsHaandtering.h \
    MenuWidgets/Lysstyring.h \
    MenuWidgets/MainPage.h \
	MenuWidgets/portablesleep.h \