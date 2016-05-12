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

private:
    QString name = "Adfærdsstyring";
    QList<QLabel *> leftList;
    QList<QLabel *> rightList;
};


#endif //QTPROJECT_ADFAERDSSTYRING_H
