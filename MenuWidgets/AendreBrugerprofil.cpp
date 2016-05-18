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
    int tempUCount=2;
    //Add layouts
    QHBoxLayout *subMainLayout = new QHBoxLayout();
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QVBoxLayout *userLayout = new QVBoxLayout;
    QVBoxLayout *userLayout2 = new QVBoxLayout;
    QVBoxLayout *userLayout3 = new QVBoxLayout;
    QVBoxLayout *userLayout4 = new QVBoxLayout;
    QVBoxLayout *userLayout5 = new QVBoxLayout;
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

        userLayout->addWidget(user, 0, Qt::AlignTop);
        userLayout->addWidget(userLockedCheck, 0, Qt::AlignTop);
        userLayout->addWidget(deleteUserCheck, 0, Qt::AlignTop);
        userLayout->addWidget(changePass, 0, Qt::AlignCenter);
        userLayout->addWidget(password, 0, Qt::AlignTop);
        userLayout->addWidget(userAccess, 0, Qt::AlignTop);
        userLayout->addWidget(adfaerdsCheck, 0, Qt::AlignTop);
        userLayout->addWidget(addUserCheck, 0, Qt::AlignTop);
        userLayout->addWidget(lightCheck, 0, Qt::AlignTop);
        userLayout->addWidget(activitySimCheck, 0, Qt::AlignTop);
        userLayout->addWidget(unitControlCheck, 0, Qt::AlignTop);
        userLayout->addWidget(changeUserCheck, 0, Qt::AlignTop);
        subMainLayout->addLayout(userLayout);
    if(tempUCount>=2)
    {
        userLayout2->addWidget(user, 0, Qt::AlignTop);
        userLayout2->addWidget(userLockedCheck, 0, Qt::AlignTop);
        userLayout2->addWidget(deleteUserCheck, 0, Qt::AlignTop);
        userLayout2->addWidget(changePass, 0, Qt::AlignCenter);
        userLayout2->addWidget(password, 0, Qt::AlignTop);
        userLayout2->addWidget(userAccess, 0, Qt::AlignTop);
        userLayout2->addWidget(adfaerdsCheck, 0, Qt::AlignTop);
        userLayout2->addWidget(addUserCheck, 0, Qt::AlignTop);
        userLayout2->addWidget(lightCheck, 0, Qt::AlignTop);
        userLayout2->addWidget(activitySimCheck, 0, Qt::AlignTop);
        userLayout2->addWidget(unitControlCheck, 0, Qt::AlignTop);
        userLayout2->addWidget(changeUserCheck, 0, Qt::AlignTop);
        subMainLayout->addLayout(userLayout2);
        if(tempUCount>=3)
        {
            userLayout3->addWidget(user, 0, Qt::AlignTop);
            userLayout3->addWidget(userLockedCheck, 0, Qt::AlignTop);
            userLayout3->addWidget(deleteUserCheck, 0, Qt::AlignTop);
            userLayout3->addWidget(changePass, 0, Qt::AlignCenter);
            userLayout3->addWidget(password, 0, Qt::AlignTop);
            userLayout3->addWidget(userAccess, 0, Qt::AlignTop);
            userLayout3->addWidget(adfaerdsCheck, 0, Qt::AlignTop);
            userLayout3->addWidget(addUserCheck, 0, Qt::AlignTop);
            userLayout3->addWidget(lightCheck, 0, Qt::AlignTop);
            userLayout3->addWidget(activitySimCheck, 0, Qt::AlignTop);
            userLayout3->addWidget(unitControlCheck, 0, Qt::AlignTop);
            userLayout3->addWidget(changeUserCheck, 0, Qt::AlignTop);
            subMainLayout->addLayout(userLayout3);
            if(tempUCount>=4)
            {
                userLayout4->addWidget(user, 0, Qt::AlignTop);
                userLayout4->addWidget(userLockedCheck, 0, Qt::AlignTop);
                userLayout4->addWidget(deleteUserCheck, 0, Qt::AlignTop);
                userLayout4->addWidget(changePass, 0, Qt::AlignCenter);
                userLayout4->addWidget(password, 0, Qt::AlignTop);
                userLayout4->addWidget(userAccess, 0, Qt::AlignTop);
                userLayout4->addWidget(adfaerdsCheck, 0, Qt::AlignTop);
                userLayout4->addWidget(addUserCheck, 0, Qt::AlignTop);
                userLayout4->addWidget(lightCheck, 0, Qt::AlignTop);
                userLayout4->addWidget(activitySimCheck, 0, Qt::AlignTop);
                userLayout4->addWidget(unitControlCheck, 0, Qt::AlignTop);
                userLayout4->addWidget(changeUserCheck, 0, Qt::AlignTop);
                subMainLayout->addLayout(userLayout4);
                if(tempUCount>=5)
                {
                    userLayout5->addWidget(user, 0, Qt::AlignTop);
                    userLayout5->addWidget(userLockedCheck, 0, Qt::AlignTop);
                    userLayout5->addWidget(deleteUserCheck, 0, Qt::AlignTop);
                    userLayout5->addWidget(changePass, 0, Qt::AlignCenter);
                    userLayout5->addWidget(password, 0, Qt::AlignTop);
                    userLayout5->addWidget(userAccess, 0, Qt::AlignTop);
                    userLayout5->addWidget(adfaerdsCheck, 0, Qt::AlignTop);
                    userLayout5->addWidget(addUserCheck, 0, Qt::AlignTop);
                    userLayout5->addWidget(lightCheck, 0, Qt::AlignTop);
                    userLayout5->addWidget(activitySimCheck, 0, Qt::AlignTop);
                    userLayout5->addWidget(unitControlCheck, 0, Qt::AlignTop);
                    userLayout5->addWidget(changeUserCheck, 0, Qt::AlignTop);
                    subMainLayout->addLayout(userLayout5);
                }
            }
        }
    }
        mainLayout->addLayout(subMainLayout);
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