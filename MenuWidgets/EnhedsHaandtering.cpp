//
// Created by Munke on 23-04-2016.
//

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtGui/QIntValidator>
#include "EnhedsHaandtering.h"
#include "MainPage.h"

EnhedsHaandtering::EnhedsHaandtering(QWidget *parent) : MenuWidget(parent) {
    //Add layouts to design from
    this->setWindowTitle(name);
    lVerticalLayout = new QVBoxLayout;
    rVerticalLayout = new QVBoxLayout;
    QHBoxLayout *horizontalLayout = new QHBoxLayout();
    QHBoxLayout *boxlayout = new QHBoxLayout;
    QVBoxLayout *mainlayout = new QVBoxLayout(this);

    //Begin with labels on left side
    QLabel *tilfoej = new QLabel(this);
    QLabel *serienummer = new QLabel(this);
    QLabel *rum = new QLabel(this);
    //Add some input boxes
    serienummerInput = new QLineEdit(this);
    unitNameInput = new QLineEdit(this);

    //Validators
    QValidator *serieNummerValidator = new QIntValidator(1,INT_MAX,this);
    QValidator *unitNameValidator = new QRegExpValidator( QRegExp("[A-Za-z0-9_]+"), this );

    serienummerInput->setValidator(serieNummerValidator);
    unitNameInput->setValidator(unitNameValidator);

    //Add some Pushbuttons
    save = new QPushButton("Gem", this);
    cancel = new QPushButton("Annuller", this);

    //Begin with labels on right side
    QLabel *fjern = new QLabel(this);
    QLabel *angiv = new QLabel(this);

    //Add elements on each lists
    leftList << tilfoej << rum << serienummer ;
    rightList << fjern << angiv;

    // add text to elements
    tilfoej->setText("<h1>Tilføj enhed</h1>");
    serienummer->setText("<h2>Serienummer</h2>");
    rum->setText("<h2>Angiv tilhørende rum</h2>");
    fjern->setText("<h1>Fjern enhed</h1>");
    angiv->setText("<h2>Angiv tilhørende rum</h2>");

    fjern->setAlignment(Qt::AlignTop);
    tilfoej->setAlignment(Qt::AlignTop);



    //Add elements to layouts
    int pos = 0;
    for (auto i = leftList.begin(); i != leftList.end() ; ++i, ++pos) {
        lVerticalLayout->addWidget(leftList.at(pos));
        if(*i == serienummer){
            lVerticalLayout->addWidget(serienummerInput);
        } else if(*i == rum){
            lVerticalLayout->addWidget(unitNameInput);
        }
    }
    pos = 0;
    for (auto j = rightList.begin(); j != rightList.end() ; ++j, ++pos) {
        rVerticalLayout->addWidget(rightList.at(pos));

    }

    serienummerInput->setPlaceholderText("Indsæt serienummer");

    serienummerInput->show();

    unitNameInput->setPlaceholderText("Angiv rum/lokation");

    unitNameInput->show();

    //connect buttons
    connect(save, &QPushButton::clicked, this, &EnhedsHaandtering::onSaveClick);
    connect(cancel, &QPushButton::clicked, this, &EnhedsHaandtering::onCancelClick);

    lVerticalLayout->setAlignment(Qt::AlignTop);
    rVerticalLayout->setAlignment(Qt::AlignTop);

    boxlayout->addWidget(cancel);
    boxlayout->addWidget(save);

    horizontalLayout->addLayout(lVerticalLayout);
    horizontalLayout->addSpacing(4);
    horizontalLayout->addLayout(rVerticalLayout);

    mainlayout->addLayout(horizontalLayout);
    mainlayout->addLayout(boxlayout);

    setLayout(mainlayout);

}

bool EnhedsHaandtering::notNull(){
    if (serienummerInput->text().size() > 0 && unitNameInput->text().size() > 0 || EnhedsHaandtering::isChecked()){
        return false;
    } else {
        return true;
    }
}

QList<Unit *> EnhedsHaandtering::getUnitsList(){
    return unitsList;
}


bool EnhedsHaandtering::isChecked() {

    for (int i = 0 ;  i < checkBoxes.size() ; i ++){
        if (checkBoxes.at(i)->isChecked()){
            return true;
        }
    }
    return false;
}

QString EnhedsHaandtering::getName() {
    return name;
}

int EnhedsHaandtering::getEditLineID() {
    return serienummerInput->text().toInt();
}

QString EnhedsHaandtering::getEditLineName() {
    return unitNameInput->text();
}

void EnhedsHaandtering::setUnitsList(QList<Unit *> list) {
    unitsList = list;
}

void EnhedsHaandtering::addBox(){
    int pos = checkBoxes.size();
    while (checkBoxes.size() < unitsList.size()  ) {
        //rVerticalLayout->removeWidget(save);
        QCheckBox *box = new QCheckBox(unitsList.at(pos)->getUnitName(), this);
        checkBoxes.append(box);
        //Skal connectes
        rVerticalLayout->addWidget(box);
        // rVerticalLayout->addWidget(save);
        serienummerInput->clear();
        unitNameInput->clear();
        pos++;
    }
}

void EnhedsHaandtering::removeBox(){
    if (checkBoxes.size() > unitsList.size()) {
        for (int i = 0; i < checkBoxes.size(); i++) {
            if (checkBoxes.at(i)->isChecked()) {
                QCheckBox *box = checkBoxes.at(i);
                rVerticalLayout->removeWidget(box);
                if (checkBoxes.size() == 1) {
                    checkBoxes.at(i)->deleteLater();
                    checkBoxes.clear();
                } else {
                    checkBoxes.at(i)->deleteLater();
                    checkBoxes.removeAt(i);
                }
            }
        }
    }
    else {
        return;
    }
}


void EnhedsHaandtering::removeIfChecked(){
    if (unitsList.size() > 0 && isChecked()) {
        if (unitsList.size() == 1){
            unitsList.clear();
        } else {
            for (int i = 0; i < checkBoxes.size(); i++) {
                if (checkBoxes.at(i)->isChecked()) {
                    delete unitsList.at(i);
                    unitsList.removeAt(i);
                }
            }
        }
    }
}