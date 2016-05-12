//
// Created by Munke on 11-04-2016.
//

#include <QtWidgets/QGridLayout>
#include "MainPage.h"
#include "AddUser.h"
#include "AdfaerdsStyring.h"
#include "AendreBrugerprofil.h"
#include "Aktivitetssimulering.h"
#include "Lysstyring.h"
#include "EnhedsHaandtering.h"


MainPage::MainPage(QWidget *parent) : MenuWidget(parent){
    //Create layouts
    //QGridLayout *gridLayout = new QGridLayout(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    QVBoxLayout *leftLayout = new QVBoxLayout();
    //leftLayout->setSpacing(2);
    QVBoxLayout *rightLayout = new QVBoxLayout();
    //stackedLayout = new QStackedLayout(gridLayout);
    //gridLayout->setHorizontalSpacing(2);

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

    // create buttons
    QPushButton *addBtn = new QPushButton("Tilføj bruger", this);
    QPushButton *activityBtn = new QPushButton("Aktivitetssimulering", this);
    QPushButton *behavBtn = new QPushButton("Adfærdsstyring", this);
    QPushButton *changeProfileBtn = new QPushButton("Ændre brugerprofil", this);
    QPushButton *lightBtn = new QPushButton("Lysstyring", this);
    QPushButton *unitBtn = new QPushButton("Enhedshåndtering", this);

    leftLayout->addWidget(addBtn);
    leftLayout->addWidget(activityBtn);
    leftLayout->addWidget(behavBtn);
    //Add buttons to the button list
    buttons << addBtn << activityBtn << behavBtn << changeProfileBtn << lightBtn << unitBtn;

    int pos = 0;
    for (auto j = buttons.begin() ; j != buttons.end() ; ++j, ++pos) {
        if(pos%2 == 0){
            leftLayout->addWidget(buttons.at(pos));
        } else {
            rightLayout->addWidget(buttons.at(pos));
        }
    }

    leftLayout->setAlignment(Qt::AlignTop);
    rightLayout->setAlignment(Qt::AlignTop);
/*
    QList<QString> menuList({ "Tilføj bruger" , "Ændre brugerprofil", "Aktivitetssimulering",
                              "Lysstyring", "Adfærdsstyring", "Enhedshåndtering"});

    pos = 0;

    for (auto i = menuList.begin(); i != menuList.end(); ++i) {
        QPushButton *btn = new QPushButton(menuList[pos], this);
        if(pos%2 == 0){
            gridLayout->addWidget(btn, (int)floor(pos/2), 0, 0);
        } else {
            gridLayout->addWidget(btn, (int)floor(pos/2), 1, 0);
        }

        QObject::connect(btn,&QPushButton::clicked, this, &MainPage::ChangeView);
        //connect(btn, &QPushButton::clicked, this, &MainPage::ChangeView);
        ++pos;
    }*/

    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);
    //setLayout(leftLayout);

}

void MainPage::ChangeView() {
    //pages.at(0)->show();
    cout << "Hello" << endl;

}