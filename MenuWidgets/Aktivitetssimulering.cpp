//
// Created by Munke on 23-04-2016.
//

#include "Aktivitetssimulering.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>

Aktivitetssimulering::Aktivitetssimulering(QWidget *parent) : MenuWidget(parent){
   this->setWindowTitle(name);
    QVBoxLayout *control= new QVBoxLayout(this);
    QVBoxLayout *top= new QVBoxLayout;
    QHBoxLayout *bottom = new QHBoxLayout;

    //labels
    QLabel *timeBAct = new QLabel(this);

    //line edits
    QLineEdit *timer = new QLineEdit;

    //check boxes
    QCheckBox *autAct = new QCheckBox("Automatisk aktivitetssimulering",this);

    //push buttons
    on = new QPushButton("Tænd aktivitetssmulering",this);
    off = new QPushButton("Sluk aktivitetssimulering",this);
    QPushButton *save = new QPushButton("Gem",this);
    QPushButton *cancel = new QPushButton("Annuller",this);
    QPushButton *onOff = new QPushButton("Tændt/slukket",this);
    onOff->setCheckable(true);
    onOff->setStyleSheet("background-color:red;");

    //tekst til labels og inputboks
    timeBAct->setText("Tid før automatisk aktivering");
    timer->setPlaceholderText("Tid i timer");

    //indsættelse af layout

    //top box
    top->addWidget(autAct);
    top->addWidget(timeBAct);
    top->addWidget(timer);
    top->addWidget(on);
    top->addWidget(off);
    top->addWidget(onOff);

    connect(save, &QPushButton::clicked,this, &Aktivitetssimulering::onSaveClick);
    connect(cancel, &QPushButton::clicked, this, &Aktivitetssimulering::onCancelClick);


    //bund box
    bottom->addWidget(cancel);
    bottom->addWidget(save);

    control->addLayout(top);
    control->addLayout(bottom);

    setLayout(control);



}

QString Aktivitetssimulering::getName() {
    return name;
}

bool Aktivitetssimulering::actSimOn(){


}