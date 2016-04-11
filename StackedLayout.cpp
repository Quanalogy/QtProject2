//
// Created by Munke on 05-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QStackedLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QStackedWidget>
#include "StackedLayout.h"
#include "VerticalBox.h"
#include "MainPage.h"

StackedLayout::StackedLayout(QWidget *parent) : QWidget(parent){
    QWidget *firstPageWidget = new QWidget;
    QWidget *secondPageWidget = new QWidget;
    QWidget *thirdPageWidget = new QWidget;

    VerticalBox *secondPage = new VerticalBox;
    MainPage *firstPage = new MainPage;
    QStackedWidget *stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(firstPage);
    stackedWidget->addWidget(secondPageWidget);
    stackedWidget->addWidget(thirdPageWidget);
    /*
    QStackedLayout *stackedLayout = new QStackedLayout;
    stackedLayout->addWidget(firstPage);
    stackedLayout->addWidget(secondPageWidget);
    stackedLayout->addWidget(thirdPageWidget);
*/
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(stackedWidget);
    setLayout(layout);

    QComboBox *pageComboBox = new QComboBox;
    pageComboBox->addItem(tr("Page 1"));
    pageComboBox->addItem(tr("Page 2"));
    pageComboBox->addItem(tr("Page 3"));
    connect(pageComboBox, SIGNAL(activated(int)), layout, SLOT(setCurrentIndex(int)));
}