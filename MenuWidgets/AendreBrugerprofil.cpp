//
// Created by Munke on 23-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include "AendreBrugerprofil.h"

AendreBrugerprofil::AendreBrugerprofil(QWidget *parent) : MenuWidget(parent) {
    this->setWindowTitle(name);
    //Add layouts
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
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

    //Add to main layout
    mainLayout->addWidget(user,0,Qt::AlignTop);
    mainLayout->addWidget(userLockedCheck,0,Qt::AlignTop);
    mainLayout->addWidget(deleteUserCheck,0,Qt::AlignTop);
    mainLayout->addWidget(changePass,0,Qt::AlignCenter);
    mainLayout->addWidget(password,0,Qt::AlignTop);
    mainLayout->addWidget(userAccess,0,Qt::AlignTop);
    mainLayout->addWidget(adfaerdsCheck,0,Qt::AlignTop);
    mainLayout->addWidget(addUserCheck,0,Qt::AlignTop);
    mainLayout->addWidget(lightCheck,0,Qt::AlignTop);
    mainLayout->addWidget(activitySimCheck,0,Qt::AlignTop);
    mainLayout->addWidget(unitControlCheck,0,Qt::AlignTop);
    mainLayout->addWidget(changeUserCheck,0,Qt::AlignTop);
    mainLayout->addLayout(buttonLayout);
}

QString AendreBrugerprofil::getName() {
    return name;
}

vector<bool> AendreBrugerprofil::getStates(){
        vector<bool> states;



}

QString AendreBrugerprofil::getNewPassword() {
   QString kodeOrd= password->text();
    return kodeOrd;
}