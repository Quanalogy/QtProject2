//
// Created by Munke on 17-04-2016.
//

#ifndef QTPROJECT_ADDUSER_H
#define QTPROJECT_ADDUSER_H


#include <QtWidgets/QWidget>
#include "MenuWidget.h"
class AddUser : public MenuWidget{
Q_OBJECT
public:
    AddUser(QWidget *parent = 0);
    QString getName();
signals:
    void onSaveClick();
    void onCancelClick();

private:
    QString name = "Tilføj bruger";
};


#endif //QTPROJECT_ADDUSER_H
