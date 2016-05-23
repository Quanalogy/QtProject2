//
// Created by Munke on 11-04-2016.
//

#include <QtWidgets/QGridLayout>
#include <QtCore/QCoreApplication>
#include <QtWidgets/QMessageBox>
#include <QtCore/QObject>
#include <QtGui/QTextLine>
#include "MainPage.h"
#include "../QMainApp.h"
#include "../Globals.h"
#include "AdminUser.h"


MainPage::MainPage(QWidget *parent) : MenuWidget(parent){
    this->setWindowTitle(name);

    //Create layouts
    mainLayout = new QVBoxLayout(this);
    gridLayout = new QGridLayout();
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


    setLayout(mainLayout);

    //[[TESTER]] Adder 3 enheder
    unitsList.append(new Unit(1337, "Stuen"));
    unitsList.append(new Unit(666, "Toilet"));
    unitsList.append(new Unit(101010, "Sovevaerelse"));
}

void MainPage::ChangeView() {
    index = buttons.indexOf((QPushButton*)QObject::sender());
    QString enhed = "Enhedshåndtering";
    QString lys = "Lysstyring";
    QString adfaerd = "Adfærdsstyring";
    QString Aendre = "Ændre brugerprofil";
    QString adduser = "Tilføj bruger";
    QString aktivi = "Aktivitetssimulering";
    if (userMenuPages.at(index)->getName() == enhed){

        enhedsHaandteringPage->setUnitsList(unitsList);
        enhedsHaandteringPage->removeBox();
        enhedsHaandteringPage->addBox();

    }
    if (userMenuPages.at(index)->getName() == lys){

        lysstyringPage->setUnitsList(unitsList);
        lysstyringPage->removeBox();


    }
    if (userMenuPages.at(index)->getName() == adfaerd){

        adfaerdsPage->setUnitsList(unitsList);
        adfaerdsPage->removeBox();
        adfaerdsPage->addBox();

    }
    if (userMenuPages.at(index)->getName() == Aendre){
        User *tempUser = new User(static_cast<QMainApp *>qApp->getCurrentUser());
        changeProfilePage->setCurrenUser(tempUser);
        QList<User *> tempUserList = static_cast<QMainApp *>qApp->getUserList();
        changeProfilePage->setUserList(tempUserList);
        changeProfilePage->addLayouts();
        changeProfilePage->removeLayouts();
    }
    if (userMenuPages.at(index)->getName() == adduser){
        User *tempUser = new User(static_cast<QMainApp *>qApp->getCurrentUser());
        addPage->setCurrenUser(tempUser);
        QList<User *> tempUserList = static_cast<QMainApp *>qApp->getUserList();
        addPage->setUserList(tempUserList);
        addPage->clear();
        addPage->setInfo();
    }
    if(userMenuPages.at(index)->getName() == aktivi){
        aktivitetssimuleringPage->setInfo();
    }
    userMenuPages.at(index)->show();
    this->hide();
}

void MainPage::handleSaveClick() {

    userMenuPages.at(index)->hide();
    this->show();

}

void MainPage::handleCancelClick() {
    QMessageBox errorMessage;
    errorMessage.setText("Ændringer IKKE gemt!");
    errorMessage.setStandardButtons(QMessageBox::Ok);
    errorMessage.button(QMessageBox::Ok)->animateClick(3000);
    errorMessage.exec();
    userMenuPages.at(index)->hide();
    this->show();
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
        errorMessage.setStandardButtons(QMessageBox::Ok);
        errorMessage.button(QMessageBox::Ok)->animateClick(3000);
        errorMessage.exec();
    }
    if(addPage->checkIfUserExist()){
        QMessageBox errorMessage;
        errorMessage.setText("Brugernavnet er optaget!");
        errorMessage.setStandardButtons(QMessageBox::Ok);
        errorMessage.button(QMessageBox::Ok)->animateClick(3000);
        errorMessage.exec();

    }
    else {
        userMap.insert(*brugernavn,*kodeord);
        User *newUser = new User(*brugernavn,*kodeord,false);
        vector<bool> userPriv= addPage->getStates();
        newUser->setRights(userPriv.at(0),userPriv.at(1),userPriv.at(2),userPriv.at(3),userPriv.at(4),userPriv.at(5));
        static_cast<QMainApp *> qApp->addUserToList(newUser);
        QMessageBox errorMessage;
        errorMessage.setText("Bruger oprettet!");
        errorMessage.setStandardButtons(QMessageBox::Ok);
        errorMessage.button(QMessageBox::Ok)->animateClick(3000);
        errorMessage.exec();
        this->show();
        userMenuPages.at(index)->hide();
    }

}

