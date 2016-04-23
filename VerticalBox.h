//
// Created by Munke on 05-04-2016.
//

#ifndef QTPROJECT_VERTICALBOX_H
#define QTPROJECT_VERTICALBOX_H

#include "MenuWidget.h"

using namespace std;
class VerticalBox : public QWidget, public MenuWidget{
    Q_OBJECT
public:
    VerticalBox(QWidget *parent = 0);

    QString getName();

private:
    QString name = "Verticalbox";
signals:
    void onNextClick();
    void onPrevClick();

};


#endif //QTPROJECT_VERTICALBOX_H
