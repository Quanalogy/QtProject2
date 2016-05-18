cmake_minimum_required(VERSION 3.3)
project(QtProject)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)
include_directories(MenuWidgets)

set(SOURCE_FILES main.cpp VerticalBox.cpp VerticalBox.h Nesting.cpp Nesting.h StackedLayout.cpp StackedLayout.h MenuWidgets/MainPage.cpp MenuWidgets/MainPage.h MenuWidgets/AdfaerdsStyring.cpp MenuWidgets/AdfaerdsStyring.h MenuWidgets/AddUser.cpp MenuWidgets/AddUser.h MenuWidgets/MenuWidget.cpp MenuWidgets/MenuWidget.h MenuWidgets/AendreBrugerprofil.cpp MenuWidgets/AendreBrugerprofil.h MenuWidgets/Aktivitetssimulering.cpp MenuWidgets/Aktivitetssimulering.h MenuWidgets/Lysstyring.cpp MenuWidgets/Lysstyring.h MenuWidgets/EnhedsHaandtering.cpp MenuWidgets/EnhedsHaandtering.h LoginDialog.cpp LoginDialog.h User.cpp User.h QMainApp.cpp QMainApp.h Globals.h)
add_executable(QtProject2 ${SOURCE_FILES} Globals.h)

target_link_libraries(QtProject2 Qt5::Core Qt5::Widgets Qt5::Gui)