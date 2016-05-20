//
// Created by Munke on 13-04-2016.
//

#ifndef QTPROJECT_ADFAERDSSTYRING_H
#define QTPROJECT_ADFAERDSSTYRING_H


#include "MenuWidget.h"
#include "../Unit.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

class AdfaerdsStyring : public MenuWidget {
Q_OBJECT
public:
    AdfaerdsStyring(QWidget *parent = 0);
    QString getName();
    bool notNull();
    void setUnitsList(QList<Unit *> list);
    void addBox();
    void removeBox();

private:
    QString name = "Adfærdsstyring";
    QList<QLabel *> leftList;
    QList<QLabel *> rightList;

    QVBoxLayout *lefVertivalLayout;
    QVBoxLayout *rigVerticalLayout;
    QHBoxLayout *controlHorizontalLayout;
    QHBoxLayout *timeDagFraHorizontalLayout;
    QHBoxLayout *timeDagTilHorizontalLayout;
    QHBoxLayout *timeNatFraHorizontalLayout;
    QHBoxLayout *timeNatTilHorizontalLayout;

    QPushButton *save;
    QPushButton *cancel;

    QLineEdit *dagFraTime;
    QLineEdit *dagFraMin;
    QLineEdit *dagTilTime;
    QLineEdit *dagTilMin;
    QLineEdit *natFraTime;
    QLineEdit *natFraMin;
    QLineEdit *natTilTime;
    QLineEdit *natTilMin;


    int idagFraTime;
    int idagFraMin;
    int idagTilTime;
    int idagTilMin;
    int inatFraTime;
    int inatFraMin;
    int inatTilTime;
    int inatTilMin;

    QList<Unit *> unitsList;
    QList<QCheckBox *> lefCheckBoxes;
    QList<QCheckBox *> rigCheckBoxes;


    QLabel *intervalNat;
    QLabel *intervalDag;

public slots:
    void saveIntervals();
};


#endif //QTPROJECT_ADFAERDSSTYRING_H
