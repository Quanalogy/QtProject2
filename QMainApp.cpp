//
// Created by Munke on 17-05-2016.
//

#include "QMainApp.h"
QMainApp::QMainApp(int &argc, char **argv) : QApplication(argc, argv){
    User *adminUser = new User((QString)"a", (QString) "p",true);
    adminUser->setRights(true, true, true, true, true, true);
    addUserToList(adminUser);

    User *noviceUser = new User("Abe", "Kat",false);
    noviceUser->setRights(true, false, false, false, false, true);
    addUserToList(noviceUser);
/*
 *
 *
 */

    mainPage = new MainPage;
    //mainPage->setupPages(adminUser);
    mainPage->hide();
    //LoginDialog *loginDialog = new LoginDialog;
    loginDialog->show();
    QObject::connect(loginDialog, SIGNAL (acceptLogin(QString&,QString&)),
                     mainPage,
                     SLOT (slotAcceptUserLogin(QString&,QString&)));

}

QList<User *> QMainApp::getUserList() {
    return userList;
}

void QMainApp::addUserToList(User *newUser) {
    userList << newUser;
    //qDebug (userName_.toLatin1());
    qDebug(newUser->getName().toLatin1());
}

LoginDialog* QMainApp::getLogin() {
            foreach(QWidget *widget, findChildren<QWidget *>()){
            if(!widget->windowFlags() & Qt::Window){
                delete widget;
            }
        }
    return loginDialog;

}

void QMainApp::setUserList(QList<User *> list) {
     userList = list;
}

void QMainApp::removeUser(int userIndex) {
    delete userList.at(userIndex);
    userList.removeAt(userIndex);
}

void QMainApp::lockUser(int userIndex) {
    cout << "locked" << endl;
    userList.at(userIndex)->setLock(true);
}

void QMainApp::unLockUser(int userIndex) {
    cout << "unlocked" << endl;
    userList.at(userIndex)->setLock(false);
}

void QMainApp::setCurrentUser(QString userName) {
    for (int i = 0 ; i < userList.size() ; i++){
        if (userList.at(i)->getName() == userName){
            currentUser = userList.at(i);
        }
    }
}

User QMainApp::getCurrentUser() {
    return *currentUser;
}
