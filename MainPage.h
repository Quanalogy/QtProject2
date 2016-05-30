//
// Created by Munke on 11-04-2016.
//

#ifndef QTPROJECT_MAINPAGE_H
#define QTPROJECT_MAINPAGE_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QStackedLayout>
#include "AddUser.h"
#include "AdfaerdsStyring.h"
#include "AendreBrugerprofil.h"
#include "Aktivitetssimulering.h"
#include "Lysstyring.h"
#include "EnhedsHaandtering.h"
#include "User.h"
#include "Unit.h"
#include "Clock.h"
#include <QtWidgets/QPushButton>
#include <QtCore/QMap>
#include <vector>

using namespace std;
class MainPage : public MenuWidget{
    Q_OBJECT
public:
    MainPage(QWidget *parent = 0);
    QString getName(){return name;};
    void setupPages(User *currentUser_);
    void setUnitList(QList<Unit *> list);

public slots:
    void ChangeView();                              // a slot to handle when a button on the main window
                                                    // has been pressed
    void handleSaveClick();
    void handleCancelClick();                       // a slot to handle when cancel has been pressed
                                                    // on one of the views
    void slotAcceptUserLogin(QString&,QString&);    //checks if the username and password is known
    void addUserSave();
    void changeAdfaerdsStyringSave();
    void changeProfileSave();
    void logOut();
    void changeUnitsSave();
    void changeLightVolumeSave();
    void updateLysSettings();
    void notFirstTime();

private:
    QList<Unit *> unitsList;
    QList<User *> userList;
    QString name = "Hovedmenu";                     // the window title name
    QList<MenuWidget *> pages;                      // All the pages avialable
    QList<MenuWidget *> userMenuPages;              // an of accessible menupages, costumized to the users
                                                    // rights
    QGridLayout *gridLayout;
    QVBoxLayout *mainLayout;

    AddUser *addPage;
    AendreBrugerprofil *changeProfilePage;
    Aktivitetssimulering *aktivitetssimuleringPage;
    Lysstyring *lysstyringPage;
    AdfaerdsStyring *adfaerdsPage;
    EnhedsHaandtering *enhedsHaandteringPage;

    QList<QPushButton *> buttons;                   // a list of all the buttons the user can use
    int index;                                      // holds the current index in the menu that has
                                                    // been pressed
    QHash<QString, QString> userMap;                 // holds all the users in our program
    QString currentUserName;                        // holds the current username try
    QString currentPassword;                        // holds the current password try
    vector<bool> rights;
    QPushButton *logout;
    bool firstTimeLogin;

    QObject timer;
    void saveMessege();

    QHBoxLayout *topLayout;
    QLabel *userName;
    // QLabel *time;
    Clock *tempClock;
    QWidget *horizontalLineWidget;

    void forsteGangsVisning();

    bool firstTime;

    bool running;

};


#endif //QTPROJECT_MAINPAGE_H
