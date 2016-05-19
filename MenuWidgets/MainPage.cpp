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

    //Test with users



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
    //connect(addPage, &AddUser::onSaveClick, this, &MainPage::handleSaveClick);
    connect(changeProfilePage, &AendreBrugerprofil::onSaveClick, this, &MainPage::changeProfileSave);
    connect(aktivitetssimuleringPage,&Aktivitetssimulering::onSaveClick,this,&MainPage::handleSaveClick);
    connect(lysstyringPage,&Lysstyring::onSaveClick,this,&MainPage::handleSaveClick);
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
    QString temp = "Enhedshåndtering";
    qDebug() << pages.at(index) << temp;
    if (pages.at(index)->getName() == temp){
        cout << "to change, size:" << unitsList.size() << endl;
        if (enhedsHaandteringPage->isChecked()) {
            enhedsHaandteringPage->removeBox();
            this->hide();
        } else {
            enhedsHaandteringPage->setUnitsList(unitsList);
            enhedsHaandteringPage->addBox();
        }

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

bool MainPage::slotAcceptUserLogin(QString &userName, QString &password) {
    //qDebug (userName_.toLatin1());
    this->show();
    cout << "Works" << endl;
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
     //QList<> liste;
     //liste= (userMap.keys().at(0));
     //userMap.insert((userMap.keys().at(0)),kodeOrd.at(0));

    //qDebug()<<userMap;
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
        qDebug() << Name << ID;
        if (ID >= 0 && Name.toStdString().size() > 0 ) {
            cout << "test1" << endl;
            unitsList.append(new Unit(ID, Name));
            enhedsHaandteringPage->setUnitsList(unitsList);
        }
        cout << unitsList.size() << endl;
        cout << "test2" << endl;
        enhedsHaandteringPage->removeIfChecked();
        unitsList = enhedsHaandteringPage->getUnitsList();
        this->show();
        pages.at(index)->hide();
    }
}

void MainPage::setupPages(User *currentUser_) {
    rights = currentUser_->getRights();
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
}