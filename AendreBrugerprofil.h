//
// Created by Munke on 23-04-2016.
//

#ifndef QTPROJECT_AENDREBRUGERPROFIL_H
#define QTPROJECT_AENDREBRUGERPROFIL_H


#include "MenuWidget.h"

class AendreBrugerprofil : public MenuWidget {
public:
    AendreBrugerprofil(QWidget *parent = 0);
    QString getName();

private:
    QString name = "Ændre brugerprofil";
};


#endif //QTPROJECT_AENDREBRUGERPROFIL_H
