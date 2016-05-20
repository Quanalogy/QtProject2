//
// Created by Munke on 13-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtGui/QIntValidator>
#include "AdfaerdsStyring.h"

AdfaerdsStyring::AdfaerdsStyring(QWidget *parent) : MenuWidget(parent) {
    this->setWindowTitle(name);
    lefVertivalLayout = new QVBoxLayout;
    rigVerticalLayout = new QVBoxLayout;
    controlHorizontalLayout = new QHBoxLayout(this);
    timeDagFraHorizontalLayout = new QHBoxLayout;
    timeDagTilHorizontalLayout = new QHBoxLayout;
    timeNatFraHorizontalLayout = new QHBoxLayout;
    timeNatTilHorizontalLayout = new QHBoxLayout;

    //labels
    QLabel *dagProfil = new QLabel(this);
    QLabel *natProfil = new QLabel(this);
    intervalNat = new QLabel(this);
    intervalDag = new QLabel(this);
    QLabel *profilgaelder1 = new QLabel(this);
    QLabel *profilgaelder2 = new QLabel(this);
    QLabel *timeDagTil = new QLabel(this);
    QLabel *timeDagFra = new QLabel(this);
    QLabel *timeNatTil = new QLabel(this);
    QLabel *timeNatFra = new QLabel(this);
    QLabel *semicolon1 = new QLabel(this);
    QLabel *semicolon2 = new QLabel(this);
    QLabel *semicolon3 = new QLabel(this);
    QLabel *semicolon4 = new QLabel(this);

    //Dags edit boxes til interval
    dagFraTime = new QLineEdit(this);
    dagFraMin = new QLineEdit(this);
    dagTilTime = new QLineEdit(this);
    dagTilMin = new QLineEdit(this);
    natFraTime = new QLineEdit(this);
    natFraMin = new QLineEdit(this);
    natTilTime = new QLineEdit(this);
    natTilMin = new QLineEdit(this);

    //Tids-editlines bredde sættes
    dagFraTime->setFixedWidth(width()/16);
    dagFraMin->setFixedWidth(width()/16);
    dagTilTime->setFixedWidth(width()/16);
    dagTilMin->setFixedWidth(width()/16);
    natFraTime->setFixedWidth(width()/16);
    natFraMin->setFixedWidth(width()/16);
    natTilTime->setFixedWidth(width()/16);
    natTilMin->setFixedWidth(width()/16);

    //Time og minut validators
    QValidator *timeValidator = new QIntValidator(0,23,this);
    QValidator *minValidator = new QIntValidator(0,59,this);

    dagFraTime->setValidator(timeValidator);
    dagFraMin->setValidator(minValidator);
    dagTilTime->setValidator(timeValidator);
    dagTilMin->setValidator(minValidator);
    natFraTime->setValidator(timeValidator);
    natFraMin->setValidator(minValidator);
    natTilTime->setValidator(timeValidator);
    natTilMin->setValidator(minValidator);

    //Push buttons
    save = new QPushButton("Gem",this);
    cancel = new QPushButton("Annuller",this);

    leftList << dagProfil << intervalDag << profilgaelder1;
    rightList << natProfil << intervalNat << profilgaelder2;

    //tekst til labels
    dagProfil->setText("<h1>Dagsprofil</h1>");
    intervalDag->setText("<h2>Interval</h2>");
    profilgaelder1->setText("<h3>Profilen gælder for</h3>");
    natProfil->setText("<h1>Aftenprofil</h1>");
    intervalNat->setText("<h2>Interval</h2>");
    profilgaelder2->setText("<h3>Profilen gælder for</h3>");
    timeDagFra->setText("<h3>Fra:</h3>");
    timeDagTil->setText("<h3>Til :</h3>");
    timeNatFra->setText("<h3>Fra:</h3>");
    timeNatTil->setText("<h3>Til :</h3>");
    semicolon1->setText("<h3>:</h3>");
    semicolon2->setText("<h3>:</h3>");
    semicolon3->setText("<h3>:</h3>");
    semicolon4->setText("<h3>:</h3>");

    dagProfil->setAlignment(Qt::AlignTop);
    intervalDag->setAlignment(Qt::AlignTop);
    natProfil->setAlignment(Qt::AlignTop);
    intervalNat->setAlignment(Qt::AlignTop);

    // Set af horizontal tids bokse layouts

    timeDagFraHorizontalLayout->addWidget(timeDagFra);
    timeDagFraHorizontalLayout->addWidget(dagFraTime);
    timeDagFraHorizontalLayout->addWidget(semicolon1);
    timeDagFraHorizontalLayout->addWidget(dagFraMin);

    timeDagTilHorizontalLayout->addWidget(timeDagTil);
    timeDagTilHorizontalLayout->addWidget(dagTilTime);
    timeDagTilHorizontalLayout->addWidget(semicolon2);
    timeDagTilHorizontalLayout->addWidget(dagTilMin);

    timeNatFraHorizontalLayout->addWidget(timeNatFra);
    timeNatFraHorizontalLayout->addWidget(natFraTime);
    timeNatFraHorizontalLayout->addWidget(semicolon3);
    timeNatFraHorizontalLayout->addWidget(natFraMin);

    timeNatTilHorizontalLayout->addWidget(timeNatTil);
    timeNatTilHorizontalLayout->addWidget(natTilTime);
    timeNatTilHorizontalLayout->addWidget(semicolon4);
    timeNatTilHorizontalLayout->addWidget(natTilMin);

    int pos=0;
    for (auto i = leftList.begin(); i != leftList.end() ; ++i,++pos)
    {
        lefVertivalLayout->addWidget(leftList.at(pos));
        if(*i==intervalDag)
        {
           lefVertivalLayout->addLayout(timeDagFraHorizontalLayout);
            lefVertivalLayout->addLayout(timeDagTilHorizontalLayout);
        }
    }
    lefVertivalLayout->addWidget(cancel);

    pos=0;

    for (auto j = rightList.begin(); j !=rightList.end() ; ++j,++pos)
    {
        rigVerticalLayout->addWidget(rightList.at(pos));
        if(*j==intervalNat)
        {
            rigVerticalLayout->addLayout(timeNatFraHorizontalLayout);
            rigVerticalLayout->addLayout(timeNatTilHorizontalLayout);
        }

    }
    rigVerticalLayout->addWidget(save);


    connect(save,&QPushButton::clicked,this,&AdfaerdsStyring::onSaveClick);
    connect(cancel,&QPushButton::clicked,this,&AdfaerdsStyring::onCancelClick);
    connect(save,&QPushButton::clicked,this,&AdfaerdsStyring::saveIntervals);

    controlHorizontalLayout->addLayout(lefVertivalLayout);
    controlHorizontalLayout->addSpacing(4);
    controlHorizontalLayout->addLayout(rigVerticalLayout);

    setLayout(controlHorizontalLayout);

}
bool AdfaerdsStyring::notNull(){
    if (dagFraTime->text().toInt() > 0){
        return true;
    } else {
        return false;
    }
}

