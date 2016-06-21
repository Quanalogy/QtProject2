//
// Created by Munke on 11-04-2016.
//

#include <QtWidgets/QGridLayout>
#include <QtCore/QCoreApplication>
#include <QtWidgets/QMessageBox>
#include <QtGui/QTextLine>
#include "MainPage.h"
#include "QMainApp.h"


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

    //Sætter det til første gang programet opstartes
    firstTime = true;
    addPage->setFirstTime(true);
    changeProfilePage->setFirstTime(true);
    adfaerdsPage->setFirstTime(true);

    //sætter running til false
    running = false;

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
        unitsList = static_cast<QMainApp *>qApp->getUnitList();
        enhedsHaandteringPage->setUnitsList(unitsList);
        enhedsHaandteringPage->removeBox();
        enhedsHaandteringPage->addBox();
    } else if (userMenuPages.at(index)->getName() == lys){
        unitsList = static_cast<QMainApp *>qApp->getUnitList();
        lysstyringPage->setUnitsList(unitsList);
        lysstyringPage->removeBox();
    } else if (userMenuPages.at(index)->getName() == adfaerd){
        unitsList = static_cast<QMainApp *>qApp->getUnitList();
        adfaerdsPage->setUnitsList(unitsList);
        adfaerdsPage->removeBox();
        adfaerdsPage->addBox();
    } else if (userMenuPages.at(index)->getName() == Aendre){
        User *tempUser = new User(static_cast<QMainApp *>qApp->getCurrentUser());
        changeProfilePage->setCurrenUser(tempUser);
        QList<User *> tempUserList = static_cast<QMainApp *>qApp->getUserList();
        changeProfilePage->setUserList(tempUserList);
        changeProfilePage->addLayouts();
        changeProfilePage->removeLayouts();
    } else if (userMenuPages.at(index)->getName() == adduser){
        User *tempUser = new User(static_cast<QMainApp *>qApp->getCurrentUser());
        addPage->setCurrenUser(tempUser);
        QList<User *> tempUserList = static_cast<QMainApp *>qApp->getUserList();
        addPage->setUserList(tempUserList);
        addPage->clear();
        addPage->setInfo();
    } else if(userMenuPages.at(index)->getName() == aktivi){
        unitsList = static_cast<QMainApp *>qApp->getUnitList();
        aktivitetssimuleringPage->setUnitList(unitsList);
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
    if(firstTime){
        userList = static_cast<QMainApp *>qApp->getUserList();
        errorMessage.setText("Ændringer IKKE gemt, du logges nu ud!");
        errorMessage.setStandardButtons(QMessageBox::Ok);
        errorMessage.button(QMessageBox::Ok)->animateClick(3000);
        errorMessage.exec();
        userMenuPages.at(index)->hide();
        userList.removeLast();
        static_cast<QMainApp *>qApp->setUserList(userList);
        logOut();
    } else {
        errorMessage.setText("Ændringer IKKE gemt!");
        errorMessage.setStandardButtons(QMessageBox::Ok);
        errorMessage.button(QMessageBox::Ok)->animateClick(3000);
        errorMessage.exec();
        userMenuPages.at(index)->hide();
        this->show();
    }
}

void MainPage::slotAcceptUserLogin(QString &userName, QString &password) {
    cout << "Welcome to MainPage" << endl;
    currentUserName = userName;
    currentPassword = password;
    QList<User *> tempUserList = static_cast<QMainApp *>qApp->getUserList();
    for (int i = 0; i <tempUserList.size(); ++i) {
        if(tempUserList.at(i)->getName()==currentUserName){
            setupPages(tempUserList.at(i));
        }
    }
    if (firstTime){
        forsteGangsVisning();
    } else {
        this->show();
    }

}

