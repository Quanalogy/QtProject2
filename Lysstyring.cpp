//
// Created by Munke on 23-04-2016.
//

#include "Lysstyring.h"
#include "QMainApp.h"
#include <QtWidgets/QLineEdit>
#include <QtGui/QIntValidator>

Lysstyring::Lysstyring(QWidget *parent) : MenuWidget(parent){
    this->setWindowTitle(name);

    lefVerticalLayout = new QVBoxLayout;
    rigVerticalLayout = new QVBoxLayout;
    controlLayout = new QHBoxLayout();
    mainLayout = new QVBoxLayout(this);

    //Push buttons
    save = new QPushButton("Gem",this);
    cancel = new QPushButton("Annuller",this);

//left layout
    lefVerticalLayout->addWidget(cancel);


    //right layout
    rigVerticalLayout->addWidget(save);

    //connects
    connect(save,&QPushButton::clicked,this,&Lysstyring::onSaveClick);
    connect(cancel,&QPushButton::clicked,this,&Lysstyring::onCancelClick);


    //setup conrol layout
    controlLayout->addLayout(lefVerticalLayout);
    controlLayout->addSpacing(4);
    controlLayout->addLayout(rigVerticalLayout);

    setLayout(mainLayout);


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

        //Krydser boksen af hvis ikke den er 70 som std. skal laves om når der kommer et ur.
        if (unitsList.at(pos)->getVolume() > 0){
            box->setChecked(true);
        } else {
            box->setChecked(false);
        }
        int tempint = unitsList.at(pos)->getVolume();
        QString temp = QString::number(tempint);
        line->setText(temp);
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
    //Laver TopLayout med brugernavn og ur.
    if(mainLayout->count() == 3){
        mainLayout->removeWidget(horizontalLineWidget);
        mainLayout->removeItem(topLayout);
        mainLayout->removeItem(controlLayout);

        horizontalLineWidget->deleteLater();
        topLayout->deleteLater();
        userName->deleteLater();
        tempClock->deleteLater();


    }
    topLayout = new QHBoxLayout();

    userName = new QLabel();
    tempClock = new Clock();
    horizontalLineWidget = new QWidget;

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
    mainLayout->addLayout(controlLayout);

}

void Lysstyring::removeBox() {
    for (int i = 0; i < checkBoxes.size(); i++) {
        delete checkBoxes.at(i);
        delete editLines.at(i);
    }
    checkBoxes.clear();
    editLines.clear();
    addBox();
}

void Lysstyring::checkIfCheckedAddVolume() {
    for (int i = 0 ; i < unitsList.size() ; i++){
        if (checkBoxes.at(i)->isChecked()){
            unitsList.at(i)->setVolume(editLines.at(i)->text().toInt());
        } else {
            unitsList.at(i)->setVolume(0);
        }
    }
    static_cast<QMainApp *>qApp->setUnitList(unitsList);
}

void Lysstyring::update(){
    unitsList = static_cast<QMainApp *>qApp->getUnitList();
    for (int i = 0 ; i < unitsList.size() ; i++){
        if (unitsList.at(i)->getVolume() > 0){
            checkBoxes.at(i)->setChecked(true);
            editLines.at(i)->setText(QString::number(unitsList.at(i)->getVolume()));
        } else {
            checkBoxes.at(i)->setChecked(false);
            editLines.at(i)->setText("0");
        }

    }
}