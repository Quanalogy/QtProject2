//
// Created by Munke on 11-04-2016.
//

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include "MainPage.h"
#include "AddUser.h"
#include "AdfaerdsStyring.h"


MainPage::MainPage(QWidget *parent) : QWidget(parent){
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->setHorizontalSpacing(2);

    AddUser *addPage = new AddUser;
    AdfaerdsStyring *adfaerdsPage = new AdfaerdsStyring;

    QList<QString> menuList({ "Tilføj bruger" , "Ændre brugerprofil", "Aktivitetssimulering",
                              "Lysstyring", "Adfærdsstyring", "Enhedshåndtering"});

    int pos = 0;

    for (auto i = menuList.begin(); i != menuList.end(); ++i) {
        QPushButton *btn = new QPushButton(menuList[pos], this);
        if(pos%2 == 0){
            gridLayout->addWidget(btn, (int)floor(pos/2), 0, 0);
        } else {
            gridLayout->addWidget(btn, (int)floor(pos/2), 1, 0);
        }
        ++pos;
    }



    setLayout(gridLayout);
}

QString MainPage::getName() {
    return name;
}