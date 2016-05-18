//
// Created by Munke on 23-04-2016.
//

#ifndef QTPROJECT_AENDREBRUGERPROFIL_H
#define QTPROJECT_AENDREBRUGERPROFIL_H


#include "MenuWidget.h"
#include "../User.h"
#include <vector>
using namespace std;


class AendreBrugerprofil : public MenuWidget {
Q_OBJECT
public:
    AendreBrugerprofil(QWidget *parent = 0);
    QString getName();
    vector<bool> getStates(int userNum);
    QString getNewPassword();
    QList<QString> getPasswords();

private:
    QString name = "Ændre brugerprofil";
    QStringList userPages;
    QList<QLineEdit> *passwordList;
    QList<QCheckBox *> checkList;
    QMap<int, QList<QCheckBox *>> checkMap;
    QCheckBox *userLockedCheck;
    QCheckBox *deleteUserCheck;
    QCheckBox *adfaerdsCheck;
    QCheckBox *lightCheck;
    QCheckBox *activitySimCheck;
    QCheckBox *unitControlCheck;
    QCheckBox *changeUserCheck;
    QCheckBox *addUserCheck;
    QLineEdit *password;
    QLabel *user;
    QLabel *changePass;
    QLabel *userAccess;
    QList<vector<bool>> stateList;
    QList<User *> userList;

    QCheckBox *userLockedCheck1;
    QCheckBox *deleteUserCheck1;
    QCheckBox *adfaerdsCheck1;
    QCheckBox *lightCheck1;
    QCheckBox *activitySimCheck1;
    QCheckBox *unitControlCheck1;
    QCheckBox *changeUserCheck1;
    QCheckBox *addUserCheck1;
    QLineEdit *password1;
    QList<QCheckBox *> checkList1;
    QLabel *user1;
    QLabel *changePass1;
    QLabel *userAccess1;
    //QList<QList *> labels;

    QCheckBox *userLockedCheck2;
    QCheckBox *deleteUserCheck2;
    QCheckBox *adfaerdsCheck2;
    QCheckBox *lightCheck2;
    QCheckBox *activitySimCheck2;
    QCheckBox *unitControlCheck2;
    QCheckBox *changeUserCheck2;
    QCheckBox *addUserCheck2;
    QLineEdit *password2;
    QLabel *user2;
    QLabel *changePass2;
    QLabel *userAccess2;

    QCheckBox *userLockedCheck3;
    QCheckBox *deleteUserCheck3;
    QCheckBox *adfaerdsCheck3;
    QCheckBox *lightCheck3;
    QCheckBox *activitySimCheck3;
    QCheckBox *unitControlCheck3;
    QCheckBox *changeUserCheck3;
    QCheckBox *addUserCheck3;
    QLineEdit *password3;
    QLabel *user3;
    QLabel *changePass3;
    QLabel *userAccess3;

    QCheckBox *userLockedCheck4;
    QCheckBox *deleteUserCheck4;
    QCheckBox *adfaerdsCheck4;
    QCheckBox *lightCheck4;
    QCheckBox *activitySimCheck4;
    QCheckBox *unitControlCheck4;
    QCheckBox *changeUserCheck4;
    QCheckBox *addUserCheck4;
    QLineEdit *password4;
    QLabel *user4;
    QLabel *changePass4;
    QLabel *userAccess4;




};


#endif //QTPROJECT_AENDREBRUGERPROFIL_H
