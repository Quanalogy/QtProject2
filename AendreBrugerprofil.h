//
// Created by Munke on 23-04-2016.
//

#ifndef QTPROJECT_AENDREBRUGERPROFIL_H
#define QTPROJECT_AENDREBRUGERPROFIL_H


#include "MenuWidget.h"
#include "User.h"
#include "Clock.h"
#include <vector>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtCore/QList>
#include <QtWidgets/QMessageBox>
using namespace std;


class AendreBrugerprofil : public MenuWidget {
Q_OBJECT
public:
    AendreBrugerprofil(QWidget *parent = 0);
    QString getName();

    void setUserList(QList<User * > list);
    void addLayouts();
    void removeLayouts();
    void makeChanges();
    bool adminCheck();
    void clear();
    void setCurrenUser(User *user);
    void setFirstTime(bool set);
    bool checkAdminRemove();

private:
    QString name = "Ændre brugerprofil";
    QStringList userPages;
    QList<QLineEdit> *passwordList;
    QMap<int, QList<QCheckBox *>> checkMap;
    QList<QCheckBox *> checkboxList;
    QList<QList<QCheckBox *>> listCheckboxList;
    QLineEdit *password;
    QLabel *user;
    QLabel *changePass;
    QLabel *userAccess;

    QPushButton *saveBtn;
    QPushButton *cancelBtn;

    QHBoxLayout *subMainLayout;
    QVBoxLayout *mainLayout;

    QList<QVBoxLayout *> userLayouts;

    QList<QLabel *> userLabels;
    QList<QLabel *> changePassLabels;
    QList<QLabel *> userAccessLabels;
    QList<QLineEdit *> passwords;

    QList<User * > userList;                 // holds all the users in our program
    User *currentUser;                        // holds the current username try


    QHBoxLayout *buttonLayout;
    QHBoxLayout *topLayout;
    QLabel *userName;
    Clock *tempClock;
    QWidget *horizontalLineWidget;
    bool firstTime;

public slots:
    void setMaxLenght(const QString &);

};


#endif //QTPROJECT_AENDREBRUGERPROFIL_H
