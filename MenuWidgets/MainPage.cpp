//
// Created by Munke on 11-04-2016.
//

#include <QtWidgets/QGridLayout>
#include <QtCore/QCoreApplication>
#include <QtWidgets/QMessageBox>
#include "MainPage.h"
#include "AddUser.h"
#include "AdfaerdsStyring.h"
#include "AendreBrugerprofil.h"
#include "Aktivitetssimulering.h"
#include "Lysstyring.h"
#include "EnhedsHaandtering.h"
#include "../LoginDialog.h"
#include "../User.h"


MainPage::MainPage(QWidget *parent) : MenuWidget(parent){
    this->setWindowTitle(name);

    //Test with users

    User *adminUser = new User((QString)"Admin",(QString) "Password");
    adminUser->setRights(true, true, true, true, true, true);

    // setup the login dialoag
    LoginDialog* loginDialog = new LoginDialog( this );
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
    QGridLayout *gridLayout = new QGridLayout(this);
    //create pages that needs connections to the buttons
    AddUser *addPage = new AddUser;
    AendreBrugerprofil *changeProfilePage = new AendreBrugerprofil;
    Aktivitetssimulering *aktivitetssimuleringPage = new Aktivitetssimulering;
    Lysstyring *lysstyringPage = new Lysstyring;
    AdfaerdsStyring *adfaerdsPage = new AdfaerdsStyring;
    EnhedsHaandtering *enhedsHaandteringPage = new EnhedsHaandtering;

    //input pages into QList
    pages << addPage << changeProfilePage << aktivitetssimuleringPage << lysstyringPage
            << adfaerdsPage << enhedsHaandteringPage;

    rights = adminUser->getRights();
    cout << rights.size() << endl;
    int pos = 0;
    for (auto i = pages.begin(); i != pages.end(); ++i,++pos) {
        if(!rights.at(pos)){
            pages.erase(i);
        }
    }
    cout << pos << endl;
    pos =0;
    for (auto i = pages.begin(); i != pages.end(); ++i,++pos) {

            QPushButton *btn = new QPushButton(pages[pos]->getName(), this);
            buttons << btn;
            if(pos%2 == 0){
                gridLayout->addWidget(btn, (int)floor(pos/2), 0, 0);
            } else {
                gridLayout->addWidget(btn, (int)floor(pos/2), 1, 0);
            }
            connect(buttons.at(pos), &QPushButton::clicked, this, &MainPage::ChangeView);
       // if(!rights.at(pos)){
       //     btn->hide();
       // }
    }
    cout << pos << endl;

    //Connect the buttons with the
    connect(addPage, &AddUser::onSaveClick, this, &MainPage::handleSaveClick);
    connect(changeProfilePage, &AendreBrugerprofil::onSaveClick, this, &MainPage::handleSaveClick);
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



    setLayout(gridLayout);
}

void MainPage::ChangeView() {
    index = buttons.indexOf((QPushButton*)QObject::sender());
    pages.at(index)->show();
    this->hide();
    //this->repaint();
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
    if(userMap.value(userName) == currentPassword){
        return true;
    }

    return false;
}

void MainPage::handleAddSave() {


    this->show();
    pages.at(index)->hide();
}