//
// Created by Munke on 15-05-2016.
// This has been taken partly from https://wiki.qt.io/User_Login_Dialog
//

#include "LoginDialog.h"
#include "QMainApp.h"

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent) {
    setUpGUI();
    setWindowTitle(tr("User Login"));
    setModal(true);
}

void LoginDialog::setUpGUI() {
    // set up the layout
    QGridLayout *formGridLayout = new QGridLayout(this);

    editUsername = new QLineEdit(this);
    editPassword = new QLineEdit(this);
    editPassword->setEchoMode(QLineEdit::Password);

// initialize the labels
    labelUsername = new QLabel(this);
    labelPassword = new QLabel(this);
    labelUsername->setText(tr("Brugernavn"));
    labelUsername->setBuddy(editUsername);
    labelPassword->setText(tr("Kodeord"));
    labelPassword->setBuddy(editPassword);

// initialize buttons
    buttons = new QDialogButtonBox(this);
    buttons->addButton(QDialogButtonBox::Ok);
    buttons->button(QDialogButtonBox::Ok)->setText(tr("Log ind"));


    // connects slots
    connect(buttons->button(QDialogButtonBox::Ok),
            SIGNAL (clicked()),
            this,
            SLOT(slotAcceptLogin()));


// place components into the dialog
    formGridLayout->addWidget(labelUsername, 0, 0);
    formGridLayout->addWidget(editUsername, 0, 1);
    formGridLayout->addWidget(labelPassword, 1, 0);
    formGridLayout->addWidget(editPassword, 1, 1);
    formGridLayout->addWidget(buttons, 2, 0, 1, 2);

/*    QString userName = "Admin";
    setUsername(userName);
  */  setLayout(formGridLayout);

}



void LoginDialog::setPassword(QString &password) {
    editPassword->setText(password);
}

void LoginDialog::slotAcceptLogin() {
    QString username = editUsername->text();
    QString password = editPassword->text();

    QList<User *> userList = static_cast<QMainApp *>qApp->getUserList();

    if(username == NULL || password == NULL){
        return;
    } else {
        for (int i = 0; i < userList.size() ; ++i) {
            if(userList.at(i)->getName() == username && userList.at(i)->getPass() == password){
                emit acceptLogin(username, // current username
                                 password // current password

                );
                close();
            }
        }
    }
}

bool LoginDialog::userAccepted() {
    if(editUsername->text() == NULL || editPassword == NULL){
        return false;
    }
    if(editUsername->text() == "Admin" && editPassword->text() == "Password"){
        return true;
    }
    return false;
}