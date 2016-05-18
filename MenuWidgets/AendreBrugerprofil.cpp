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
    userList =  static_cast<QMainApp *> qApp->getUserList();
   /* if(brugerliste.first().)
    {*/
    if(!userList.isEmpty()){
        QString brugerNavn= userList.first()->getName();
        user->setText(brugerNavn);
        qDebug()<<brugerNavn;
        changePass->setText("<h2>Skift kodeord</h2>");
        userAccess->setText("<h2>Bruger har adgang til</h2>");
    }
    else{
        cout<<"den er tom"<<endl;
    }

    //A list of names of the checkboxes
    userPages<<"Bruger låst"<<"Fjern bruger"<<"Tilføj brugerprofil"<<"Ændre brugerprofil"<<"Aktivitetssimulering"
    <<"Lysstyring"<<"Adfærdsstyring"<<"Enhedshåndtering";
    //A loop to map the users with thier checkboxes
    for(int i = 0;i<size;++i){ //user loop
        QList<QCheckBox *> checkboxList;
        for(int j = 0; j<8; ++j){ //checkbox loop
            QCheckBox *checkBox = new QCheckBox(userPages.at(j));
            checkboxList<<checkBox;
        }
        checkMap[i] = checkboxList; // add the completed checkboxes to the map
    }


    //inputbox for new password
    password = new QLineEdit(this);
    // for (auto i = 0; i <=5 ; ++i) {
    password->setPlaceholderText("Indtast nyt kodeord her");



    //Pushbuttons
    QPushButton *saveBtn = new QPushButton("Gem", this);
    QPushButton *cancelBtn = new QPushButton("Annuller", this);

    //Add buttons to horizontal layout
    buttonLayout->addWidget(cancelBtn);
    buttonLayout->addWidget(saveBtn);

    //connect buttons with signals
    connect(cancelBtn, &QPushButton::clicked, this, &AendreBrugerprofil::onCancelClick);
    connect(saveBtn, &QPushButton::clicked, this, &AendreBrugerprofil::onSaveClick);





    for(int i = 0; i < size; ++i){//user loop
        QList<QCheckBox *> tempList = checkMap[i];
        for (int j = 0; j <8 ; ++j) {//checkbox loop
            if(j==0){
                userLayout->addWidget(user, 0, Qt::AlignTop);
            } else if(j==2){
                userLayout->addWidget(changePass, 0, Qt::AlignCenter);
                userLayout->addWidget(password, 0, Qt::AlignTop);
                userLayout->addWidget(userAccess, 0, Qt::AlignTop);
            }
            //QList<QCheckBox *> hej2 = checkMap.values(i);
            QCheckBox *tempBox = tempList.at(j);
            userLayout->addWidget(tempBox);
        }


    }


    subMainLayout->addLayout(userLayout);


    subMainLayout->addLayout(userLayout);
        mainLayout->addLayout(subMainLayout);
        mainLayout->addLayout(buttonLayout);
        setLayout(mainLayout);
   // }
}

QString AendreBrugerprofil::getName() {
    return name;
}

vector<bool> AendreBrugerprofil::getStates(int userNum){

    userList= static_cast<QMainApp *> qApp->getUserList();
    int pos=0;
    for (auto i = userList.first(); i !=userList.last() ; ++i, ++pos) {
        vector<bool> states=userList.at(pos)->getRights();

    }

}

//QString AendreBrugerprofil::getNewPassword() {
//QString kodeOrd= password->text();
//return kodeOrd;
//}

QList<QString> AendreBrugerprofil::getPasswords(){
   QList<QString> kodeListe;
    //kodeListe<<passwordList->at(0).text()<<passwordList->at(1).text()<<passwordList->at(2).text()<<passwordList->at(3).text()
   //         <<passwordList->at(4).text();
    return  kodeListe;
}

