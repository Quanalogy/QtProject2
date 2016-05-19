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
    QList<QList<QCheckBox *> *> checkList;
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





};


#endif //QTPROJECT_AENDREBRUGERPROFIL_H
