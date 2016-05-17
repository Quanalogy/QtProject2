//
// Created by Munke on 11-04-2016.
//

#ifndef QTPROJECT_MAINPAGE_H
#define QTPROJECT_MAINPAGE_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QStackedLayout>
#include "MenuWidget.h"
#include <QtWidgets/QPushButton>
#include <QtCore/QMap>
#include <vector>

using namespace std;
class MainPage : public MenuWidget{
    Q_OBJECT
public:
    MainPage(QWidget *parent = 0);
    QString getName(){return name;};

public slots:
    void ChangeView();
    void handleSaveClick();
    void handleAddSave();
    void handleCancelClick();
    bool slotAcceptUserLogin(QString&,QString&);
private:
    QString name = "Hovedmenu";
    QList<MenuWidget *> pages;
    QList<QPushButton *> buttons;
    QStackedLayout *mainLayout;
    int index;
    QMap<QString, QString> userMap;
    QString currentUserName; // holds the current username try
    QString currentPassword; // holds the current password try
    vector<bool> rights;
};


#endif //QTPROJECT_MAINPAGE_H
