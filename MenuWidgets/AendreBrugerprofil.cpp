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
    user[5] = new QLabel(this);
    changePass[5] = new QLabel(this);
    userAccess[5] = new QLabel(this);
    //set text on labels
    for (int j = 0; j <=5 ; ++j) {
        user[j]->setText("<h1>Bruger 1</h1>");
        changePass[j]->setText("<h2>Skift kodeord</h2>");
        userAccess[j]->setText("<h2>Bruger har adgang til</h2>");
    }


    //inputbox for new password
    password[5] = new QLineEdit(this);
    for (auto i = 0; i <=5 ; ++i) {
        password[i]->setPlaceholderText("Indtast nyt kodeord her");
    }

    //Add checkboxes
    userLockedCheck[5] = new QCheckBox("Bruger låst");
    deleteUserCheck[5] = new QCheckBox("Markér for sletning");
    adfaerdsCheck[5] = new QCheckBox("Adfærdsstyring");
    lightCheck[5] = new QCheckBox("Lysstyring");
    activitySimCheck[5] = new QCheckBox("Aktivitetssimulering");
    unitControlCheck[5] = new QCheckBox("Enhedshåndtering");
    changeUserCheck[5] = new QCheckBox("Ændre brugerprofil");
    addUserCheck[5] = new QCheckBox("Tilføj brugerprofil");
    for (int i = 0; i <=5 ; ++i) {
        checkList[i]<<addUserCheck[i]<<changeUserCheck[i]<<activitySimCheck[i]<<lightCheck[i]
        <<adfaerdsCheck[i] << unitControlCheck[i];
    }


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

        userLayout->addWidget(user[0], 0, Qt::AlignTop);
        userLayout->addWidget(userLockedCheck[0], 0, Qt::AlignTop);
        userLayout->addWidget(deleteUserCheck[0], 0, Qt::AlignTop);
        userLayout->addWidget(changePass[0], 0, Qt::AlignCenter);
        userLayout->addWidget(password[0], 0, Qt::AlignTop);
        userLayout->addWidget(userAccess[0], 0, Qt::AlignTop);
        userLayout->addWidget(adfaerdsCheck[0], 0, Qt::AlignTop);
        userLayout->addWidget(addUserCheck[0], 0, Qt::AlignTop);
        userLayout->addWidget(lightCheck[0], 0, Qt::AlignTop);
        userLayout->addWidget(activitySimCheck[0], 0, Qt::AlignTop);
        userLayout->addWidget(unitControlCheck[0], 0, Qt::AlignTop);
        userLayout->addWidget(changeUserCheck[0], 0, Qt::AlignTop);
        subMainLayout->addLayout(userLayout);
    if(tempUCount>=2)
    {
        userLayout2->addWidget(user[1], 0, Qt::AlignTop);
        userLayout2->addWidget(userLockedCheck[1], 0, Qt::AlignTop);
        userLayout2->addWidget(deleteUserCheck[1], 0, Qt::AlignTop);
        userLayout2->addWidget(changePass[1], 0, Qt::AlignCenter);
        userLayout2->addWidget(password[1], 0, Qt::AlignTop);
        userLayout2->addWidget(userAccess[1], 0, Qt::AlignTop);
        userLayout2->addWidget(adfaerdsCheck[1], 0, Qt::AlignTop);
        userLayout2->addWidget(addUserCheck[1], 0, Qt::AlignTop);
        userLayout2->addWidget(lightCheck[1], 0, Qt::AlignTop);
        userLayout2->addWidget(activitySimCheck[1], 0, Qt::AlignTop);
        userLayout2->addWidget(unitControlCheck[1], 0, Qt::AlignTop);
        userLayout2->addWidget(changeUserCheck[1], 0, Qt::AlignTop);
        subMainLayout->addLayout(userLayout2);
        if(tempUCount>=3)
        {
            userLayout3->addWidget(user[2], 0, Qt::AlignTop);
            userLayout3->addWidget(userLockedCheck[2], 0, Qt::AlignTop);
            userLayout3->addWidget(deleteUserCheck[2], 0, Qt::AlignTop);
            userLayout3->addWidget(changePass[2], 0, Qt::AlignCenter);
            userLayout3->addWidget(password[2], 0, Qt::AlignTop);
            userLayout3->addWidget(userAccess[2], 0, Qt::AlignTop);
            userLayout3->addWidget(adfaerdsCheck[2], 0, Qt::AlignTop);
            userLayout3->addWidget(addUserCheck[2], 0, Qt::AlignTop);
            userLayout3->addWidget(lightCheck[2], 0, Qt::AlignTop);
            userLayout3->addWidget(activitySimCheck[2], 0, Qt::AlignTop);
            userLayout3->addWidget(unitControlCheck[2], 0, Qt::AlignTop);
            userLayout3->addWidget(changeUserCheck[2], 0, Qt::AlignTop);
            subMainLayout->addLayout(userLayout3);
            if(tempUCount>=4)
            {
                userLayout4->addWidget(user[3], 0, Qt::AlignTop);
                userLayout4->addWidget(userLockedCheck[3], 0, Qt::AlignTop);
                userLayout4->addWidget(deleteUserCheck[3], 0, Qt::AlignTop);
                userLayout4->addWidget(changePass[3], 0, Qt::AlignCenter);
                userLayout4->addWidget(password[3], 0, Qt::AlignTop);
                userLayout4->addWidget(userAccess[3], 0, Qt::AlignTop);
                userLayout4->addWidget(adfaerdsCheck[3], 0, Qt::AlignTop);
                userLayout4->addWidget(addUserCheck[3], 0, Qt::AlignTop);
                userLayout4->addWidget(lightCheck[3], 0, Qt::AlignTop);
                userLayout4->addWidget(activitySimCheck[3], 0, Qt::AlignTop);
                userLayout4->addWidget(unitControlCheck[3], 0, Qt::AlignTop);
                userLayout4->addWidget(changeUserCheck[3], 0, Qt::AlignTop);
                subMainLayout->addLayout(userLayout4);
                if(tempUCount>=5)
                {
                    userLayout5->addWidget(user[4], 0, Qt::AlignTop);
                    userLayout5->addWidget(userLockedCheck[4], 0, Qt::AlignTop);
                    userLayout5->addWidget(deleteUserCheck[4], 0, Qt::AlignTop);
                    userLayout5->addWidget(changePass[4], 0, Qt::AlignCenter);
                    userLayout5->addWidget(password[4], 0, Qt::AlignTop);
                    userLayout5->addWidget(userAccess[4], 0, Qt::AlignTop);
                    userLayout5->addWidget(adfaerdsCheck[4], 0, Qt::AlignTop);
                    userLayout5->addWidget(addUserCheck[4], 0, Qt::AlignTop);
                    userLayout5->addWidget(lightCheck[4], 0, Qt::AlignTop);
                    userLayout5->addWidget(activitySimCheck[4], 0, Qt::AlignTop);
                    userLayout5->addWidget(unitControlCheck[4], 0, Qt::AlignTop);
                    userLayout5->addWidget(changeUserCheck[4], 0, Qt::AlignTop);
                    subMainLayout->addLayout(userLayout5);
                }
            }
        }
    }
        mainLayout->addLayout(subMainLayout);
        mainLayout->addLayout(buttonLayout);
        setLayout(mainLayout);
}

QString AendreBrugerprofil::getName() {
    return name;
}

vector<bool> AendreBrugerprofil::getStates(int userNum){
        vector<bool> states;
    states.push_back(checkList[userNum].at(0));
    states.push_back(checkList[userNum].at(1));
    states.push_back(checkList[userNum].at(2));
    states.push_back(checkList[userNum].at(3));
    states.push_back(checkList[userNum].at(4));
    states.push_back(checkList[userNum].at(5));
    return states;
}

//QString AendreBrugerprofil::getNewPassword() {
   //QString kodeOrd= password->text();
    //return kodeOrd;
//}

QList<QString> AendreBrugerprofil::getPasswords(){
    QList<QString> kodeListe;
    kodeListe<<password[0]->text()<<password[1]->text()<<password[2]->text()<<password[3]->text()
            <<password[4]->text();
    return  kodeListe;
}