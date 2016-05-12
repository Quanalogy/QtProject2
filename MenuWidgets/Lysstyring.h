//
// Created by Munke on 23-04-2016.
//

#ifndef QTPROJECT_LYSSTYRING_H
#define QTPROJECT_LYSSTYRING_H


#include "MenuWidget.h"

class Lysstyring : public MenuWidget{
Q_OBJECT
public:
    Lysstyring(QWidget *parent = 0);
    QString getName();

private:
    QString name = "Lysstyring";
};


#endif //QTPROJECT_LYSSTYRING_H
