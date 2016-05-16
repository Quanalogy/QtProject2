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

private:
    QString name = "Ændre brugerprofil";

signals:
    void onSaveClick();
    void onCancelClick();
};


#endif //QTPROJECT_AENDREBRUGERPROFIL_H
