cmake_minimum_required(VERSION 3.3)
project(QtProject)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)


set(SOURCE_FILES main.cpp VerticalBox.cpp VerticalBox.h Nesting.cpp Nesting.h StackedLayout.cpp StackedLayout.h MainPage.cpp MainPage.h AdfaerdsStyring.cpp AdfaerdsStyring.h AddUser.cpp AddUser.h)
add_executable(QtProject2 ${SOURCE_FILES})

target_link_libraries(QtProject2 Qt5::Core Qt5::Widgets Qt5::Gui)