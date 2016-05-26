//
// Created by Munke on 23-04-2016.
//

#include "Aktivitetssimulering.h"
#include "../QMainApp.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>

Aktivitetssimulering::Aktivitetssimulering(QWidget *parent) : MenuWidget(parent){
   this->setWindowTitle(name);
    mainLayout = new QVBoxLayout(this);
    top= new QVBoxLayout;
    bottom = new QHBoxLayout;

    //labels
    QLabel *timeBAct = new QLabel(this);

    //line edits
    QLineEdit *timer = new QLineEdit;

    //check boxes
    autAct = new QCheckBox("Automatisk aktivitetssimulering",this);

    //push buttons
    on = new QPushButton("Tænd aktivitetssmulering",this);
    off = new QPushButton("Sluk aktivitetssimulering",this);
    QPushButton *save = new QPushButton("Gem",this);
    QPushButton *cancel = new QPushButton("Annuller",this);
    onOff = new QPushButton("Slukket",this);
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
    //connect(onOff, &QPushButton::clicked, this, &Aktivitetssimulering::toggleButtonColor);
    connect(on, &QPushButton::clicked, this, &Aktivitetssimulering::toggleButtonOn);
    connect(off, &QPushButton::clicked, this, &Aktivitetssimulering::toggleButtonOff);
    connect(autAct, &QCheckBox::clicked, this, &Aktivitetssimulering::setAuto);
    onOff->setDisabled(true);

    //bund box
    bottom->addWidget(cancel);
    bottom->addWidget(save);


    setLayout(mainLayout);



}

QString Aktivitetssimulering::getName() {
    return name;
}

void Aktivitetssimulering::toggleButtonOn() {
        QPalette *green = new QPalette();
        green->setColor(QPalette::ButtonText, Qt::darkGreen);
        onOff->setText("Tændt");
        onOff->setPalette(*green);
        off->setChecked(false);
        for (int i = 0 ; i < unitList.size() ; i++){
            unitList.at(i)->setAS(true);
        }



        // Call til X.10
        // Skrives her
        cout << "Kommando til hver enkelt enhed, kan erstattes med:" << endl;
        cout << "X.10 command: id: 0, AS=true, styrke: x : sendes her!!" << endl;
        cout << "Kommando for alle enheder" << endl;


}

void Aktivitetssimulering::toggleButtonOff() {
        QPalette *red = new QPalette();
        onOff->setText("Slukket");
        red->setColor(QPalette::ButtonText, Qt::red);
        onOff->setPalette(*red);
        on->setChecked(false);
        for (int i = 0 ; i < unitList.size() ; i++){
            unitList.at(i)->setAS(false);
        }


        // Call til X.10
        // Skrives her
        cout << "Kommando til hver enkelt enhed, kan erstattes med:" << endl;
        cout << "X.10 command: id: 0, AS=false, styrke: x : sendes her!!" << endl;
        cout << "Kommando for alle enheder" << endl;


}

void Aktivitetssimulering::setAuto(){
    if(autAct->isChecked()){
        on->setDisabled(true);
        off->setDisabled(true);
    } else {
        on->setDisabled(false);
        off->setDisabled(false);
    }
}

void Aktivitetssimulering::setInfo(){
    if(mainLayout->count() == 4){
        mainLayout->removeWidget(horizontalLineWidget);
        mainLayout->removeItem(topLayout);
        mainLayout->removeItem(top);
        mainLayout->removeItem(bottom);

        horizontalLineWidget->deleteLater();
        topLayout->deleteLater();
        userName->deleteLater();
        tempClock->deleteLater();


    }
    topLayout = new QHBoxLayout();
    userName = new QLabel();
    tempClock = new Clock();
    horizontalLineWidget = new QWidget();

    if(static_cast<QMainApp *>qApp->getCurrentUser().getAdmin()){
        QString temp = static_cast<QMainApp *>qApp->getCurrentUser().getName() + "  (Admin)";
        userName->setText(temp);
    } else {
        userName->setText("<h4>" + static_cast<QMainApp *>qApp->getCurrentUser().getName() + "</h4>");
    }
    //time->setText("<h4>" + tempClock->showTime() + "</h4>" );
    userName->setStyleSheet("QLabel { background-color : ; color : #a0a0a0; }");

    topLayout->addWidget(userName);
    topLayout->addWidget(tempClock);
    horizontalLineWidget->setFixedHeight(3);
    horizontalLineWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    horizontalLineWidget->setStyleSheet(QString("background-color: #c0c0c0;"));
    topLayout->setAlignment(userName,Qt::AlignLeft);

    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(horizontalLineWidget);
    mainLayout->addLayout(top);
    mainLayout->addLayout(bottom);
}

void Aktivitetssimulering::setUnitList(QList<Unit *> list) {
    unitList = list;
}