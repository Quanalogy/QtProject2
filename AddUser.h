//
// Created by Munke on 17-04-2016.
//

#ifndef QTPROJECT_ADDUSER_H
#define QTPROJECT_ADDUSER_H


#include <QtWidgets/QWidget>

class AddUser : public QWidget{
Q_OBJECT
public:
    AddUser(QWidget *parent = 0);

signals:
    void onSaveClick();
    void onCancelClick();
};


#endif //QTPROJECT_ADDUSER_H
