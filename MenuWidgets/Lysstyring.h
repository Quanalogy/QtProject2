//
// Created by Munke on 23-04-2016.
//

#ifndef QTPROJECT_LYSSTYRING_H
#define QTPROJECT_LYSSTYRING_H


#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include "MenuWidget.h"
#include "QLabel.h"
#include "../Unit.h"

class Lysstyring : public MenuWidget{
Q_OBJECT
public:
    Lysstyring(QWidget *parent = 0);
    QString getName();
    void setUnitsList(QList<Unit *> list);
    void addBox();
    void removeBox();

private:
    QString name = "Lysstyring";
    QVBoxLayout *lefVerticalLayout;
    QVBoxLayout *rigVerticalLayout;
    QHBoxLayout *controlLayout;
    QPushButton *save;
    QPushButton *cancel;
    QList<Unit *> unitsList;
    QList<QCheckBox *> checkBoxes;
    QList<QLineEdit *> editLines;

};


#endif //QTPROJECT_LYSSTYRING_H