void MainPage::changeAdfaerdsStyringSave()  {
    if(!adfaerdsPage->notNull()){
        QMessageBox errorMessage;
        errorMessage.setText("Stattiden for dagsprofil må ikke være 0!");
        errorMessage.setStandardButtons(QMessageBox::Ok);
        errorMessage.button(QMessageBox::Ok)->animateClick(3000);
        errorMessage.exec();

    } else {
        adfaerdsPage->saveIntervals();
        adfaerdsPage->changeSave();
        saveMessege();
        this->show();
        userMenuPages.at(index)->hide();
    }

}

void MainPage::changeProfileSave() {
    if (!changeProfilePage->adminCheck()){
        changeProfilePage->clear();
        QMessageBox errorMessage;
        errorMessage.setText("Kun admin kan sætte nyt admin password!");
        errorMessage.setStandardButtons(QMessageBox::Ok);
        errorMessage.button(QMessageBox::Ok)->animateClick(3000);
        errorMessage.exec();
    } else {
        changeProfilePage->makeChanges();
        saveMessege();
        this->show();
        userMenuPages.at(index)->hide();
    }
}

void MainPage::changeUnitsSave()  {
    if(enhedsHaandteringPage->notNull()){
        QMessageBox errorMessage;
        errorMessage.setText("Du skal angive serienummer og rum/lokation for at tilføje, eller krydse af for at fjerne");
        errorMessage.setStandardButtons(QMessageBox::Ok);
        errorMessage.button(QMessageBox::Ok)->animateClick(3000);
        errorMessage.exec();
    }
    if (enhedsHaandteringPage->checkIfSerieExist() || enhedsHaandteringPage->checkIfNavnExist()) {
        if (enhedsHaandteringPage->checkIfSerieExist() && enhedsHaandteringPage->checkIfNavnExist()) {
            QMessageBox errorMessage;
            errorMessage.setText("Enhedens navn og serienummer er allerede i brug!");
            errorMessage.setStandardButtons(QMessageBox::Ok);
            errorMessage.button(QMessageBox::Ok)->animateClick(3000);
            errorMessage.exec();
            return;
        }
        if (enhedsHaandteringPage->checkIfSerieExist()) {
            QMessageBox errorMessage;
            errorMessage.setText("Serienummer er allerede i brug!");
            errorMessage.setStandardButtons(QMessageBox::Ok);
            errorMessage.button(QMessageBox::Ok)->animateClick(3000);
            errorMessage.exec();
        }
        if (enhedsHaandteringPage->checkIfNavnExist()) {
            QMessageBox errorMessage;
            errorMessage.setText("Enhedens navn er allerede i brug!");
            errorMessage.setStandardButtons(QMessageBox::Ok);
            errorMessage.button(QMessageBox::Ok)->animateClick(3000);
            errorMessage.exec();
        }
    }
    else {
        int ID = enhedsHaandteringPage->getEditLineID();
        QString Name = enhedsHaandteringPage->getEditLineName();
        if (ID >= 0 && Name.toStdString().size() > 0 ) {
            unitsList.append(new Unit(ID, Name));
            enhedsHaandteringPage->setUnitsList(unitsList);
        }
        enhedsHaandteringPage->removeIfChecked();
        unitsList = enhedsHaandteringPage->getUnitsList();
        if (enhedsHaandteringPage->somethingWritten() || enhedsHaandteringPage->isChecked()){
            if (enhedsHaandteringPage->somethingWritten() && enhedsHaandteringPage->isChecked()){
                QMessageBox errorMessage;
                errorMessage.setText("Enhed tilføjet og enhed slettet!");
                errorMessage.setStandardButtons(QMessageBox::Ok);
                errorMessage.button(QMessageBox::Ok)->animateClick(3000);
                errorMessage.exec();
            }
            if(enhedsHaandteringPage->somethingWritten()){
                QMessageBox errorMessage;
                errorMessage.setText("Enhed tilføjet!");
                errorMessage.setStandardButtons(QMessageBox::Ok);
                errorMessage.button(QMessageBox::Ok)->animateClick(3000);
                errorMessage.exec();
            }
            if (enhedsHaandteringPage->isChecked()){
                QMessageBox errorMessage;
                errorMessage.setText("Enhed slettet!");
                errorMessage.setStandardButtons(QMessageBox::Ok);
                errorMessage.button(QMessageBox::Ok)->animateClick(3000);
                errorMessage.exec();
            }
        }
        this->show();
        userMenuPages.at(index)->hide();
    }
}

