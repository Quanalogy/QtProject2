//
// Created by Virkman on 19-05-2016.
//

#ifndef QTPROJECT2_UNIT_H
#define QTPROJECT2_UNIT_H

#include <QtCore/QString>

using namespace std;
class Unit {
public:
    Unit(int id_, QString unitName_);
    int getId();
    QString getUnitName();
    void setUnitName(QString name);
    void setVolume(int vol);
    int getVolume();
    void setToggle(bool toggle_);
    bool getToggle();



private:
    int id;
    QString unitName;
    int volume;
    bool toggle;
};

#endif