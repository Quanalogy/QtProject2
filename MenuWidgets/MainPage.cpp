//
// Created by Munke on 11-04-2016.
//

#include <QtWidgets/QGridLayout>
#include <QtCore/QCoreApplication>
#include <QtWidgets/QMessageBox>
#include "MainPage.h"
#include "../QMainApp.h"
#include "../Globals.h"


MainPage::MainPage(QWidget *parent) : MenuWidget(parent){
    this->setWindowTitle(name);

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



    //Connect the buttons with the
    connect(changeProfilePage, &AendreBrugerprofil::onSaveClick, this, &MainPage::changeProfileSave);
    connect(aktivitetssimuleringPage,&Aktivitetssimulering::onSaveClick,this,&MainPage::handleSaveClick);
    connect(lysstyringPage,&Lysstyring::onSaveClick,this,&MainPage::changeLightVolumeSave);
    connect(adfaerdsPage,&AdfaerdsStyring::onSaveClick,this,&MainPage::changeAdfaerdsStyringSave);
    connect(enhedsHaandteringPage,&EnhedsHaandtering::onSaveClick,this,&MainPage::changeUnitsSave);
    connect(addPage, &AddUser::onSaveClick, this, &MainPage::addUserSave);


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
    QString enhed = "Enhedshåndtering";
    QString lys = "Lysstyring";
    if (pages.at(index)->getName() == enhed){

        enhedsHaandteringPage->setUnitsList(unitsList);
        enhedsHaandteringPage->removeBox();
        enhedsHaandteringPage->addBox();

    }
    if (pages.at(index)->getName() == lys){

        lysstyringPage->setUnitsList(unitsList);
        lysstyringPage->removeBox();
        lysstyringPage->addBox();

    }
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

void MainPage::slotAcceptUserLogin(QString &userName, QString &password) {
    cout << "Welcome to MainPage" << endl;
    currentUserName = userName;
    currentPassword = password;
    QList<User *> tempUserList = static_cast<QMainApp *>qApp->getUserList();



    for (int i = 0; i <tempUserList.size() ; ++i) {
        if(tempUserList.at(i)->getName()==currentUserName){
            setupPages(tempUserList.at(i));
            qDebug() << tempUserList.at(i);
            qDebug() << tempUserList.size();
        }
    }
    this->show();
    //return false;


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
        userMap.insert(*brugernavn,*kodeord);
        User *newUser = new User(*brugernavn,*kodeord);
        static_cast<QMainApp *> qApp->addUserToList(newUser);
        vector<bool> userPriv= addPage->getStates();
        //userCount++;
        newUser->setRights(userPriv.at(0),userPriv.at(1),userPriv.at(2),userPriv.at(3),userPriv.at(4),userPriv.at(5));
        this->show();
        pages.at(index)->hide();
    }

}

void MainPage::changeAdfaerdsStyringSave()  {
    if(!adfaerdsPage->notNull()){
        QMessageBox errorMessage;
        errorMessage.setText("Stattiden for dagsprofil må ikke være 0!");
        errorMessage.exec();
    } else {
        this->show();
        pages.at(index)->hide();
    }

}

void MainPage::changeProfileSave() {
    //bruger 1 ændring
    QList<QString> kodeOrd= changeProfilePage->getPasswords();

    int size = static_cast<QMainApp *> qApp->getUserList().size();
    QList<User *> bruger=static_cast<QMainApp *> qApp->getUserList();
    vector<bool> userPriv;
    QList<QString > userPassword=(changeProfilePage->getPasswords());
    for (int i = 0; i < size; ++i) {
        userPriv=changeProfilePage->getStates(i);
        if(userPassword.at(i)!=NULL) {
            bruger.at(i)->setRights(userPriv.at(2), userPriv.at(3), userPriv.at(4), userPriv.at(5), userPriv.at(6), userPriv.at(7));
            QString brugerNavn=bruger.at(i)->getName();
            userMap.insert(brugerNavn,userPassword.at(i));
        }
    }
    this->show();
    pages.at(index)->hide();
}

void MainPage::changeUnitsSave()  {
    if(enhedsHaandteringPage->notNull()){
        QMessageBox errorMessage;
        errorMessage.setText("Du skal angive serienummer og rum/lokation for at tilføje, eller krydse af for at fjerne");
        errorMessage.exec();
    } else {
        int ID = enhedsHaandteringPage->getEditLineID();
        QString Name = enhedsHaandteringPage->getEditLineName();
        if (ID >= 0 && Name.toStdString().size() > 0 ) {
            unitsList.append(new Unit(ID, Name));
            enhedsHaandteringPage->setUnitsList(unitsList);
        }
        enhedsHaandteringPage->removeIfChecked();
        unitsList = enhedsHaandteringPage->getUnitsList();
        this->show();
        pages.at(index)->hide();
    }
}

void MainPage::changeLightVolumeSave() {
    lysstyringPage->checkIfCheckedAddVolume();
    this->show();
    pages.at(index)->hide();
}

void MainPage::setupPages(User *currentUser_) {
    rights = currentUser_->getRights();
    int pos = 0;

    // start on finding the relevant menupages for the user
    pos = 0;
    for (auto i = pages.begin(); i != pages.end(); ++i,++pos) {
        if(rights.at(pos)){
            userMenuPages << pages.at(pos);
        }
    }
    logout  = new QPushButton("Log ud", this);
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
    gridLayout->addWidget(logout);

    connect(logout, &QPushButton::clicked, this, &logOut);
}

void MainPage::logOut() {
    for(QPushButton *pushButton : buttons ){ // loop to remove the extras buttons
        pushButton->deleteLater();
    }
    logout->deleteLater();
    buttons.clear();
    userMenuPages.clear();
    this->hide();
    static_cast<QMainApp *>qApp->getLogin()->showMe();
}