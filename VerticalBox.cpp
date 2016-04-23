//
// Created by Munke on 05-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include "VerticalBox.h"

VerticalBox::VerticalBox(QWidget *parent) : QWidget(parent){
    QVBoxLayout *vBox = new QVBoxLayout(this);
    vBox->setSpacing(1);

    QPushButton *settings = new QPushButton("Settings", this);
    settings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *accounts = new QPushButton("Accounts", this);
    accounts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *loans = new QPushButton("Loans", this);
    loans->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *cash = new QPushButton("Cash", this);
    cash->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *debts = new QPushButton("Debts", this);
    debts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton *nextBtn = new QPushButton("Next", this);
    nextBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(nextBtn, &QPushButton::clicked, this, &VerticalBox::onNextClick);

    QPushButton *prev = new QPushButton("Previous", this);
    prev->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(prev, &QPushButton::clicked, this, &VerticalBox::onPrevClick);


    vBox->addWidget(settings);
    vBox->addWidget(accounts);
    vBox->addWidget(loans);
    vBox->addWidget(cash);
    vBox->addWidget(debts);

    QHBoxLayout *hBox = new QHBoxLayout;
    hBox->addWidget(prev);
    hBox->addWidget(nextBtn);

    vBox->addLayout(hBox);

    setLayout(vBox);

}

QString VerticalBox::getName() {
    return name;
}