void AdfaerdsStyring::saveIntervals() {
    idagFraTime = dagFraTime->text().toInt();
    idagFraMin = dagFraMin->text().toInt();
    idagTilTime = dagTilTime->text().toInt();
    idagTilMin = dagTilMin->text().toInt();
    inatFraTime = natFraTime->text().toInt();
    inatFraMin = natFraMin->text().toInt();
    inatTilTime = natTilTime->text().toInt();
    inatTilMin = natTilMin->text().toInt();
}

QString AdfaerdsStyring::getName() {
    return name;
}

void AdfaerdsStyring::setUnitsList(QList<Unit *> list) {
    unitsList = list;
}

void AdfaerdsStyring::addBox(){
    int pos = lefCheckBoxes.size();
    while (lefCheckBoxes.size() < unitsList.size()  ) {
        lefVertivalLayout->removeWidget(cancel);
        rigVerticalLayout->removeWidget(save);
        QCheckBox *box = new QCheckBox(unitsList.at(pos)->getUnitName(), this);
        QCheckBox *box2 = new QCheckBox(unitsList.at(pos)->getUnitName(), this);
        lefCheckBoxes.append(box);
        rigCheckBoxes.append(box2);
        lefVertivalLayout->addWidget(box);
        rigVerticalLayout->addWidget(box2);
        lefVertivalLayout->addWidget(cancel);
        rigVerticalLayout->addWidget(save);
        pos++;
    }
}

void AdfaerdsStyring::removeBox(){
    if (lefCheckBoxes.size() > unitsList.size()) {
        for (int i = 0 ; i < lefCheckBoxes.size() ; i++){
            delete lefCheckBoxes.at(i);
            delete rigCheckBoxes.at(i);
        }
        lefCheckBoxes.clear();
        rigCheckBoxes.clear();
        addBox();
    }
    else {
        return;
    }
}
