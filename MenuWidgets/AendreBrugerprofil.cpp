//
// Created by Munke on 23-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtCore/QList>
#include <QtWidgets/QMessageBox>
#include "AendreBrugerprofil.h"
#include "../QMainApp.h"
//#include "../Globals.h"


AendreBrugerprofil::AendreBrugerprofil(QWidget *parent) : MenuWidget(parent) {
    this->setWindowTitle(name);
    int tempUCount=2;

    //Add layouts
    subMainLayout = new QHBoxLayout;
    mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    int size = static_cast<QMainApp *> qApp->getUserList().size();
    //Labels
    user = new QLabel(this);
    changePass = new QLabel(this);
    userAccess =new QLabel(this);

    //set text on labels
    //  for (int j = 0; j <=size ; ++j) {
   /* if(brugerliste.first().)
    {*/


    //A list of names of the checkboxes
    userPages<<"Bruger låst"<<"Fjern bruger"<<"Tilføj brugerprofil"<<"Ændre brugerprofil"<<"Aktivitetssimulering"
    <<"Lysstyring"<<"Adfærdsstyring"<<"Enhedshåndtering";
    //A loop to map the users with thier checkboxes





    //Pushbuttons
    QPushButton *saveBtn = new QPushButton("Gem", this);
    QPushButton *cancelBtn = new QPushButton("Annuller", this);

    //Add buttons to horizontal layout
    buttonLayout->addWidget(cancelBtn);
    buttonLayout->addWidget(saveBtn);

    //connect buttons with signals
    connect(cancelBtn, &QPushButton::clicked, this, &AendreBrugerprofil::onCancelClick);
    connect(saveBtn, &QPushButton::clicked, this, &AendreBrugerprofil::onSaveClick);

        mainLayout->addLayout(subMainLayout);
        mainLayout->addLayout(buttonLayout);
        setLayout(mainLayout);

}

QString AendreBrugerprofil::getName() {
    return name;
}

vector<bool> AendreBrugerprofil::getStates(int userNum){
    for (int i = 0; i < 8; ++i) {
        checkMap[userNum].at(i)->isChecked();
    }

}

QString AendreBrugerprofil::getNewPassword() {
QString kodeOrd= password->text();
return kodeOrd;
}

QList<QString *> AendreBrugerprofil::getPasswords(){
   QList<QString> kodeListe;
    int size = static_cast<QMainApp *> qApp->getUserList().size();
    for (int i = 0; i < size; ++i) {
        kodeListe<<passwordList->at(i).text();
    }
    //return  kodeListe;
}

void AendreBrugerprofil::setUserList(QList<User * > list) {
    userList = list;
}

void AendreBrugerprofil::addLayouts(){
    vector<bool> tempRights = currentUser->getRights();
    int pos = userLayouts.size();
    while(userLayouts.size() < userList.size()){

        QList<QCheckBox *> *checkboxList = new QList<QCheckBox *>();

        for(int j = 0; j<8; ++j){ //checkbox loop
                QCheckBox *checkBox = new QCheckBox(userPages.at(j));
                if (j == 0) {
                    if (userList.at(pos)->getLock()) {
                        checkBox->setChecked(true);
                    } else {
                        checkBox->setChecked(false);
                    }
                    if (userList.at(pos)->getAdmin()){
                        checkBox->setDisabled(true);
                    }
                }
                if (j == 1 && userList.at(pos)->getAdmin()){
                    checkBox->setDisabled(true);
                }
                if (j > 1) {
                    vector<bool> temp = userList.at(pos)->getRights();
                    if (temp.at(j - 2)) {
                        checkBox->setChecked(true);
                    } else {
                        checkBox->setChecked(false);
                    }
                    if(tempRights.at(j-2)){
                        checkBox->setDisabled(false);
                    } else {
                        checkBox->setDisabled(true);
                    }
                    if (userList.at(pos)->getAdmin()){
                        checkBox->setDisabled(true);
                    }
                }
                checkboxList->append(checkBox);

        }

        listCheckboxList.append(*checkboxList); // add the completed checkboxes to the map

        QString brugerNavn= userList.at(pos)->getName();
        qDebug()<<brugerNavn;
        QVBoxLayout *layout = new QVBoxLayout();
        userLayouts.append(layout);

        QLabel *user = new QLabel();
        QLabel *changePass = new QLabel();
        QLabel *userAccess = new QLabel();
        QLineEdit *password = new QLineEdit();

        password->setPlaceholderText("Indtast nyt kodeord her");
        changePass->setText("<h2>Skift kodeord</h2>");
        userAccess->setText("<h2>Bruger har adgang til</h2>");
        user->setText("<h1>" + brugerNavn + "</h1>");

        userLabels.append(user);
        changePassLabels.append(changePass);
        userAccessLabels.append(userAccess);
        passwords.append(password);

        userLayouts.at(pos)->addWidget(userLabels.at(pos), 0, Qt::AlignCenter);
        userLayouts.at(pos)->addWidget(changePassLabels.at(pos), 0, Qt::AlignCenter);
        userLayouts.at(pos)->addWidget(passwords.at(pos), 0, Qt::AlignTop);
        userLayouts.at(pos)->addWidget(userAccessLabels.at(pos), 0, Qt::AlignTop);

        for (int j = 0; j < listCheckboxList.at(pos).size() ; ++j) {//checkbox loop
            userLayouts.at(pos)->addWidget(listCheckboxList.at(pos).at(j));
        }
        userLayouts.at(pos)->setAlignment(Qt::AlignTop);
        subMainLayout->addLayout(userLayouts.at(pos));
        cout << subMainLayout->count() << endl;
                //subMainLayout->addLayout(userLayout);
        pos++;

    }
}

