//
// Created by Munke on 05-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include "Nesting.h"

Nesting::Nesting(QWidget *parent) : QWidget(parent){
    QVBoxLayout *vbox = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout(this);

    QListWidget *listWidget = new QListWidget(this);
    listWidget->addItem("The Omen");
    listWidget->addItem("The Exorcist");
    listWidget->addItem("Notes on a scandal");
    listWidget->addItem("Fargo");
    listWidget->addItem("Capote");

    QPushButton *add = new QPushButton("Add", this);
    QPushButton *rename = new QPushButton("Rename", this);
    QPushButton *remove = new QPushButton("Remove", this);
    QPushButton *removeAll = new QPushButton("Remove All", this);

    vbox->setSpacing(3);
    vbox->addStretch(1);
    vbox->addWidget(add);
    vbox->addWidget(rename);
    vbox->addWidget(remove);
    vbox->addWidget(removeAll);
    vbox->addStretch(1);

    hbox->addWidget(listWidget);
    hbox->setSpacing(15);
    hbox->addLayout(vbox);

    setLayout(hbox);

}