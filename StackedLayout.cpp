//
// Created by Munke on 05-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QStackedLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QListWidget>
#include "StackedLayout.h"
#include "VerticalBox.h"
#include "MainPage.h"

StackedLayout::StackedLayout(QWidget *parent) : QWidget(parent){

    QList<QWidget *> qList;

    MainPage *secondPage = new MainPage;
    VerticalBox *firstPage = new VerticalBox;
    qList << firstPage << secondPage;

    QStackedLayout *stackedLayout = new QStackedLayout;
    stackedLayout->addWidget(firstPage);
    stackedLayout->addWidget(secondPage);
    connect(firstPage, &VerticalBox::onNextClick, this, &StackedLayout::onNextClick);
    //connect(qListWidget, )
/*    QComboBox *pageComboBox = new QComboBox;
    pageComboBox->addItem(tr("Page 1"));
    pageComboBox->addItem(tr("Page 2"));*/


    //connect(firstPage, SLOT(onNextClick()),
    //        stackedLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    //mainLayout->addWidget(pageComboBox);
    mainLayout->addLayout(stackedLayout);
    setLayout(mainLayout);


 }

void StackedLayout::onNextClick() {
    cout << "It Works!" << endl;
}

void StackedLayout::onPrevClick() {

}