//
// Created by Munke on 23-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include "AendreBrugerprofil.h"
#include "../QMainApp.h"
//#include "../Globals.h"


AendreBrugerprofil::AendreBrugerprofil(QWidget *parent) : MenuWidget(parent) {
    this->setWindowTitle(name);
    int tempUCount=2;
    //Add layouts
    QHBoxLayout *subMainLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QVBoxLayout *userLayout = new QVBoxLayout;
    QVBoxLayout *userLayout2 = new QVBoxLayout;
    QVBoxLayout *userLayout3 = new QVBoxLayout;
    QVBoxLayout *userLayout4 = new QVBoxLayout;
    QVBoxLayout *userLayout5 = new QVBoxLayout;
    int size = static_cast<QMainApp *> qApp->getUserList().size();
    //Labels
    user= new QLabel(this);
    changePass= new QLabel(this);
    userAccess=new QLabel(this);

    //set text on labels
    //  for (int j = 0; j <=size ; ++j) {
   /* QList<User *> brugerliste =  static_cast<QMainApp *> qApp->getUserList();
    if(brugerliste.first().)
    {

  QString brugerNavn= brugerliste.first()->getName();
    user->setText(brugerNavn);
    changePass->setText("<h2>Skift kodeord</h2>");
    userAccess->setText("<h2>Bruger har adgang til</h2>");
    }//} */


    //inputbox for new password
    password = new QLineEdit(this);
    // for (auto i = 0; i <=5 ; ++i) {
    password->setPlaceholderText("Indtast nyt kodeord her");
    // }

    //Add checkboxes
    userLockedCheck= new QCheckBox("Bruger låst");
    //userLockedCheck1= new QCheckBox("Bruger låst");
    addUserCheck= new QCheckBox("Tilføj brugerprofil");
    //addUserCheck1= new QCheckBox("Tilføj brugerprofil");
    changeUserCheck= new QCheckBox("Ændre brugerprofil");
    //changeUserCheck1= new QCheckBox("Ændre brugerprofil");
    activitySimCheck= new QCheckBox("Aktivitetssimulering");
    //activitySimCheck1= new QCheckBox("Aktivitetssimulering");
    lightCheck= new QCheckBox("Lysstyring");
    //lightCheck1= new QCheckBox("Lysstyring");
    adfaerdsCheck= new QCheckBox("Adfærdsstyring");
   // adfaerdsCheck1= new QCheckBox("Adfærdsstyring");
    unitControlCheck= new QCheckBox("Enhedshåndtering");
   // unitControlCheck1= new QCheckBox("Enhedshåndtering");
    deleteUserCheck= new QCheckBox("Fjern bruger");
   // deleteUserCheck1= new QCheckBox("Fjern bruger");
userPages<<"Bruger låst"<<"Tilføj brugerprofil"<<"Ændre brugerprofil"<<"Aktivitetssimulering"
<<"Lysstyring"<<"Adfærdsstyring"<<"Enhedshåndtering"<<"Fjern bruger";

   /* for (int i = 0; i <size; ++i) {
        checkList<<addUserCheck<<changeUserCheck<<activitySimCheck<<lightCheck
        <<adfaerdsCheck << unitControlCheck<<userLockedCheck;
    }
*/

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
   // for (int l = 0; l <size; ++l) {
   /* int u=0;
    for (auto j = userPages.begin(); j !=userPages.end() ; ++j,++u) {
        userLockedCheck = new QCheckBox(userPages.at(u));
        deleteUserCheck = new QCheckBox(userPages.at(u));
    }*/

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

    /*
    userLayout->addWidget(user1, 0, Qt::AlignTop);
    userLayout->addWidget(userLockedCheck1, 0, Qt::AlignTop);
    userLayout->addWidget(deleteUserCheck1, 0, Qt::AlignTop);
    userLayout->addWidget(changePass, 0, Qt::AlignCenter);
    userLayout->addWidget(password, 0, Qt::AlignTop);
    userLayout->addWidget(userAccess, 0, Qt::AlignTop);
    userLayout->addWidget(adfaerdsCheck, 0, Qt::AlignTop);
    userLayout->addWidget(addUserCheck, 0, Qt::AlignTop);
    userLayout->addWidget(lightCheck, 0, Qt::AlignTop);
    userLayout->addWidget(activitySimCheck, 0, Qt::AlignTop);
    userLayout->addWidget(unitControlCheck, 0, Qt::AlignTop);
    userLayout->addWidget(changeUserCheck, 0, Qt::AlignTop);
    */
    subMainLayout->addLayout(userLayout);
        mainLayout->addLayout(subMainLayout);
        mainLayout->addLayout(buttonLayout);
        setLayout(mainLayout);
   // }
}

QString AendreBrugerprofil::getName() {
    return name;
}

/*vector<bool> AendreBrugerprofil::getStates(int userNum){
    vector<bool> states;
    states.push_back(checkList[userNum].at(0));
    states.push_back(checkList[userNum].at(1));
    states.push_back(checkList[userNum].at(2));
    states.push_back(checkList[userNum].at(3));
    states.push_back(checkList[userNum].at(4));
    states.push_back(checkList[userNum].at(5));
    return states;
}*/

//QString AendreBrugerprofil::getNewPassword() {
//QString kodeOrd= password->text();
//return kodeOrd;
//}

QList<QString> AendreBrugerprofil::getPasswords(){
    QList<QString> kodeListe;
    kodeListe<<passwordList->at(0).text()<<passwordList->at(1).text()<<passwordList->at(2).text()<<passwordList->at(3).text()
            <<passwordList->at(4).text();
    return  kodeListe;
}