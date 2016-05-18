//
// Created by Munke on 13-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include "AdfaerdsStyring.h"

AdfaerdsStyring::AdfaerdsStyring(QWidget *parent) : MenuWidget(parent) {
    this->setWindowTitle(name);
    QVBoxLayout *lefVertivalLayout = new QVBoxLayout;
    QVBoxLayout *rigVerticalLayout = new QVBoxLayout;
    QHBoxLayout *controlHorizontalLayout = new QHBoxLayout(this);
    //labels
    QLabel *dagProfil = new QLabel(this);
    QLabel *natProfil = new QLabel(this);
    QLabel *intervalNat = new QLabel(this);
    QLabel *intervalDag = new QLabel(this);
    QLabel *profilgaelder1 = new QLabel(this);
    QLabel *profilgaelder2 = new QLabel(this);
    //Line edits
    QLineEdit *dagFra = new QLineEdit(this);
    QLineEdit *dagTil = new QLineEdit(this);
    QLineEdit *natFra = new QLineEdit(this);
    QLineEdit *natTil = new QLineEdit(this);
    //check boxes
    QCheckBox *stueDag = new QCheckBox("Stue",this);
    QCheckBox *soveDag1 = new QCheckBox("Soveværelse 1",this);
    QCheckBox *soveDag2 = new QCheckBox("Soveværelse 2",this);
    QCheckBox *stueNat = new QCheckBox("Stue",this);
    QCheckBox *soveNat1 = new QCheckBox("Soveværelse 1",this);
    QCheckBox *soveNat2 = new QCheckBox("Soveværelse 2",this);
    //Push buttons
    QPushButton *save = new QPushButton("Gem",this);
    QPushButton *cancel = new QPushButton("Annuller",this);

    leftList << dagProfil << intervalDag << profilgaelder1;
    rightList << natProfil << intervalNat << profilgaelder2;
    //tekst til labels
    dagProfil->setText("<h1>Dagsprofil</h1>");
    intervalDag->setText("<h2>Interval</h2>");
    profilgaelder1->setText("<h3>Profilen gælder for</h3>");
    natProfil->setText("<h1>Aftenprofil</h1>");
    intervalNat->setText("<h2>Interval</h2>");
    profilgaelder2->setText("<h3>Profilen gælder for</h3>");

    dagProfil->setAlignment(Qt::AlignTop);
    intervalDag->setAlignment(Qt::AlignTop);
    natProfil->setAlignment(Qt::AlignTop);
    intervalNat->setAlignment(Qt::AlignTop);

    int pos=0;
    for (auto i = leftList.begin(); i != leftList.end() ; ++i,++pos)
    {
        lefVertivalLayout->addWidget(leftList.at(pos));
        if(*i==intervalDag)
        {
           lefVertivalLayout->addWidget(dagFra);
            lefVertivalLayout->addWidget(dagTil);
        }
        else if(*i==profilgaelder1)
        {
            lefVertivalLayout->addWidget(stueDag);
            lefVertivalLayout->addWidget(soveDag1);
            lefVertivalLayout->addWidget(soveDag2);
        }
    }
    lefVertivalLayout->addWidget(cancel);

    pos=0;

    for (auto j = rightList.begin(); j !=rightList.end() ; ++j,++pos)
    {
        rigVerticalLayout->addWidget(rightList.at(pos));
        if(*j==intervalNat)
        {
            rigVerticalLayout->addWidget(natFra);
            rigVerticalLayout->addWidget(natTil);
        }
        else if(*j==profilgaelder2)
        {
            rigVerticalLayout->addWidget(stueNat);
            rigVerticalLayout->addWidget(soveNat1);
            rigVerticalLayout->addWidget(soveNat2);
        }

    }
    rigVerticalLayout->addWidget(save);

    dagFra->setPlaceholderText("Fra");
    dagTil->setPlaceholderText("Til");
    natFra->setPlaceholderText("Fra");
    natTil->setPlaceholderText("Til");

    connect(save,&QPushButton::clicked,this,&AdfaerdsStyring::onSaveClick);
    connect(cancel,&QPushButton::clicked,this,&AdfaerdsStyring::onCancelClick);

    controlHorizontalLayout->addLayout(lefVertivalLayout);
    controlHorizontalLayout->addSpacing(4);
    controlHorizontalLayout->addLayout(rigVerticalLayout);

    setLayout(controlHorizontalLayout);

}

QString AdfaerdsStyring::getName() {
    return name;
}