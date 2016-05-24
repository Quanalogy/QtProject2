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
    QList<User *> getUserList();
    void addUserToList(User *newUser);
    LoginDialog* getLogin();
    void setUserList(QList<User *> list);
    void removeUser(int userIndex);
    void lockUser(int userIndex);
    void unLockUser (int userIndex);
    void setCurrentUser(QString userName);
    User getCurrentUser();

private:
    LoginDialog *loginDialog = new LoginDialog;
    MainPage *mainPage;
    QList<User *> userList;
    User *currentUser;

};


#endif //QTPROJECT_QMAINAPP_H
