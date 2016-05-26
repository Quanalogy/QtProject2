//
// Created by Virkman on 19-05-2016.
//

#include <iostream>
#include "Unit.h"


Unit::Unit(int id_, QString unitName_) {
    if(id_ !=NULL && unitName_ != NULL){
        id = id_;
        unitName = unitName_;
        volume = 70;
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

void Unit::setVolume(int vol) {
    if (volume != vol) {
        volume = vol;
        cout << "X.10 command: id: " << this->getId() << ", AS=false, styrke:" << this->getVolume() <<
        " : sendes her!!" << endl;
    }
}

int Unit::getVolume(){
    return volume;
}

void Unit::setAS(bool as_) {
    as = as_;
    if (as_) {
        cout << "X.10 command: id: " << this->getId() << ", AS=true, styrke:" << this->getVolume() << " : sendes her!!" << endl;
    } else {
        cout << "X.10 command: id: " << this->getId() << ", AS=false, styrke:" << this->getVolume() << " : sendes her!!" << endl;
    }
}

bool Unit::getAS() {
    return as;
}