void AendreBrugerprofil::removeLayouts(){
    vector<bool> tempRights = currentUser->getRights();
    for (int k = 0 ; k < userList.size() ; k++){
        if (passwords.at(k)->text() != NULL) {
            passwords.at(k)->clear();
        }
        if (userList.at(k)->getLock()){
            listCheckboxList.at(k).at(0)->setChecked(true);
        }
        for (int y = 2 ; y < listCheckboxList.at(k).size(); y++){
            if(tempRights.at(y-2)){
                listCheckboxList.at(k).at(y)->setDisabled(false);
            } else {
                listCheckboxList.at(k).at(y)->setDisabled(true);
            }
            if (userList.at(k)->getAdmin()){
                listCheckboxList.at(k).at(y)->setDisabled(true);
            }
        }
    }

    if (userLayouts.size() > userList.size()) {
        for (int i = 0 ; i < userLayouts.size() ; i++){
            userLayouts.at(i)->deleteLater();
            for (int j = 0 ; j < 8 ; j++ ){
                listCheckboxList.at(i).at(j)->deleteLater();
            }
            userLabels.at(i)->deleteLater();
            changePassLabels.at(i)->deleteLater();
            userAccessLabels.at(i)->deleteLater();
            passwords.at(i)->deleteLater();
            subMainLayout->removeItem(userLayouts.at(i));
        }

        userLayouts.clear();
        listCheckboxList.clear();
        userLabels.clear();
        changePassLabels.clear();
        userAccessLabels.clear();
        passwords.clear();
        addLayouts();

    }
    else {
        return;
    }
}

void AendreBrugerprofil::makeChanges() {
for (int i = 0 ; i < userList.size() ; i ++){
    if (passwords.at(i)->text() != NULL ) {
        userList.at(i)->setPassword(passwords.at(i)->text());
    }
    if (listCheckboxList.at(i).at(0)->isChecked()){
        userList.at(i)->setLock(true);
        static_cast<QMainApp *> qApp->lockUser(i);
    } else {
        userList.at(i)->setLock(false);
        static_cast<QMainApp *> qApp->unLockUser(i);
    }
    if (listCheckboxList.at(i).at(1)->isChecked()){
        static_cast<QMainApp *> qApp->removeUser(i);
        //userList.removeAt(i);
        //static_cast<QMainApp *> qApp->setUserList(userList);
        return;
    }
    vector<bool> *temp = new vector<bool>;
    for (int j = 2 ; j < listCheckboxList.at(i).size() ; j++){
        if(!listCheckboxList.at(i).at(j)->isChecked()){
            temp->push_back(false);
        } else {
            temp->push_back(true);
        }
    }
    userList.at(i)->setRights(temp->at(0),temp->at(1),temp->at(2),temp->at(3),temp->at(4),temp->at(5));
    static_cast<QMainApp *> qApp->setUserList(userList);
}
}

QList<User *> AendreBrugerprofil::getUserlist() {
    return userList;
}

bool AendreBrugerprofil::adminCheck(){
    for (int i = 0 ; i < userList.size() ; i ++){
        if (passwords.at(i)->text() != NULL){
            if (currentUser->getAdmin()){
                return true;
            } else {
                if (!userList.at(i)->getAdmin()){
                    return true;
                } else {
                    return false;
                }
            }
            return false;
        }
        return true;
    }
}

void AendreBrugerprofil::clear(){
    for (int i = 0 ; i < passwords.size() ; i++) {
        passwords.at(i)->clear();
    }
}

void AendreBrugerprofil::setCurrenUser(User *user) {
    currentUser = user;
}