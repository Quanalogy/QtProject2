//
// Created by Munke on 23-04-2016.
//

#ifndef QTPROJECT_AENDREBRUGERPROFIL_H
#define QTPROJECT_AENDREBRUGERPROFIL_H


#include "MenuWidget.h"


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
    QCheckBox *userLockedCheck;
    QCheckBox *deleteUserCheck;
    QCheckBox *adfaerdsCheck;
    QCheckBox *lightCheck;
    QCheckBox *activitySimCheck;
    QCheckBox *unitControlCheck;
    QCheckBox *changeUserCheck;
    QCheckBox *addUserCheck;
    QList<QLineEdit> *passwordList;
    QList<QCheckBox *> checkList[];
    QLineEdit *password;
    QLabel *user;
    QLabel *changePass;
    QLabel *userAccess;

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



};


#endif //QTPROJECT_AENDREBRUGERPROFIL_H
