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
    QPushButton *on = new QPushButton("Tænd aktivitetssmulering",this);
    QPushButton *off = new QPushButton("Sluk aktivitetssimulering",this);
    QPushButton *save = new QPushButton("Gem",this);
    QPushButton *cancel = new QPushButton("Annuller",this);
    onOff = new QPushButton("Tændt/slukket",this);
    onOff->setCheckable(true);

    //Set color of button
    QPalette *red = new QPalette();
    red->setColor(QPalette::ButtonText, Qt::red);
    onOff->setPalette(*red);
    //onOff->setStyleSheet("background-color:red;");

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
    connect(onOff, &QPushButton::clicked, this, &Aktivitetssimulering::toggleButtonColor);

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

void Aktivitetssimulering::toggleButtonColor() {
    if(onOff->isChecked()){
        QPalette *green = new QPalette();
        green->setColor(QPalette::ButtonText, Qt::darkGreen);
        onOff->setPalette(*green);
    } else {
        QPalette *red = new QPalette();
        red->setColor(QPalette::ButtonText, Qt::red);
        onOff->setPalette(*red);
    }
}