void MainPage::addUserSave() {

// AddUser tempuser = pages.at(0);
    QMap<QString,QString> userCredentials= addPage->getLogin();
    QString *brugernavn= new QString(userCredentials.firstKey());
    QString *kodeord = new QString(userCredentials.value(userCredentials.firstKey()));
    if(*brugernavn == "" || *kodeord == "" ){
        QMessageBox errorMessage;
        errorMessage.setText("Du skal skrive både brugernavn og kodeord!");
        errorMessage.setStandardButtons(QMessageBox::Ok);
        errorMessage.button(QMessageBox::Ok)->animateClick(3000);
        errorMessage.exec();
        return;
    } else if(addPage->checkIfUserExist()) {
        QMessageBox errorMessage;
        errorMessage.setText("Brugernavnet er optaget!");
        errorMessage.setStandardButtons(QMessageBox::Ok);
        errorMessage.button(QMessageBox::Ok)->animateClick(3000);
        errorMessage.exec();
        return;
    } else if(addPage->checkAdmin() && !addPage->checkIfUserExist()) {
        brugernavn->remove("admin5555admin");
        userMap.insert(*brugernavn,*kodeord);
        User *newUser = new User(*brugernavn,*kodeord,true);
        vector<bool> userPriv= addPage->getStates();
        newUser->setRights(userPriv.at(0),userPriv.at(1),userPriv.at(2),userPriv.at(3),userPriv.at(4),userPriv.at(5));
        static_cast<QMainApp *> qApp->addUserToList(newUser);
        QMessageBox errorMessage;
        errorMessage.setText("Admin bruger oprettet!");
        errorMessage.setStandardButtons(QMessageBox::Ok);
        errorMessage.button(QMessageBox::Ok)->animateClick(3000);
        errorMessage.exec();
    } else {
        QMessageBox errorMessage;
        errorMessage.setText("Bruger oprettet!");
        errorMessage.setStandardButtons(QMessageBox::Ok);
        errorMessage.button(QMessageBox::Ok)->animateClick(3000);
        errorMessage.exec();
        userMap.insert(*brugernavn,*kodeord);
        User *newUser = new User(*brugernavn,*kodeord,false);
        vector<bool> userPriv= addPage->getStates();
        newUser->setRights(userPriv.at(0),userPriv.at(1),userPriv.at(2),userPriv.at(3),userPriv.at(4),userPriv.at(5));
        static_cast<QMainApp *> qApp->addUserToList(newUser);
    }
    if(firstTime){
        User *tempUser = new User(static_cast<QMainApp *>qApp->getCurrentUser());
        changeProfilePage->setCurrenUser(tempUser);
        QList<User *> tempUserList = static_cast<QMainApp *>qApp->getUserList();
        changeProfilePage->setUserList(tempUserList);
        changeProfilePage->addLayouts();
        changeProfilePage->removeLayouts();
        userMenuPages.at(1)->show();
        userMenuPages.at(index)->hide();
        index = 1;
    } else {
        this->show();
        userMenuPages.at(index)->hide();
    }
}

void MainPage::changeAdfaerdsStyringSave()  {
    if(!adfaerdsPage->notNull()){
        QMessageBox errorMessage;
        errorMessage.setText("Tiden ikke indstillet, HUSK både fra og til!!");
        errorMessage.setStandardButtons(QMessageBox::Ok);
        errorMessage.button(QMessageBox::Ok)->animateClick(3000);
        errorMessage.exec();
        return;
    } else {
        adfaerdsPage->saveIntervals();
        adfaerdsPage->changeSave();
        if (firstTime){
            QMessageBox afslut;
            afslut.setText("Førstgangsopsætningen er færdig. \n"
                                   "Du er nu klar til brug af systemet");
            afslut.setStandardButtons(QMessageBox::Ok);
            afslut.button(QMessageBox::Ok)->animateClick(3000);
            afslut.exec();
            addPage->setFirstTime(false);
            changeProfilePage->setFirstTime(false);
            adfaerdsPage->setFirstTime(false);
            firstTime = false;
            adfaerdsPage->startWork();
            running = true;
            this->show();
            userMenuPages.at(index)->hide();
        } else {
            saveMessege();
            adfaerdsPage->startWork();
            running = true;
            this->show();
            userMenuPages.at(index)->hide();
        }
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
        return;
    } else {
        if (changeProfilePage->checkAdminRemove()){
            QMessageBox errorMessage;
            errorMessage.setText("Admin bruger fjernet!");
            errorMessage.setStandardButtons(QMessageBox::Ok);
            errorMessage.button(QMessageBox::Ok)->animateClick(3000);
            errorMessage.exec();
        } else {
            saveMessege();
        }
        changeProfilePage->makeChanges();
        if(firstTime){
            adfaerdsPage->setUnitsList(unitsList);
            adfaerdsPage->removeBox();
            adfaerdsPage->addBox();
            userMenuPages.at(4)->show();
            userMenuPages.at(index)->hide();
            index = 4;
        } else {
            this->show();
            userMenuPages.at(index)->hide();
        }

    }
}

