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
    timeDagFraHorizontalLayout->addSpacing(width()/32);
    timeDagFraHorizontalLayout->addWidget(dagFraTime);
    timeDagFraHorizontalLayout->addSpacing(width()/128);
    timeDagFraHorizontalLayout->addWidget(semicolon1);
    timeDagFraHorizontalLayout->addSpacing(width()/128);
    timeDagFraHorizontalLayout->addWidget(dagFraMin);
    timeDagFraHorizontalLayout->addSpacing(width()/12);

    timeDagTilHorizontalLayout->addWidget(timeDagTil);
    timeDagTilHorizontalLayout->addSpacing(width()/32);
    timeDagTilHorizontalLayout->addWidget(dagTilTime);
    timeDagTilHorizontalLayout->addSpacing(width()/128);
    timeDagTilHorizontalLayout->addWidget(semicolon2);
    timeDagTilHorizontalLayout->addSpacing(width()/128);
    timeDagTilHorizontalLayout->addWidget(dagTilMin);
    timeDagTilHorizontalLayout->addSpacing(width()/12);

    timeNatFraHorizontalLayout->addWidget(timeNatFra);
    timeNatFraHorizontalLayout->addSpacing(width()/32);
    timeNatFraHorizontalLayout->addWidget(natFraTime);
    timeNatFraHorizontalLayout->addSpacing(width()/128);
    timeNatFraHorizontalLayout->addWidget(semicolon3);
    timeNatFraHorizontalLayout->addSpacing(width()/128);
    timeNatFraHorizontalLayout->addWidget(natFraMin);
    timeNatFraHorizontalLayout->addSpacing(width()/12);

    timeNatTilHorizontalLayout->addWidget(timeNatTil);
    timeNatTilHorizontalLayout->addSpacing(width()/32);
    timeNatTilHorizontalLayout->addWidget(natTilTime);
    timeNatTilHorizontalLayout->addSpacing(width()/128);
    timeNatTilHorizontalLayout->addWidget(semicolon4);
    timeNatTilHorizontalLayout->addSpacing(width()/128);
    timeNatTilHorizontalLayout->addWidget(natTilMin);
    timeNatTilHorizontalLayout->addSpacing(width()/12);




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


    lefVertivalLayout->setAlignment(dagProfil,Qt::AlignCenter);
    rigVerticalLayout->setAlignment(natProfil,Qt::AlignCenter);

    controlHorizontalLayout->addLayout(lefVertivalLayout);
    controlHorizontalLayout->addSpacing(4);
    controlHorizontalLayout->addLayout(rigVerticalLayout);

    controlHorizontalLayout->setStretchFactor(timeDagFraHorizontalLayout,0);

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
        QCheckBox *lefBox = new QCheckBox(unitsList.at(pos)->getUnitName(), this);
        QCheckBox *rigBox = new QCheckBox(unitsList.at(pos)->getUnitName(), this);
        QLineEdit *lefStyrke = new QLineEdit("", this);
        QLineEdit *rigStyrke = new QLineEdit("", this);
        QHBoxLayout *lefLayout = new QHBoxLayout();
        QHBoxLayout *rigLayout = new QHBoxLayout();
        lefStyrke->setPlaceholderText("lysstyrke %");
        rigStyrke->setPlaceholderText("lysstyrke %");
        lefStyrke->setFixedWidth(width()/8);
        rigStyrke->setFixedWidth(width()/8);
        lefCheckBoxes.append(lefBox);
        rigCheckBoxes.append(rigBox);
        lefLineEdits.append(lefStyrke);
        rigLineEdits.append(rigStyrke);
        lefLayout->addWidget(lefBox);
        lefLayout->addWidget(lefStyrke);
        rigLayout->addWidget(rigBox);
        rigLayout->addWidget(rigStyrke);
        lefLayout->setAlignment(lefStyrke,Qt::AlignRight);
        rigLayout->setAlignment(rigStyrke,Qt::AlignRight);

        lefVertivalLayout->addLayout(lefLayout);
        rigVerticalLayout->addLayout(rigLayout);
        lefVertivalLayout->addWidget(cancel);
        rigVerticalLayout->addWidget(save);
        pos++;
    }
}

void AdfaerdsStyring::removeBox(){
    if (lefCheckBoxes.size() > unitsList.size()) {
        for (int i = 0 ; i < lefCheckBoxes.size() ; i++){
            lefCheckBoxes.at(i)->deleteLater();
            rigCheckBoxes.at(i)->deleteLater();
        }
        lefCheckBoxes.clear();
        rigCheckBoxes.clear();
        addBox();
    }
    else {
        return;
    }
}
