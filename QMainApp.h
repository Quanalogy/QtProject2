//
// Created by Munke on 17-05-2016.
//

#ifndef QTPROJECT_QMAINAPP_H
#define QTPROJECT_QMAINAPP_H


#include <QtWidgets/QApplication>
#include <MainPage.h>
#include "LoginDialog.h"
#include "User.h"

class QMainApp : public QApplication{

public:
    QMainApp(int &argc, char *argv[]);
    void reset();
    QList<User *> getUserList();
    void addUserToList(User *newUser);

private:
    LoginDialog *loginDialog;
    MainPage *mainPage;
    QList<User *> userList;
};


#endif //QTPROJECT_QMAINAPP_H
