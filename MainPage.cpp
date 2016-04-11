//
// Created by Munke on 11-04-2016.
//

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include "MainPage.h"

MainPage::MainPage(QWidget *parent) : QWidget(parent){
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(2);

    QList<QString> menuList({"Bruger konfiguration", "Lysstyring", "blabla"});

    int pos = 0;

    for (int i = 0; i <1 ; ++i) {
        for (int j = 0; j <3 ; ++j) {
            QPushButton *btn = new QPushButton(menuList[pos], this);
            //btn->setFixedSize(40,40);
            gridLayout->addWidget(btn);
            ++pos;
        }
    }
    setLayout(gridLayout);
}