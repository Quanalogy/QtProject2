//
// Created by Munke on 21-04-2016.
//

#ifndef QTPROJECT_MENUWIDGET_H
#define QTPROJECT_MENUWIDGET_H

#include <QtCore/QString>
#include <QtWidgets/QWidget>

class MenuWidget {

public:
    MenuWidget(){};
    ~MenuWidget(){};
    virtual QString getName()=0;

};


#endif //QTPROJECT_MENUWIDGET_H
