//
// Created by Munke on 23-04-2016.
//

#ifndef QTPROJECT_AKTIVITETSSIMULERING_H
#define QTPROJECT_AKTIVITETSSIMULERING_H


#include "MenuWidget.h"
#include "Clock.h"
#include "Unit.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>

class Aktivitetssimulering : public MenuWidget{
Q_OBJECT
public:
    Aktivitetssimulering(QWidget *parent = 0);
    QString getName(){return name;}
    void setInfo();
    void setUnitList(QList<Unit *> list){unitList = list;}


private:
    QString name = "Aktivitetssimulering";
    void setAuto();
    QPushButton *onOff;
    bool actSimstate;
    QPushButton *on;
    QPushButton *off;

    QVBoxLayout *mainLayout;
    QVBoxLayout *top;
    QHBoxLayout *bottom;

    QHBoxLayout *topLayout;
    QLabel *userName;
    Clock *tempClock;
    QWidget *horizontalLineWidget;

    QCheckBox *autAct;
    QList<Unit *> unitList;

signals:
    void onSaveClick();
    void onCancelClick();

private slots:
    void actSimOn();
    void actSimOff();
};


#endif //QTPROJECT_AKTIVITETSSIMULERING_H
