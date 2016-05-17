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
    vector<bool> getStates();
    QString getNewPassword();
    QList<QString> getPasswords();

private:
    QString name = "Ændre brugerprofil";
    QCheckBox *userLockedCheck;
    QCheckBox *deleteUserCheck;
    QCheckBox *adfaerdsCheck;
    QCheckBox *lightCheck;
    QCheckBox *activitySimCheck;
    QCheckBox *unitControlCheck;
    QCheckBox *changeUserCheck;
    QCheckBox *addUserCheck;
    QLineEdit *password;
    QList<QCheckBox *> checkList;


signals:
    void onSaveClick();
    void onCancelClick();
};


#endif //QTPROJECT_AENDREBRUGERPROFIL_H
