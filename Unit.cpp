//
// Created by Virkman on 19-05-2016.
//

#include <iostream>
#include "Unit.h"
#include "QMainApp.h"


Unit::Unit(int id_, QString unitName_) {
    id = id_;
    unitName = unitName_;
    volume = 70;
    as = false;

    static_cast<QMainApp *>qApp->getSendingPTR()->SendCommunication(id, as, volume);

    // Call til X.10
    // Skrives her
    cout << "X.10 command: id: " << this->getId() << ", AS=false, styrke:" << this->getVolume() <<
    " : sendes her!!" << endl;

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
        static_cast<QMainApp *>qApp->getSendingPTR()->SendCommunication(id, false, volume);
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
        // Call til X.10
        // Skrives her
        cout << "X.10 command: id: " << this->getId() << ", AS=true, styrke:" << this->getVolume() << " : sendes her!!" << endl;
    } else {
        // Call til X.10
        // Skrives her
        cout << "X.10 command: id: " << this->getId() << ", AS=false, styrke:" << this->getVolume() << " : sendes her!!" << endl;
    }
}

bool Unit::getAS() {
    return as;
}