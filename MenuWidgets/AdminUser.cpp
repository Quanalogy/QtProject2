//
// Created by Munke on 21-05-2016.
//

#include "AdminUser.h"


AdminUser::AdminUser(QString userName_, QString password_, bool isAdmin_) : User(userName_, password_, isAdmin_){

}

bool AdminUser::getLock() {
    return false;
}