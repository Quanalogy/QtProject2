//
// Created by Munke on 21-05-2016.
//

#ifndef QTPROJECT2_ADMINUSER_H
#define QTPROJECT2_ADMINUSER_H


#include "../User.h"

class AdminUser : User{
public:
    AdminUser(QString userName_, QString password_);

    bool getLock();
};


#endif //QTPROJECT2_ADMINUSER_H
