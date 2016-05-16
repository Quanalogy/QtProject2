//
// Created by Munke on 23-04-2016.
//

#ifndef QTPROJECT_AKTIVITETSSIMULERING_H
#define QTPROJECT_AKTIVITETSSIMULERING_H


#include "MenuWidget.h"

class Aktivitetssimulering : public MenuWidget{
Q_OBJECT
public:
    Aktivitetssimulering(QWidget *parent = 0);
    QString getName();

private:
    QString name = "Aktivitetssimulering";

signals:
    void onSaveClick();
    void onCancelClick();
};


#endif //QTPROJECT_AKTIVITETSSIMULERING_H
