//
// Created by Munke on 23-04-2016.
//

#ifndef QTPROJECT_AKTIVITETSSIMULERING_H
#define QTPROJECT_AKTIVITETSSIMULERING_H


#include "MenuWidget.h"
#include "../Clock.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

class Aktivitetssimulering : public MenuWidget{
Q_OBJECT
public:
    Aktivitetssimulering(QWidget *parent = 0);
    QString getName();
    bool actSimOn();
    bool acSimOff();
    void setInfo();

private:
    QString name = "Aktivitetssimulering";
    void toggleButtonColor();
    QPushButton *onOff;
    bool actSimstate;
    QPushButton *on;
    QPushButton *off;

    QVBoxLayout *mainLayout;
    QVBoxLayout *top;
    QHBoxLayout *bottom;

    QHBoxLayout *topLayout;
    QLabel *userName;
    QLabel *time;
    Clock *tempClock;
    QWidget *horizontalLineWidget;

signals:
    void onSaveClick();
    void onCancelClick();
};


#endif //QTPROJECT_AKTIVITETSSIMULERING_H
