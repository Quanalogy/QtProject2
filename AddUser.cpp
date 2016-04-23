//
// Created by Munke on 17-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtGui/QStaticText>
#include "AddUser.h"
#include <QDialog>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>

AddUser::AddUser(QWidget *parent) : QWidget(parent){
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    mainLayout->setSpacing(1);
    //this->setWindowTitle("This is the title FTW");

    //parent->setWindowTitle("Tilføj bruger");/*
    QLabel *titleLabel = new QLabel("Tilføj bruger");
    QFont font = titleLabel->font();
    font.setPointSize(32);
    font.setBold(true);
    titleLabel->setFont(font);
    //QStaticText *title = new QStaticText("Tilføj bruger");
    //QStaticText *brugernavn = new QStaticText("Brugernavn");
    //QStaticText *kode = new QStaticText("Kode");

    QPushButton *saveBtn = new QPushButton("Gem", this);
    QPushButton *cancelBtn = new QPushButton("Annuller", this);
    QInputDialog *brugernavnBox = new QInputDialog(this, Qt::Dialog);
    QInputDialog *kodeBox = new QInputDialog(this, Qt::Dialog);

    brugernavnBox->setInputMode(QInputDialog::TextInput);
    kodeBox->setInputMode(QInputDialog::TextInput);
    connect(saveBtn, &QPushButton::clicked, this, &AddUser::onSaveClick);
    connect(cancelBtn, &QPushButton::clicked, this, &AddUser::onCancelClick);
    /*brugernavnBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    kodeBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);*/

    brugernavnBox->setTextValue("Skriv brugernavn her");
    kodeBox->setTextValue("Skriv adgangskode her");

    mainLayout->addWidget(titleLabel, QSizePolicy::Expanding, Qt::AlignCenter);
    mainLayout->addWidget(brugernavnBox, QSizePolicy::Expanding, Qt::AlignCenter);
    mainLayout->addWidget(kodeBox, QSizePolicy::Expanding, Qt::AlignCenter);
    mainLayout->addWidget(saveBtn, QSizePolicy::Expanding, Qt::AlignCenter);
    mainLayout->addWidget(cancelBtn, QSizePolicy::Expanding, Qt::AlignCenter);


}

QString AddUser::getName() {
    return name;
}