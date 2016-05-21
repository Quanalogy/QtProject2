//
// Created by Munke on 17-05-2016.
//

#include "QMainApp.h"
QMainApp::QMainApp(int &argc, char **argv) : QApplication(argc, argv){
    User *adminUser = new User((QString)"a", (QString) "p");
    adminUser->setRights(true, true, true, true, true, true);
    addUserToList(adminUser);

    User *noviceUser = new User("Abe", "Kat");
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
    cout << "The size of the userList is " << userList.size() << endl;
}

LoginDialog* QMainApp::getLogin() {
            foreach(QWidget *widget, findChildren<QWidget *>()){
            if(!widget->windowFlags() & Qt::Window){
                delete widget;
            }
        }
    return loginDialog;

}

