//
// Created by Munke on 23-04-2016.
//

#ifndef QTPROJECT_ENHEDSHAANDTERING_H
#define QTPROJECT_ENHEDSHAANDTERING_H


//#include <QtWidgets/QWidget>
#include "MenuWidget.h"
#include <QtWidgets/QLabel>

class EnhedsHaandtering : public MenuWidget{
    Q_OBJECT
public:
    EnhedsHaandtering(QWidget *parent = 0);
    QString getName();

private:
    QString name = "Enhedshåndtering";
    QList<QLabel *> leftList;
    QList<QLabel *> rightList;

signals:
    void onSaveClick();
    void onCancelClick();
};


#endif //QTPROJECT_ENHEDSHAANDTERING_H
