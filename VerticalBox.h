//
// Created by Munke on 05-04-2016.
//

#ifndef QTPROJECT_VERTICALBOX_H
#define QTPROJECT_VERTICALBOX_H

#include <iostream>
#include "StackedLayout.h"
using namespace std;
class VerticalBox : public QWidget{
    Q_OBJECT
public:
    VerticalBox(QWidget *parent = 0);

signals:
    void onNextClick();
    void onPrevClick();

};


#endif //QTPROJECT_VERTICALBOX_H
