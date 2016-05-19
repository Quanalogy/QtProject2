//
// Created by Virkman on 19-05-2016.
//

#ifndef QTPROJECT2_UNIT_H
#define QTPROJECT2_UNIT_H

#endif //QTPROJECT2_UNIT_H

#include <QtCore/QString>

using namespace std;
class Unit {
public:
    Unit(int id_, QString unitName_);
    int getId();
    QString getUnitName();
    void setUnitName(QString name);
private:
    int id;
    QString unitName;
};