//
// Created by Virkman on 19-05-2016.
//

#ifndef QTPROJECT2_UNIT_H
#define QTPROJECT2_UNIT_H

#include <QtCore/QString>
#include "SendOnX10.h"
using namespace std;
class Unit {
public:
    Unit(int id_, QString unitName_);
    int getId();
    QString getUnitName();
    void setUnitName(QString name);
    void setVolume(int vol);
    int getVolume();
    void setAS(bool as_);
    bool getAS();

private:
    int id;
    QString unitName;
    int volume;
    bool as;
    SendOnX10 sendOnX10;
};

#endif