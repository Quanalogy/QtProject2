//
// Created by Munke on 11-04-2016.
//

#include <QtWidgets/QGridLayout>
#include <QtCore/QCoreApplication>
#include "MainPage.h"
#include "AddUser.h"
#include "AdfaerdsStyring.h"
#include "AendreBrugerprofil.h"
#include "Aktivitetssimulering.h"
#include "Lysstyring.h"
#include "EnhedsHaandtering.h"


MainPage::MainPage(QWidget *parent) : MenuWidget(parent){
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

    QList<QString> menuList({ "Tilføj bruger" , "Ændre brugerprofil", "Aktivitetssimulering",
                              "Lysstyring", "Adfærdsstyring", "Enhedshåndtering"});
    int pos = 0;
    for (auto i = menuList.begin(); i != menuList.end(); ++i) {
        QPushButton *btn = new QPushButton(menuList[pos], this);
        buttons << btn;
        if(pos%2 == 0){
            gridLayout->addWidget(btn, (int)floor(pos/2), 0, 0);
        } else {
            gridLayout->addWidget(btn, (int)floor(pos/2), 1, 0);
        }
        connect(buttons.at(pos), &QPushButton::clicked, this, &MainPage::ChangeView);
        ++pos;
    }
    setLayout(gridLayout);
}

void MainPage::ChangeView() {
    cout << "Hello" <<  endl;
    int index = buttons.indexOf((QPushButton*)QObject::sender());
    pages.at(index)->show();
}