//
// Created by Munke on 23-04-2016.
//

#include "Lysstyring.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtGui/QIntValidator>

Lysstyring::Lysstyring(QWidget *parent) : MenuWidget(parent){
    this->setWindowTitle(name);

    lefVerticalLayout = new QVBoxLayout;
    rigVerticalLayout = new QVBoxLayout;
    controlLayout = new QHBoxLayout(this);

    //Push buttons
    save = new QPushButton("Gem",this);
    cancel = new QPushButton("Annuller",this);

//left layout
    lefVerticalLayout->addWidget(cancel);


    //right layout
    rigVerticalLayout->addWidget(save);

    //connects
    connect(save,&QPushButton::clicked,this,&Lysstyring::onSaveClick);
    connect(cancel,&QPushButton::clicked,this,&Lysstyring::onSaveClick);


    //setup conrol layout
    controlLayout->addLayout(lefVerticalLayout);
    controlLayout->addSpacing(4);
    controlLayout->addLayout(rigVerticalLayout);

    setLayout(controlLayout);


}

QString Lysstyring::getName() {
    return name;
}

void Lysstyring::setUnitsList(QList<Unit *> list) {
    unitsList = list;
}

void Lysstyring::addBox(){
    int pos = checkBoxes.size();
    while (checkBoxes.size() < unitsList.size()  ) {
        lefVerticalLayout->removeWidget(cancel);
        rigVerticalLayout->removeWidget(save);
        QCheckBox *box = new QCheckBox(unitsList.at(pos)->getUnitName(), this);
        QLineEdit *line = new QLineEdit("", this);
        QValidator *validator = new QIntValidator(0,100,this);
        line->setValidator(validator);
        line->setPlaceholderText("lysstyrke %");
        checkBoxes.append(box);
        editLines.append(line);
        lefVerticalLayout->addWidget(box);
        rigVerticalLayout->addWidget(line);
        lefVerticalLayout->addWidget(cancel);
        rigVerticalLayout->addWidget(save);
        pos++;
    }
}

void Lysstyring::removeBox(){
    if (checkBoxes.size() > unitsList.size()) {
        for (int i = 0 ; i < checkBoxes.size() ; i++){
            checkBoxes.at(i)->deleteLater();
            editLines.at(i)->deleteLater();
        }
        checkBoxes.clear();
        editLines.clear();
        addBox();
    }
    else {
        return;
    }
}

void Lysstyring::checkIfCheckedAddVolume() {
    for (int i = 0 ; i < unitsList.size() ; i++){
        if (checkBoxes.at(i)->isChecked()){
            unitsList.at(i)->setVolume(editLines.at(i)->text().toInt());
            cout << "lysstyrke:" << unitsList.at(i)->getVolume() << endl;
        }
    }
}