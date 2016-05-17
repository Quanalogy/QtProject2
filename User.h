//
// Created by Munke on 16-05-2016.
//

#ifndef QTPROJECT_USER_H
#define QTPROJECT_USER_H


#include <QtCore/QString>
#include <vector>

using namespace std;
class User {
public:
    User(QString userName_, QString password_);
    QString getName();
    void setRights(bool tilfoej_, bool aendreBrugerprofil_, bool aktivitet_, bool lysstyring_, bool adfaerd_ , bool enhed_ );
    vector<bool> getRights();
private:
    QString userName, password;
    bool adfaerd, lysstyring, aktivitet, enhed, aendreBrugerprofil, tilfoej;


};


#endif //QTPROJECT_USER_H
