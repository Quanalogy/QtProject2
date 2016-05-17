//
// Created by Munke on 17-04-2016.
//

#include <QtWidgets/QVBoxLayout>
#include <QtGui/QStaticText>
#include "AddUser.h"
#include <QDialog>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>

AddUser::AddUser(QWidget *parent) : MenuWidget(parent){
    this->setWindowTitle(name);
    //Create layouts for the page
    QVBoxLayout *leftLayout = new QVBoxLayout();
    QVBoxLayout *rightLayout = new QVBoxLayout();
    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    //Begin with labels for left side
    QLabel *username = new QLabel(this);
    QLabel *access = new QLabel(this);
    //set text for labels
    username->setText("<h1>Brugernavn</h1>");
    access->setText("<h2>Bruger har adgang til</h2>");

    //Begin with labels for right side
    QLabel *password = new QLabel(this);
    QLabel *connectNFC = new QLabel(this);
    QLabel *NFCID = new QLabel(this);
    // set text
    password->setText("<h1>Angiv kode</h1>");
    connectNFC->setText("<h2>Tilknyt NFC til bruger</h2>");
    NFCID->setText("<h2>Scannet NFC ID</h2>");

    //Pushbuttons for left side
    QPushButton *cancelBtn = new QPushButton("Annuller", this);

    //Pushbuttons for right side
    QPushButton *scanNFC = new QPushButton("Klik for at scanne NFC", this);
    QPushButton *saveBtn = new QPushButton("Gem", this);

    //Left side inputBox
    QLineEdit *usernameInput = new QLineEdit(this);
    // set guidance text
    usernameInput->setPlaceholderText("Indtast brugernavn her");

    //Right side Inputbox
    QLineEdit *passwordInput = new QLineEdit(this);
    QLineEdit *NFCIDInput = new QLineEdit(this);
    // set guidance text
    passwordInput->setPlaceholderText("Indtast kodeord her");
    NFCIDInput->setPlaceholderText("Scannet NFC ID vises her");

    //Checkboxes for left side
    QCheckBox *adfaerdsCheck = new QCheckBox("Adfærdsstyring", this);
    QCheckBox *lightCheck = new QCheckBox("Lysstyring", this);
    QCheckBox *activityCheck = new QCheckBox("Aktivitetssimulering", this);
    QCheckBox *unitCheck = new QCheckBox("Enhedshåndtering", this);
    QCheckBox *changeUserCheck = new QCheckBox("Ændre brugerprofil", this);
    QCheckBox *adduser = new QCheckBox("Tilføj bruger",this);

    //Add widgets for left side
    leftLayout->addWidget(username);
    leftLayout->insertSpacing(10,15);
    leftLayout->addWidget(usernameInput);
    leftLayout->insertSpacing(20,10);
    leftLayout->addWidget(access);
    leftLayout->addWidget(adduser);
    leftLayout->addWidget(adfaerdsCheck);
    leftLayout->addWidget(lightCheck);
    leftLayout->addWidget(activityCheck);
    leftLayout->addWidget(unitCheck);
    leftLayout->addWidget(changeUserCheck);
    leftLayout->addWidget(cancelBtn);

    //Add widgets for right side
    rightLayout->addWidget(password);
    rightLayout->addWidget(passwordInput);
    rightLayout->alignment();
    rightLayout->addWidget(connectNFC);
    rightLayout->addWidget(scanNFC);
    rightLayout->addWidget(NFCID);
    rightLayout->addWidget(NFCIDInput);
    rightLayout->addWidget(saveBtn);

    //Alignment to make it look not so horrible.
    username->setAlignment(Qt::AlignTop);
    usernameInput->setAlignment(Qt::AlignTop);
    password->setAlignment(Qt::AlignTop);
    passwordInput->setAlignment(Qt::AlignTop);
    NFCID->setAlignment(Qt::AlignBottom);

    //Connect buttons
    connect(saveBtn, &QPushButton::clicked, this, &AddUser::onSaveClick);
    connect(cancelBtn, &QPushButton::clicked, this, &AddUser::onCancelClick);

    //Add layouts
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);


}

QString AddUser::getName() {
    return name;
}