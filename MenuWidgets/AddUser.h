//
// Created by Munke on 17-04-2016.
//

#ifndef QTPROJECT_ADDUSER_H
#define QTPROJECT_ADDUSER_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "MenuWidget.h"
#include "../User.h"
#include "../Clock.h"

class AddUser : public MenuWidget{
Q_OBJECT
public:
    AddUser(QWidget *parent = 0);
    QString getName();
    vector<bool> getStates();
    QMap<QString,QString> getLogin();
    void clear();
    void setCurrenUser(User *user);
    void setUserList(QList< User *> list);
    bool checkIfUserExist();
    void setInfo();
    bool checkAdmin();
    void setFirstTime(bool set);

private:
    QString usernameInputString;
    QString passwordInputString;
    QList<QCheckBox *> checkList;
    QList<QLineEdit *> lineList;
    User *currentUser_;
    QList<User *> userList;

    QPushButton *cancelBtn;
    QPushButton *saveBtn;

    QHBoxLayout *horizontelLayout;
    QHBoxLayout *boxLayout;
    QVBoxLayout *mainLayout;
    QHBoxLayout *topLayout;
    QLabel *userName;
    Clock *tempClock;
    QWidget *horizontalLineWidget;

    bool firstTime;


signals:
    void onSaveClick();
    void onCancelClick();

public slots:
    void open(){cout << "Open has been clicked on AddUser" << endl;};

private:
    QString name = "Tilføj bruger";
};


#endif //QTPROJECT_ADDUSER_H
