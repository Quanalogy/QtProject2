//
// Created by Virkman on 19-05-2016.
//

#include "Unit.h"


Unit::Unit(int id_, QString unitName_) {
    if(id_ !=NULL && unitName_ != NULL){
        id = id_;
        unitName = unitName_;
    } else {
        exit(0);
    }
}

QString Unit::getUnitName() {
    return unitName;
}

int Unit::getId() {
    return id;
}

void Unit::setUnitName(QString name) {
    unitName = name;
}