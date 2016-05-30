cmake_minimum_required(VERSION 3.3)
project(QtProject2)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)


include_directories(MenuWidgets)

set(SOURCE_FILES main.cpp MainPage.cpp MainPage.h AdfaerdsStyring.cpp AdfaerdsStyring.h AddUser.cpp AddUser.h MenuWidget.cpp MenuWidget.h AendreBrugerprofil.cpp AendreBrugerprofil.h Aktivitetssimulering.cpp Aktivitetssimulering.h Lysstyring.cpp Lysstyring.h EnhedsHaandtering.cpp EnhedsHaandtering.h LoginDialog.cpp LoginDialog.h User.cpp User.h QMainApp.cpp QMainApp.h Globals.h Unit.cpp Unit.h  Clock.cpp Clock.h Worker.cpp Worker.h portablesleep.h SendOnX10.cpp SendOnX10.h CSender.cpp CSender.h)
add_executable(QtProject2 ${SOURCE_FILES} Globals.h)

target_link_libraries(QtProject2 Qt5::Core Qt5::Widgets Qt5::Gui)