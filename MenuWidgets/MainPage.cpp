//
// Created by Munke on 11-04-2016.
//

#include <QtWidgets/QGridLayout>
#include <QtCore/QCoreApplication>
#include <QtWidgets/QMessageBox>
#include "MainPage.h"
#include "../LoginDialog.h"
#include "../User.h"
#include "../Globals.h"


MainPage::MainPage(QWidget *parent) : MenuWidget(parent){
    this->setWindowTitle(name);

    //Test with users

    User *adminUser = new User((QString)"Admin",(QString) "Password");
    adminUser->setRights(true, true, true, true, true, true);

    // setup the login dialoag
    loginDialog = new LoginDialog( this );
    QString username = "Admin";
    loginDialog->setUsername(username); // optional
    userMap["Admin"] = "Password";

    connect( loginDialog,
             SIGNAL (acceptLogin(QString&,QString&,int&)),
             this,
             SLOT (slotAcceptUserLogin(QString&,QString&)));
    loginDialog->exec();

    //Keep it running while the username or / and password is wrong
    while(!slotAcceptUserLogin(currentUserName, currentPassword)){
        QMessageBox errorMessage;
        errorMessage.setText("Dit log-in forsøg er blevet afvist!");
        errorMessage.exec();
        loginDialog->exec();
    }
    //now we can make the rest when the user is logged in

    //Create layouts
    gridLayout = new QGridLayout(this);
    //create pages that needs connections to the buttons
    addPage = new AddUser;
    changeProfilePage = new AendreBrugerprofil;
    aktivitetssimuleringPage = new Aktivitetssimulering;
    lysstyringPage = new Lysstyring;
    adfaerdsPage = new AdfaerdsStyring;
    enhedsHaandteringPage = new EnhedsHaandtering;

    //input pages into QList
    pages << addPage << changeProfilePage << aktivitetssimuleringPage << lysstyringPage
            << adfaerdsPage << enhedsHaandteringPage;

    rights = adminUser->getRights();
    // start on finding the relevant menupages for the user
    int pos = 0;
    for (auto i = pages.begin(); i != pages.end(); ++i,++pos) {
        if(rights.at(pos)){
            userMenuPages << pages.at(pos);
        }
    }
    //Begin to add buttons, that map to the menupages the user has access to
    pos =0;
    for (auto i = userMenuPages.begin(); i != userMenuPages.end(); ++i,++pos) {

            QPushButton *btn = new QPushButton(userMenuPages[pos]->getName(), this);
            buttons << btn;
            if(pos%2 == 0){
                gridLayout->addWidget(btn, (int)floor(pos/2), 0, 0);
            } else {
                gridLayout->addWidget(btn, (int)floor(pos/2), 1, 0);
            }
            connect(buttons.at(pos), &QPushButton::clicked, this, &MainPage::ChangeView);
    }

    //Connect the buttons with the
    //connect(addPage, &AddUser::onSaveClick, this, &MainPage::handleSaveClick);
    connect(changeProfilePage, &AendreBrugerprofil::onSaveClick, this, &MainPage::changeProfileSave);
    connect(aktivitetssimuleringPage,&Aktivitetssimulering::onSaveClick,this,&MainPage::handleSaveClick);
    connect(lysstyringPage,&Lysstyring::onSaveClick,this,&MainPage::handleSaveClick);
    connect(adfaerdsPage,&AdfaerdsStyring::onSaveClick,this,&MainPage::handleSaveClick);
    connect(enhedsHaandteringPage,&EnhedsHaandtering::onSaveClick,this,&MainPage::handleSaveClick);


    //Connect annuller knap
    connect(addPage, &AddUser::onCancelClick, this, &MainPage::handleCancelClick);
    connect(changeProfilePage, &AendreBrugerprofil::onCancelClick, this, &MainPage::handleCancelClick);
    connect(aktivitetssimuleringPage, &Aktivitetssimulering::onCancelClick, this, &MainPage::handleCancelClick);
    connect(lysstyringPage, &Lysstyring::onCancelClick, this, &MainPage::handleCancelClick);
    connect(adfaerdsPage, &AdfaerdsStyring::onCancelClick, this, &MainPage::handleCancelClick);
    connect(enhedsHaandteringPage, &EnhedsHaandtering::onCancelClick, this, &MainPage::handleCancelClick);

    connect(addPage, &AddUser::onSaveClick, this, &MainPage::addUserSave);

    setLayout(gridLayout);
}

void MainPage::ChangeView() {
    index = buttons.indexOf((QPushButton*)QObject::sender());
    pages.at(index)->show();
    this->hide();
}

void MainPage::handleSaveClick() {
    this->show();
    pages.at(index)->hide();

}

void MainPage::handleCancelClick() {
    this->show();
    pages.at(index)->hide();
}

bool MainPage::slotAcceptUserLogin(QString &userName, QString &password) {
    //qDebug (userName_.toLatin1());
    currentUserName = userName;
    currentPassword = password;


    if(userMap.value(currentUserName) == currentPassword){
        return true;
    }

    return false;
}

void MainPage::addUserSave() {

// AddUser tempuser = pages.at(0);
    QMap<QString,QString> userCredentials= addPage->getLogin();
    QString *brugernavn= new QString(userCredentials.firstKey());
    QString *kodeord = new QString(userCredentials.value(userCredentials.firstKey()));
    if(brugernavn == NULL || *brugernavn == "" || kodeord == NULL || *kodeord == "" ){
        QMessageBox errorMessage;
        errorMessage.setText("Du skal skrive både brugernavn og kodeord!");
        errorMessage.exec();
    } else {
       // int userNumber=2;
        userMap.insert(*brugernavn,*kodeord);
        User *newUser = new User(*brugernavn,*kodeord);
        //userNumber++;
        vector<bool> userPriv= addPage->getStates();
        userCount++;
        newUser->setRights(userPriv.at(0),userPriv.at(1),userPriv.at(2),userPriv.at(3),userPriv.at(4),userPriv.at(5));
        this->show();
        pages.at(index)->hide();
    }

}
 void MainPage::changeProfileSave() {
     //bruger 1 ændring
     QString kodeOrd= changeProfilePage->getNewPassword();
     //QList<> liste;
     //liste= (userMap.keys().at(0));
     userMap.insert((userMap.keys().at(0)),kodeOrd);
    qDebug()<<userMap;


     this->show();
     pages.at(index)->hide();
 }