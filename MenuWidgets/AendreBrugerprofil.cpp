//
// Created by Munke on 23-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include "AendreBrugerprofil.h"

AendreBrugerprofil::AendreBrugerprofil(QWidget *parent) : MenuWidget(parent) {
    this->setWindowTitle(name);
    //Add layouts
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    //Labels
    QLabel *user = new QLabel(this);
    QLabel *changePass = new QLabel(this);
    QLabel *userAccess = new QLabel(this);
    //set text on labels
    user->setText("<h1>Bruger 1</h1>");
    changePass->setText("<h2>Skift kodeord</h2>");
    userAccess->setText("<h2>Bruger har adgang til</h2>");

    //inputbox for new password
    QLineEdit *password = new QLineEdit(this);
    password->setPlaceholderText("Indtast nyt kodeord her");

    //Add checkboxes
    QCheckBox *userLockedCheck = new QCheckBox("Bruger låst");
    QCheckBox *deleteUserCheck = new QCheckBox("Markér for sletning");
    QCheckBox *adfaerdsCheck = new QCheckBox("Adfærdsstyring");
    QCheckBox *lightCheck = new QCheckBox("Lysstyring");
    QCheckBox *activitySimCheck = new QCheckBox("Aktivitetssimulering");
    QCheckBox *unitControlCheck = new QCheckBox("Enhedshåndtering");
    QCheckBox *changeUserCheck = new QCheckBox("Ændre brugerprofil");

    mainLayout->addWidget(user,0,Qt::AlignTop);
    mainLayout->addWidget(userLockedCheck,0,Qt::AlignTop);
    mainLayout->addWidget(deleteUserCheck,0,Qt::AlignTop);
    mainLayout->addWidget(changePass,0,Qt::AlignCenter);
    mainLayout->addWidget(password,0,Qt::AlignTop);
    mainLayout->addWidget(userAccess,0,Qt::AlignTop);
    mainLayout->addWidget(adfaerdsCheck,0,Qt::AlignTop);
    mainLayout->addWidget(lightCheck,0,Qt::AlignTop);
    mainLayout->addWidget(activitySimCheck,0,Qt::AlignTop);
    mainLayout->addWidget(unitControlCheck,0,Qt::AlignTop);
    mainLayout->addWidget(changeUserCheck,0,Qt::AlignTop);
}

QString AendreBrugerprofil::getName() {
    return name;
}