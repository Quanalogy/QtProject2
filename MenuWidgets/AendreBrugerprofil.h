//
// Created by Munke on 23-04-2016.
//

#ifndef QTPROJECT_AENDREBRUGERPROFIL_H
#define QTPROJECT_AENDREBRUGERPROFIL_H


#include "MenuWidget.h"
#include "../User.h"
#include "../Clock.h"
#include <vector>
using namespace std;


class AendreBrugerprofil : public MenuWidget {
Q_OBJECT
public:
    AendreBrugerprofil(QWidget *parent = 0);
    QString getName();
    vector<bool> getStates(int userNum);
    QString getNewPassword();
    QList<QString *> getPasswords();
    void setUserList(QList<User * > list);
    QList<User * > getUserlist();
    void addLayouts();
    void removeLayouts();
    void makeChanges();
    bool adminCheck();
    void clear();
    void setCurrenUser(User *user);

private:
    QString name = "Ændre brugerprofil";
    QStringList userPages;
    QList<QLineEdit> *passwordList;
    QMap<int, QList<QCheckBox *>> checkMap;
    QList<QCheckBox *> checkboxList;
    QList<QList<QCheckBox *>> listCheckboxList;
    QLineEdit *password;
    QLabel *user;
    QLabel *changePass;
    QLabel *userAccess;

    QHBoxLayout *subMainLayout;
    QVBoxLayout *mainLayout;

    QList<QVBoxLayout *> userLayouts;

    QList<QLabel *> userLabels;
    QList<QLabel *> changePassLabels;
    QList<QLabel *> userAccessLabels;
    QList<QLineEdit *> passwords;


    QList<vector<bool>> stateList;

    QList<User * > userList;                 // holds all the users in our program
    User *currentUser;                        // holds the current username try
    QString currentPassword;                        // holds the current password try
    vector<bool> rights;
    QPushButton *logout;
    bool firstTimeLogin;

    int layoutsCount;

    QHBoxLayout *buttonLayout;
    QHBoxLayout *topLayout;
    QLabel *userName;
    Clock *tempClock;
    QWidget *horizontalLineWidget;



};


#endif //QTPROJECT_AENDREBRUGERPROFIL_H
