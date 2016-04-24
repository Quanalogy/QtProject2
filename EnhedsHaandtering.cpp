//
// Created by Munke on 23-04-2016.
//

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include "EnhedsHaandtering.h"

EnhedsHaandtering::EnhedsHaandtering(QWidget *parent) : QWidget(parent){
    //Add layouts to design from
    QVBoxLayout *lVerticalLayout = new QVBoxLayout;
    QVBoxLayout *rVerticalLayout = new QVBoxLayout;
    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
    //Begin with labels on left side
    QLabel *tilfoej = new QLabel(this);
    QLabel *serienummer = new QLabel(this);
    QLabel *rum = new QLabel(this);
    //Add some input boxes
    QLineEdit *serienummerInput = new QLineEdit(this);
    //Add some checkboxes
    QCheckBox *stueCheck = new QCheckBox("Stue", this);
    QCheckBox *sovevaerelseCheck1 = new QCheckBox("Soveværelse 1", this);
    QCheckBox *sovevaerelseCheck2 = new QCheckBox("Soveværelse 2", this);
    QCheckBox *rStueCheck = new QCheckBox("Stue", this);
    QCheckBox *rSovevaerelseCheck1 = new QCheckBox("Soveværelse 1", this);
    QCheckBox *rSovevaerelseCheck2 = new QCheckBox("Soveværelse 2", this);
    //Add some Pushbuttons
    QPushButton *save = new QPushButton("Gem", this);
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
            lVerticalLayout->addWidget(stueCheck);
            lVerticalLayout->addWidget(sovevaerelseCheck1);
            lVerticalLayout->addWidget(sovevaerelseCheck2);
        }
    }
    lVerticalLayout->addWidget(save);
    pos = 0;
    for (auto j = rightList.begin(); j != rightList.end() ; ++j, ++pos) {
        rVerticalLayout->addWidget(rightList.at(pos));
        if(*j == angiv){
            rVerticalLayout->addWidget(rStueCheck);
            rVerticalLayout->addWidget(rSovevaerelseCheck1);
            rVerticalLayout->addWidget(rSovevaerelseCheck2);
        }
    }
    rVerticalLayout->addWidget(cancel);


    serienummerInput->setText("Indsæt serienummer");

    serienummerInput->show();


    horizontalLayout->addLayout(rVerticalLayout);
    horizontalLayout->addSpacing(4);
    horizontalLayout->addLayout(lVerticalLayout);

    setLayout(horizontalLayout);

}

QString EnhedsHaandtering::getName() {
    return name;
}