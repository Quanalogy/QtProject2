//
// Created by Munke on 21-04-2016.
//

#ifndef QTPROJECT_MENUWIDGET_H
#define QTPROJECT_MENUWIDGET_H

#include <QtWidgets/QWidget>
#include <iostream>
#include <QtCore/QMap>

using namespace std;
class MenuWidget : public QWidget {
    Q_OBJECT
public:
    MenuWidget(QWidget *parent = 0);
    ~MenuWidget(){};
    virtual QString getName()=0;
    virtual  QMap<QString,QString> getLogin(){QMap<QString,QString> qMap;
        return qMap;};

public slots:


signals:
    virtual void onSaveClick();
    virtual void onCancelClick();
};


#endif //QTPROJECT_MENUWIDGET_H
