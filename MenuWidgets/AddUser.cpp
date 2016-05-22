//
// Created by Munke on 17-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtGui/QStaticText>
#include "AddUser.h"
#include <QDialog>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>





AddUser::AddUser(QWidget *parent) : MenuWidget(parent){
    this->setWindowTitle(name);
    //Create layouts for the page
    QVBoxLayout *leftLayout = new QVBoxLayout();
    QVBoxLayout *rightLayout = new QVBoxLayout();
    QHBoxLayout *horizontelLayout = new QHBoxLayout();
    QHBoxLayout *boxLayout = new QHBoxLayout();
    QVBoxLayout *mainLayout = new QVBoxLayout(this);


    //Begin with labels for left side
    QLabel *username = new QLabel(this);
    QLabel *access = new QLabel(this);
    //set text for labels
    username->setText("<h1>Brugernavn</h1>");
    access->setText("<h2>Bruger har adgang til</h2>");

    //Begin with labels for right side
    QLabel *password = new QLabel(this);
    QLabel *connectNFC = new QLabel(this);
    QLabel *NFCID = new QLabel(this);
    // set text
    password->setText("<h1>Angiv kode</h1>");
    connectNFC->setText("<h2>Tilknyt NFC til bruger</h2>");
    NFCID->setText("<h2>Scannet NFC ID</h2>");

    //Pushbuttons for left side
    QPushButton *cancelBtn = new QPushButton("Annuller", this);

    //Pushbuttons for right side
    QPushButton *scanNFC = new QPushButton("Klik for at scanne NFC", this);
    QPushButton *saveBtn = new QPushButton("Gem", this);

    //Checkboxes for left side
    QCheckBox *adfaerdsCheck = new QCheckBox("Adfærdsstyring");
    QCheckBox *lightCheck = new QCheckBox("Lysstyring");
    QCheckBox *activityCheck = new QCheckBox("Aktivitetssimulering");
    QCheckBox *unitCheck = new QCheckBox("Enhedshåndtering");
    QCheckBox *changeUserCheck = new QCheckBox("Ændre brugerprofil");
    QCheckBox *addUser = new QCheckBox("Tilføj bruger");
    checkList << adfaerdsCheck <<lightCheck<<activityCheck<<unitCheck<<changeUserCheck
              << addUser;

    //Left side inputBox
    QLineEdit *usernameInput = new QLineEdit;

    // set guidance text
    usernameInput->setPlaceholderText("Indtast brugernavn her");

    //Right side Inputbox
    QLineEdit *passwordInput = new QLineEdit;
    QLineEdit *NFCIDInput = new QLineEdit(this);
    // set guidance text
    passwordInput->setPlaceholderText("Indtast kodeord her");
    NFCIDInput->setPlaceholderText("Scannet NFC ID vises her");

    lineList<<usernameInput<<passwordInput;

    //Add widgets for left side
    leftLayout->addWidget(username);
    leftLayout->addWidget(usernameInput);
    leftLayout->addWidget(access);
    leftLayout->addWidget(addUser);
    leftLayout->addWidget(adfaerdsCheck);
    leftLayout->addWidget(lightCheck);
    leftLayout->addWidget(activityCheck);
    leftLayout->addWidget(unitCheck);
    leftLayout->addWidget(changeUserCheck);


    //Add widgets for right side
    rightLayout->addWidget(password);
    rightLayout->addWidget(passwordInput);
    rightLayout->addWidget(connectNFC);
    rightLayout->addWidget(scanNFC);
    rightLayout->addWidget(NFCID);
    rightLayout->addWidget(NFCIDInput);

    boxLayout->addWidget(cancelBtn);
    boxLayout->addWidget(saveBtn);

    //Alignment to make it look not so horrible.
    /*username->setAlignment(Qt::AlignTop);
    usernameInput->setAlignment(Qt::AlignTop);
    password->setAlignment(Qt::AlignTop);
    passwordInput->setAlignment(Qt::AlignTop);
    NFCID->setAlignment(Qt::AlignBottom);*/

    //Connect buttons
    connect(saveBtn, &QPushButton::clicked, this, &AddUser::onSaveClick);
    connect(cancelBtn, &QPushButton::clicked, this, &AddUser::onCancelClick);

    //Add layouts
    leftLayout->setAlignment(Qt::AlignTop);
    rightLayout->setAlignment(Qt::AlignTop);
    horizontelLayout->addLayout(leftLayout);
    horizontelLayout->addLayout(rightLayout);
    mainLayout->addLayout(horizontelLayout);
    mainLayout->addLayout(boxLayout);

    setLayout(mainLayout);


}

QString AddUser::getName() {
    return name;
}

vector<bool> AddUser::getStates() {
    vector<bool> states;


    states.push_back(checkList.at(5)->isChecked());
    states.push_back(checkList.at(4)->isChecked());
    states.push_back(checkList.at(2)->isChecked());
    states.push_back(checkList.at(1)->isChecked());
    states.push_back(checkList.at(0)->isChecked());
    states.push_back(checkList.at(3)->isChecked());
    return states;
}

QMap<QString,QString> AddUser::getLogin(){
    usernameInputString = lineList.at(0)->text();
    passwordInputString = lineList.at(1)->text();
    QMap<QString,QString> credentials;
    credentials[usernameInputString] = passwordInputString;
    return credentials;
}

void AddUser::clear() {
    for (int i = 0 ; i < lineList.size() ; i++){
        if (lineList.at(i)->text() != NULL){
            lineList.at(i)->clear();
        }

    }
    for (int i = 0 ; i < checkList.size() ; i++){
        if (checkList.at(i)->isChecked()){
            checkList.at(i)->setChecked(false);
        }

    }
}