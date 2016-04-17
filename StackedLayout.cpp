//
// Created by Munke on 05-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QListWidget>
#include "VerticalBox.h"
#include "MainPage.h"
#include "StackedLayout.h"
#include "AddUser.h"

StackedLayout::StackedLayout(QWidget *parent) : QWidget(parent){

    // create a list of the pages, i think this would be usefull later on
    QList<QWidget *> qList;
    //Create the pages
    VerticalBox *firstPage = new VerticalBox;
    AddUser *secondPage = new AddUser;
    MainPage *thirdPage = new MainPage;

    //Add the pages to the list. It can now be accessed with qList.at(int)
    qList << firstPage << secondPage << thirdPage;

    stackedLayout->addWidget(firstPage);
    stackedLayout->addWidget(secondPage);
    stackedLayout->addWidget(thirdPage);
    connect(firstPage, &VerticalBox::onNextClick, this, &StackedLayout::onNextClick);
    connect(firstPage, &VerticalBox::onPrevClick, this, &StackedLayout::onPrevClick);
    connect(secondPage, &AddUser::onSaveClick, this, &StackedLayout::onNextClick);
    connect(secondPage, &AddUser::onCancelClick, this, &StackedLayout::onPrevClick);
    setLayout(stackedLayout);


 }

void StackedLayout::onNextClick() {
    if(stackedLayout->currentIndex()+1 != -1){
        stackedLayout->setCurrentIndex(stackedLayout->currentIndex()+1);
    }
}

void StackedLayout::onPrevClick() {
    if(stackedLayout->currentIndex()-1 != -1){
        stackedLayout->setCurrentIndex(stackedLayout->currentIndex()-1);
    }
}