//
// Created by Munke on 23-04-2016.
//

#include "Lysstyring.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>

Lysstyring::Lysstyring(QWidget *parent) : MenuWidget(parent){
    this->setWindowTitle(name);

    QVBoxLayout *lefVerticalLayout = new QVBoxLayout;
    QVBoxLayout *rigVerticalLayout = new QVBoxLayout;
    QHBoxLayout *controlLayout = new QHBoxLayout(this);

    //check boxes
    QCheckBox *stue = new QCheckBox("Stue",this);
    QCheckBox *sove1 = new QCheckBox("Soveværelse 1",this);
    QCheckBox *sove2 = new QCheckBox("Soveværelse 2",this);

    //Line edits
    QLineEdit *lysStue = new QLineEdit(this);
    QLineEdit *lysSove1 = new QLineEdit(this);
    QLineEdit *lysSove2 = new QLineEdit(this);

    //Push buttons
    QPushButton *save = new QPushButton("Gem",this);
    QPushButton *cancel = new QPushButton("Annuller",this);

//left layout
    lefVerticalLayout->addWidget(stue);
    lefVerticalLayout->addWidget(sove1);
    lefVerticalLayout->addWidget(sove2);
    lefVerticalLayout->addSpacing(10);
    lefVerticalLayout->addWidget(cancel);


    //right layout
    rigVerticalLayout->addWidget(lysStue);
    rigVerticalLayout->addWidget(lysSove1);
    rigVerticalLayout->addWidget(lysSove2);
    rigVerticalLayout->addWidget(save);

    // placeholder text for input
    lysStue->setPlaceholderText("lysstyrke %");
    lysSove1->setPlaceholderText("lysstyrke %");
    lysSove2->setPlaceholderText("lysstyrke %");

    connect(save,&QPushButton::clicked,this,&Lysstyring::onSaveClick);
    connect(cancel,&QPushButton::clicked,this,&Lysstyring::onSaveClick);



    controlLayout->addLayout(lefVerticalLayout);
    controlLayout->addSpacing(4);
    controlLayout->addLayout(rigVerticalLayout);

    setLayout(controlLayout);


}

QString Lysstyring::getName() {
    return name;
}