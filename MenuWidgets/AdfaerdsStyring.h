//
// Created by Munke on 13-04-2016.
//

#ifndef QTPROJECT_ADFAERDSSTYRING_H
#define QTPROJECT_ADFAERDSSTYRING_H


#include "MenuWidget.h"
#include <QtWidgets/QLabel>

class AdfaerdsStyring : public MenuWidget {
Q_OBJECT
public:
    AdfaerdsStyring(QWidget *parent = 0);
    QString getName();
    bool notNull();

private:
    QString name = "Adfærdsstyring";
    QList<QLabel *> leftList;
    QList<QLabel *> rightList;

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

public slots:
    void saveIntervals();
};


#endif //QTPROJECT_ADFAERDSSTYRING_H