void MainPage::changeLightVolumeSave() {
    lysstyringPage->checkIfCheckedAddVolume();
    saveMessege();
    this->show();
    userMenuPages.at(index)->hide();
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


    //Laver TopLayout med brugernavn og ur.
    if(mainLayout->count() == 3){
        mainLayout->removeWidget(horizontalLineWidget);
        mainLayout->removeItem(topLayout);
        mainLayout->removeItem(gridLayout);

        horizontalLineWidget->deleteLater();
        topLayout->deleteLater();
        userName->deleteLater();
        time->deleteLater();
        tempClock->deleteLater();


    }
    topLayout = new QHBoxLayout();
    userName = new QLabel();
    time = new QLabel();
    tempClock = new Clock();
    horizontalLineWidget = new QWidget();

    userName->setText("<h4>" + static_cast<QMainApp *>qApp->getCurrentUser().getName() + "</h4>"  );
    time->setText("<h4>" + tempClock->showTime() + "</h4>" );
    userName->setStyleSheet("QLabel { background-color : ; color : #a0a0a0; }");
    time->setStyleSheet("QLabel { background-color : ; color : #a0a0a0; }");

    topLayout->addWidget(userName);
    topLayout->addWidget(time);
    horizontalLineWidget->setFixedHeight(3);
    horizontalLineWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    horizontalLineWidget->setStyleSheet(QString("background-color: #c0c0c0;"));
    topLayout->setAlignment(userName,Qt::AlignLeft);
    topLayout->setAlignment(time,Qt::AlignRight);


    //Begin to add buttons, that map to the menupages the user has access to
    pos =0;
    for (auto i = userMenuPages.begin(); i != userMenuPages.end(); ++i,++pos) {

        QPushButton *btn = new QPushButton(userMenuPages[pos]->getName(), this);
        buttons.append(btn);
        if(pos%2 == 0){
            gridLayout->addWidget(btn, (int)floor(pos/2), 0, 0);
        } else {
            gridLayout->addWidget(btn, (int)floor(pos/2), 1, 0);
        }
        connect(buttons.at(pos), &QPushButton::clicked, this, &MainPage::ChangeView);
    }
    gridLayout->addWidget(logout);

    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(horizontalLineWidget);
    mainLayout->addLayout(gridLayout);

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

void MainPage::saveMessege(){
    QMessageBox errorMessage;
    errorMessage.setText("Ændringer gemt!");
    errorMessage.setStandardButtons(QMessageBox::Ok);
    errorMessage.button(QMessageBox::Ok)->animateClick(3000);
    errorMessage.exec();
}