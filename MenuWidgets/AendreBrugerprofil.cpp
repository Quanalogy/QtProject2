//
// Created by Munke on 23-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include "AendreBrugerprofil.h"
//#include "../Globals.h"


AendreBrugerprofil::AendreBrugerprofil(QWidget *parent) : MenuWidget(parent) {
    this->setWindowTitle(name);
    //Add layouts
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QVBoxLayout *userLayout = new QVBoxLayout[5];
    //Labels
    QLabel *user = new QLabel(this);
    QLabel *changePass = new QLabel(this);
    QLabel *userAccess = new QLabel(this);
    //set text on labels
    user->setText("<h1>Bruger 1</h1>");
    changePass->setText("<h2>Skift kodeord</h2>");
    userAccess->setText("<h2>Bruger har adgang til</h2>");

    //inputbox for new password
    password = new QLineEdit(this);
    password->setPlaceholderText("Indtast nyt kodeord her");

    //Add checkboxes
    userLockedCheck = new QCheckBox("Bruger låst");
    deleteUserCheck = new QCheckBox("Markér for sletning");
    adfaerdsCheck = new QCheckBox("Adfærdsstyring");
    lightCheck = new QCheckBox("Lysstyring");
    activitySimCheck = new QCheckBox("Aktivitetssimulering");
    unitControlCheck = new QCheckBox("Enhedshåndtering");
    changeUserCheck = new QCheckBox("Ændre brugerprofil");
    addUserCheck = new QCheckBox("Tilføj brugerprofil");

    checkList<<addUserCheck<<changeUserCheck<<activitySimCheck<<lightCheck<<adfaerdsCheck
    << unitControlCheck;


    //Pushbuttons
    QPushButton *saveBtn = new QPushButton("Gem", this);
    QPushButton *cancelBtn = new QPushButton("Annuller", this);

    //Add buttons to horizontal layout
    buttonLayout->addWidget(cancelBtn);
    buttonLayout->addWidget(saveBtn);

    //connect buttons with signals
    connect(cancelBtn, &QPushButton::clicked, this, &AendreBrugerprofil::onCancelClick);
    connect(saveBtn, &QPushButton::clicked, this, &AendreBrugerprofil::onSaveClick);

    //Add to userlayout
   /* for (int i = 0; i <=userCount ; ++i) {


        userLayout[i].addWidget(user, 0, Qt::AlignTop);
        userLayout[i].addWidget(userLockedCheck, 0, Qt::AlignTop);
        userLayout[i].addWidget(deleteUserCheck, 0, Qt::AlignTop);
        userLayout[i].addWidget(changePass, 0, Qt::AlignCenter);
        userLayout[i].addWidget(password, 0, Qt::AlignTop);
        userLayout[i].addWidget(userAccess, 0, Qt::AlignTop);
        userLayout[i].addWidget(adfaerdsCheck, 0, Qt::AlignTop);
        userLayout[i].addWidget(addUserCheck, 0, Qt::AlignTop);
        userLayout[i].addWidget(lightCheck, 0, Qt::AlignTop);
        userLayout[i].addWidget(activitySimCheck, 0, Qt::AlignTop);
        userLayout[i].addWidget(unitControlCheck, 0, Qt::AlignTop);
        userLayout[i].addWidget(changeUserCheck, 0, Qt::AlignTop);
        mainLayout->addLayout(userLayout);

    }*/
    mainLayout->addLayout(buttonLayout);
}

QString AendreBrugerprofil::getName() {
    return name;
}

vector<bool> AendreBrugerprofil::getStates(){
        vector<bool> states;
    states.push_back(checkList.at(0));
    states.push_back(checkList.at(1));
    states.push_back(checkList.at(2));
    states.push_back(checkList.at(3));
    states.push_back(checkList.at(4));
    states.push_back(checkList.at(5));
    return states;
}

QString AendreBrugerprofil::getNewPassword() {
   QString kodeOrd= password->text();
    return kodeOrd;
}

QList<QString> getPasswords(){
    QList<QString> kodeListe;

    return  kodeListe;
}