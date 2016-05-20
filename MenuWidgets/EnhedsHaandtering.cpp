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
    QVBoxLayout *lVerticalLayout = new QVBoxLayout;
    rVerticalLayout = new QVBoxLayout;
    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);

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
    QPushButton *cancel = new QPushButton("Annuller", this);

    //Begin with labels on right side
    QLabel *fjern = new QLabel(this);
    QLabel *angiv = new QLabel(this);

    //Add elements on each lists
    leftList << tilfoej << serienummer << rum ;
    rightList << fjern << angiv;

    // add text to elements
    tilfoej->setText("<h1>Tilføj enhed</h1>");
    serienummer->setText("<h2>Serienummer</h2>");
    rum->setText("<h2>Angiv tilhørende rum</h2>");
    fjern->setText("<h1>Fjern enhed</h1>");
    angiv->setText("<h2>Angiv tilhørende rum</h2>");

    fjern->setAlignment(Qt::AlignTop);
    tilfoej->setAlignment(Qt::AlignTop);
    angiv->setAlignment(Qt::AlignBottom);
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
    lVerticalLayout->addWidget(cancel);
    pos = 0;
    for (auto j = rightList.begin(); j != rightList.end() ; ++j, ++pos) {
        rVerticalLayout->addWidget(rightList.at(pos));

    }
    rVerticalLayout->addWidget(save);

    serienummerInput->setPlaceholderText("Indsæt serienummer");

    serienummerInput->show();

    unitNameInput->setPlaceholderText("Angiv rum/lokation");

    unitNameInput->show();

    //connect buttons
    connect(save, &QPushButton::clicked, this, &EnhedsHaandtering::onSaveClick);
    connect(cancel, &QPushButton::clicked, this, &EnhedsHaandtering::onCancelClick);

    horizontalLayout->addLayout(lVerticalLayout);
    horizontalLayout->addSpacing(4);
    horizontalLayout->addLayout(rVerticalLayout);

    setLayout(horizontalLayout);

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
            cout << "test 1" << endl;
            return true;
        }
        cout << "test 2" << endl;
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
    if (checkBoxes.size() < unitsList.size()  ) {
            rVerticalLayout->removeWidget(save);
            QCheckBox *box = new QCheckBox(unitsList.last()->getUnitName(), this);
            checkBoxes.append(box);
            //Skal connectes
            rVerticalLayout->addWidget(box);
            rVerticalLayout->addWidget(save);
            serienummerInput->clear();
            unitNameInput->clear();
    } else {
        return;
    }
}

void EnhedsHaandtering::removeBox(){
    if (checkBoxes.size() > unitsList.size()) {
        for (int i = 0; i < checkBoxes.size(); i++) {
            if (checkBoxes.at(i)->isChecked()) {
                QCheckBox *box = checkBoxes.at(i);
                rVerticalLayout->removeWidget(box);
                if (checkBoxes.size() == 1) {
                    delete checkBoxes.at(i);
                    checkBoxes.clear();
                } else {
                    delete checkBoxes.at(i);
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