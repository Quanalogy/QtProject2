//
// Created by Munke on 11-04-2016.
//

#ifndef QTPROJECT_MAINPAGE_H
#define QTPROJECT_MAINPAGE_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QStackedLayout>
#include "MenuWidget.h"
#include <QtWidgets/QPushButton>

class MainPage : public MenuWidget{
    Q_OBJECT
public:
    MainPage(QWidget *parent = 0);
    QString getName(){return name;};

public slots:
    void ChangeView();
    void handleSaveClick();
    void handleCancelClick();
private:
    QString name = "Hovedmenu";
    QList<MenuWidget *> pages;
    QList<QPushButton *> buttons;
    QStackedLayout *mainLayout;
    int index;
};


#endif //QTPROJECT_MAINPAGE_H
