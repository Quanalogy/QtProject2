//
// Created by Munke on 11-04-2016.
//

#ifndef QTPROJECT_MAINPAGE_H
#define QTPROJECT_MAINPAGE_H


#include <QtWidgets/QWidget>
#include "MenuWidget.h"

class MainPage : public MenuWidget{
public:
    MainPage(QWidget *parent = 0);
    QString getName();

private:
    QString name = "Hovedmenu";
    QList<MenuWidget *> pages;
};


#endif //QTPROJECT_MAINPAGE_H
