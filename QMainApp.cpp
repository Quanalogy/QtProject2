//
// Created by Munke on 17-05-2016.
//

#include "QMainApp.h"
QMainApp::QMainApp(int &argc, char **argv) : QApplication(argc, argv){
    User *adminUser = new User((QString)"Admin",(QString) "Password");
    adminUser->setRights(true, true, true, true, true, true);
    mainPage = new MainPage;
    mainPage->setupPages(adminUser);
    mainPage->hide();
    LoginDialog *loginDialog = new LoginDialog;
    loginDialog->show();
    QObject::connect(loginDialog, SIGNAL (acceptLogin(QString&,QString&)),
                     mainPage,
                     SLOT (slotAcceptUserLogin(QString&,QString&)));
    addUserToList(adminUser);
}

QList<User *> QMainApp::getUserList() {
    return userList;
}

void QMainApp::addUserToList(User *newUser) {
    userList << newUser;
    //qDebug (userName_.toLatin1());
    qDebug(newUser->getName().toLatin1());
    cout << "The size of the userList is " << userList.size() << endl;
}

void QMainApp::reset() {

}