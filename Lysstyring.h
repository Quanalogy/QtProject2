//
// Created by Munke on 23-04-2016.
//

#ifndef QTPROJECT_LYSSTYRING_H
#define QTPROJECT_LYSSTYRING_H


#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include <QLabel>
#include "MenuWidget.h"
#include "Unit.h"
#include "Clock.h"

class Lysstyring : public MenuWidget{
Q_OBJECT
public:
    Lysstyring(QWidget *parent = 0);
    QString getName();
    void setUnitsList(QList<Unit *> list);
    void addBox();
    void removeBox();
    void checkIfCheckedAddVolume();
    void update();

private:
    QString name = "Lysstyring";
    QVBoxLayout *lefVerticalLayout;
    QVBoxLayout *rigVerticalLayout;
    QHBoxLayout *controlLayout;
    QVBoxLayout *mainLayout;
    QPushButton *save;
    QPushButton *cancel;
    QList<Unit *> unitsList;
    QList<QCheckBox *> checkBoxes;
    QList<QLineEdit *> editLines;

    QLabel *userName;
    QHBoxLayout *topLayout;
    Clock *tempClock;
    QWidget *horizontalLineWidget;

};


#endif //QTPROJECT_LYSSTYRING_H