void MainPage::changeUnitsSave()  {
    if(enhedsHaandteringPage->notNull()){
        QMessageBox errorMessage;
        errorMessage.setText("Du skal angive serienummer og rum/lokation for at tilføje, eller krydse af for at fjerne");
        errorMessage.setStandardButtons(QMessageBox::Ok);
        errorMessage.button(QMessageBox::Ok)->animateClick(3000);
        errorMessage.exec();
        return;
    } else if (enhedsHaandteringPage->checkIfSerieExist() || enhedsHaandteringPage->checkIfNavnExist()) {
        if (enhedsHaandteringPage->checkIfSerieExist() && enhedsHaandteringPage->checkIfNavnExist()) {
            QMessageBox errorMessage;
            errorMessage.setText("Enhedens navn og serienummer er allerede i brug!");
            errorMessage.setStandardButtons(QMessageBox::Ok);
            errorMessage.button(QMessageBox::Ok)->animateClick(3000);
            errorMessage.exec();
            return;
        } else if (enhedsHaandteringPage->checkIfSerieExist()) {
            QMessageBox errorMessage;
            errorMessage.setText("Serienummer er allerede i brug!");
            errorMessage.setStandardButtons(QMessageBox::Ok);
            errorMessage.button(QMessageBox::Ok)->animateClick(3000);
            errorMessage.exec();
            return;
        } else if (enhedsHaandteringPage->checkIfNavnExist()) {
            QMessageBox errorMessage;
            errorMessage.setText("Enhedens navn er allerede i brug!");
            errorMessage.setStandardButtons(QMessageBox::Ok);
            errorMessage.button(QMessageBox::Ok)->animateClick(3000);
            errorMessage.exec();
            return;
        }
    } else {
        int ID = enhedsHaandteringPage->getEditLineID();
        QString Name = enhedsHaandteringPage->getEditLineName();

        if (ID >= 0 && Name.toStdString().size() > 0 ) {
            unitsList.append(new Unit(ID, Name));
            enhedsHaandteringPage->setUnitsList(unitsList);
        }
        enhedsHaandteringPage->removeIfChecked();
        unitsList = enhedsHaandteringPage->getUnitsList();
        static_cast<QMainApp *>qApp->setUnitList(unitsList);

        if (enhedsHaandteringPage->somethingWritten() || enhedsHaandteringPage->isChecked()){
            if (enhedsHaandteringPage->somethingWritten() && enhedsHaandteringPage->isChecked()){
                QMessageBox errorMessage;
                errorMessage.setText("Enhed tilføjet og enhed slettet!");
                errorMessage.setStandardButtons(QMessageBox::Ok);
                errorMessage.button(QMessageBox::Ok)->animateClick(3000);
                errorMessage.exec();
            } else if(enhedsHaandteringPage->somethingWritten()){
                QMessageBox errorMessage;
                errorMessage.setText("Enhed tilføjet!");
                errorMessage.setStandardButtons(QMessageBox::Ok);
                errorMessage.button(QMessageBox::Ok)->animateClick(3000);
                errorMessage.exec();
            } else if (enhedsHaandteringPage->isChecked()){
                QMessageBox errorMessage;
                errorMessage.setText("Enhed slettet!");
                errorMessage.setStandardButtons(QMessageBox::Ok);
                errorMessage.button(QMessageBox::Ok)->animateClick(3000);
                errorMessage.exec();
            }
        }
        if (running) {
            adfaerdsPage->updateWorker(unitsList);
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
    unsigned int pos = 0;

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
        topLayout->removeWidget(tempClock);
        mainLayout->removeWidget(horizontalLineWidget);
        mainLayout->removeItem(topLayout);
        mainLayout->removeItem(gridLayout);

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

    //time->setText("<h4>" + tempClock->showTime() + "</h4>" );
    userName->setStyleSheet("QLabel { background-color : ; color : #a0a0a0; }");
    //time->setStyleSheet("QLabel { background-color : ; color : #a0a0a0; }");
    topLayout->addWidget(userName);
    topLayout->addWidget(tempClock);

    horizontalLineWidget->setFixedHeight(3);
    horizontalLineWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    horizontalLineWidget->setStyleSheet(QString("background-color: #c0c0c0;"));
    topLayout->setAlignment(userName,Qt::AlignLeft);


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


    connect(logout, &QPushButton::clicked, this, &MainPage::logOut);
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

void MainPage::forsteGangsVisning() {
    QMessageBox velkomst;
    velkomst.setText(
            "Velkommen til Home Automation System \n"
                    "                                     \n"
                    "Dette er en førstegangs intro for nye\n"
                    "brugere. Du vil nu komme igennem:    \n"
                    "   1. Tilføj brugerprofil            \n"
                    "   2. Ændre brugerprofil             \n"
                    "   3. AdfærdsStyring                 \n"
                    "                                     \n"
                    "                                     \n"
                    "                                     \n"
                    "                                     \n"
                    "                                     \n"
    );
    velkomst.exec();
    User *tempUser = new User(static_cast<QMainApp *>qApp->getCurrentUser());
    addPage->setCurrenUser(tempUser);
    QList<User *> tempUserList = static_cast<QMainApp *>qApp->getUserList();
    addPage->setUserList(tempUserList);
    addPage->clear();
    addPage->setInfo();
    index = 0;
    userMenuPages.at(0)->show();

}

void MainPage::setUnitList(QList<Unit *> list) {
    unitsList = list;
}

void MainPage::updateLysSettings() {
    if(!lysstyringPage->isHidden()){
        lysstyringPage->update();
    }
}

void MainPage::notFirstTime(){
    firstTime = false;
    addPage->setFirstTime(false);
    changeProfilePage->setFirstTime(false);
    adfaerdsPage->setFirstTime(false);
}
