#-------------------------------------------------
#
# Project created by QtCreator 2016-05-11T16:18:42
#
#-------------------------------------------------

QT       += core gui

ggreaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11 debug

CONFIG(debug, debug|release) {
QMAKE_CXXFLAGS_DEBUG += -g3 -O0
QMAKE_LFLAGS_DEBUG += -rdynamic
message("DEBUG!")
} else {
DEFINES += QT_NO_DEBUG
DEFINES += QT_NO_DEBUG_OUTPUT
message("RELEASE!")
}
TARGET = SemesterprojektPI
TEMPLATE = app
qmake_lflags += -rdynamic
qmake_cxxflags += -g

# So wiringPi include files can be found during compile
INCLUDEPATH    += /usr/local/include

# To link the wiringPi library when making the executable
LIBS += -L/usr/local/lib -lwiringPi

SOURCES += main.cpp \
	SendOnX10.cpp \
	CSender.cpp \
	Worker.cpp \
	QMainApp.cpp \
	LoginDialog.cpp\
	Unit.cpp \
	User.cpp \
	Clock.cpp \
    MenuWidget.cpp \
    AddUser.cpp \
    AdfaerdsStyring.cpp \
    AendreBrugerprofil.cpp \
    Aktivitetssimulering.cpp \
    EnhedsHaandtering.cpp \
    Lysstyring.cpp \
    MainPage.cpp \


HEADERS  += SendOnX10.h \
	User.h \
	CSender.h \
	Unit.h \
	Clock.h \
	Worker.h \
	Globals.h \
	QMainApp.h \
	LoginDialog.h \
	MenuWidget.h \
    AddUser.h \
    AdfaerdsStyring.h \
    AendreBrugerprofil.h \
    Aktivitetssimulering.h \
    EnhedsHaandtering.h \
    Lysstyring.h \
    MainPage.h \
	portablesleep.h \
