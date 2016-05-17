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
    void ChangeView();                              // a slot to handle when a button on the main window
                                                    // has been pressed
    void handleSaveClick();
    void handleCancelClick();                       // a slot to handle when cancel has been pressed
                                                    // on one of the views
    bool slotAcceptUserLogin(QString&,QString&);    //checks if the username and password is known
private:
    QString name = "Hovedmenu";                     // the window title name
    QList<MenuWidget *> pages;                      // All the pages avialable
    QList<MenuWidget *> userMenuPages;              // an of accessible menupages, costumized to the users
                                                    // rights
    QList<QPushButton *> buttons;                   // a list of all the buttons the user can use
    int index;                                      // holds the current index in the menu that has
                                                    // been pressed
    QMap<QString, QString> userMap;                 // holds all the users in our program
    QString currentUserName;                        // holds the current username try
    QString currentPassword;                        // holds the current password try
    vector<bool> rights;
};


#endif //QTPROJECT_MAINPAGE_H
