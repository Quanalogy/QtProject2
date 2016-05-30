//
// Created by Munke on 17-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtGui/QStaticText>
#include "AddUser.h"
#include "Clock.h"
#include "QMainApp.h"
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
    horizontelLayout = new QHBoxLayout();
    boxLayout = new QHBoxLayout();
    mainLayout = new QVBoxLayout(this);


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
    cancelBtn = new QPushButton("Annuller", this);

    //Pushbuttons for right side
    QPushButton *scanNFC = new QPushButton("Klik for at scanne NFC", this);
    saveBtn = new QPushButton("Gem", this);

    //Checkboxes for left side
    QCheckBox *adfaerdsCheck = new QCheckBox("Adfærdsstyring");
    QCheckBox *lightCheck = new QCheckBox("Lysstyring");
    QCheckBox *activityCheck = new QCheckBox("Aktivitetssimulering");
    QCheckBox *unitCheck = new QCheckBox("Enhedshåndtering");
    QCheckBox *changeUserCheck = new QCheckBox("Ændre brugerprofil");
    QCheckBox *addUser = new QCheckBox("Tilføj bruger");
    checkList << addUser << changeUserCheck << activityCheck << lightCheck << adfaerdsCheck << unitCheck;


    //Left side inputBox
    QLineEdit *usernameInput = new QLineEdit;

    // set guidance text
    usernameInput->setPlaceholderText("Indtast brugernavn her");

    //Right side Inputbox
    QLineEdit *passwordInput = new QLineEdit;
    QLineEdit *NFCIDInput = new QLineEdit(this);
    passwordInput->setMaxLength(8);
    // set guidance text
    passwordInput->setPlaceholderText("Indtast kodeord her");
    NFCIDInput->setPlaceholderText("Scannet NFC ID vises her");

    lineList<<usernameInput<<passwordInput;

    //Add widgets for left side
    leftLayout->addWidget(username);
    leftLayout->addWidget(usernameInput);
    leftLayout->addWidget(access);

    for (int i = 0 ; i < checkList.size() ; i++){


        leftLayout->addWidget(checkList.at(i));
    }

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



    setLayout(mainLayout);


}

QString AddUser::getName() {
    return name;
}

vector<bool> AddUser::getStates() {
    vector<bool> states;


    states.push_back(checkList.at(0)->isChecked());
    states.push_back(checkList.at(1)->isChecked());
    states.push_back(checkList.at(2)->isChecked());
    states.push_back(checkList.at(3)->isChecked());
    states.push_back(checkList.at(4)->isChecked());
    states.push_back(checkList.at(5)->isChecked());
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
    vector<bool> temp = currentUser_->getRights();
    for (int i = 0 ; i < lineList.size() ; i++){
        if (lineList.at(i)->text() != NULL){
            lineList.at(i)->clear();
        }

    }
    for (int i = 0 ; i < checkList.size() ; i++){
        if (checkList.at(i)->isChecked()){
            checkList.at(i)->setChecked(false);
        }
        if(temp.at(i) || currentUser_->getAdmin()){
            checkList.at(i)->setDisabled(false);
        } else {
            checkList.at(i)->setDisabled(true);
        }

    }
}

void AddUser::setCurrenUser(User *user) {
    currentUser_ = user;
}

void AddUser::setUserList(QList<User *> list) {
    userList = list;
}

bool AddUser::checkIfUserExist() {
    QString tempname = usernameInputString;
    for (int i = 0 ; i < userList.size() ; i++){
        if (checkAdmin()){
            tempname.remove("admin5555admin");

        }
        if (userList.at(i)->getName() == tempname){
            return true;
        }
    }
    return false;
}

void AddUser::setInfo(){
    if(mainLayout->count() == 4){
        mainLayout->removeWidget(horizontalLineWidget);
        mainLayout->removeItem(topLayout);
        mainLayout->removeItem(horizontelLayout);
        mainLayout->removeItem(boxLayout);

        horizontalLineWidget->deleteLater();
        topLayout->deleteLater();
        userName->deleteLater();
        tempClock->deleteLater();


    }
    topLayout = new QHBoxLayout();
    userName = new QLabel();
    tempClock = new Clock();
    horizontalLineWidget = new QWidget();

    if(static_cast<QMainApp *>qApp->getCurrentUser().getAdmin()){
        QString temp = static_cast<QMainApp *>qApp->getCurrentUser().getName() + "  (Admin)";
        userName->setText(temp);
    } else {
        userName->setText("<h4>" + static_cast<QMainApp *>qApp->getCurrentUser().getName() + "</h4>");
    }
    userName->setStyleSheet("QLabel { background-color : ; color : #a0a0a0; }");

    topLayout->addWidget(userName);
    topLayout->addWidget(tempClock);
    horizontalLineWidget->setFixedHeight(3);
    horizontalLineWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    horizontalLineWidget->setStyleSheet(QString("background-color: #c0c0c0;"));
    topLayout->setAlignment(userName,Qt::AlignLeft);

    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(horizontalLineWidget);
    mainLayout->addLayout(horizontelLayout);
    if (firstTime){
        cancelBtn->hide();
        saveBtn->setText("Næste");
    } else {
        cancelBtn->show();
        saveBtn->setText("Gem");
    }

    mainLayout->addLayout(boxLayout);
}

bool AddUser::checkAdmin(){
    if (usernameInputString != "") {
        if (usernameInputString.startsWith("admin5555admin")) {

            return true;
        } else {
            return false;
        }
    }
    return false;
}

void AddUser::setFirstTime(bool set) {
    firstTime = set;
}