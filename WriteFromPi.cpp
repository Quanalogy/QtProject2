//
// Created by Munke on 18-05-2016.
//

#include "WriteFromPi.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//#include <wiringPi.h>

//lysværdi = sidste 14 bits
int communication[30] = {1,1,1,0,0,1,0,1,1,0,0,1,1,0,0,1,0,1,0,1,1,0,0,1,1,0,0,1,0,1};
int index = 0;
int stopSending = 0;

WriteFromPi::WriteFromPi(QWidget *parent) : QWidget(parent){
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QPushButton *sendSignal = new QPushButton("120 kHz", this);
    brightness = new QLineEdit(this);
    brightness->setPlaceholderText("Skriv lysstyrke her - default 70%");
    QPushButton *stopSignal = new QPushButton("Off", this);
    QPushButton *getInt = new QPushButton("hent int", this);
    mainLayout->addWidget(brightness);
    mainLayout->addWidget(sendSignal);
    mainLayout->addWidget(stopSignal);
    mainLayout->addWidget(getInt);
    //connect(sendSignal, &QPushButton::clicked, this, &WriteFromPi::RestartSignal);
    //connect(stopSignal, &QPushButton::clicked, this, &WriteFromPi::StopSignal);
    //connect(getInt, &QPushButton::clicked, this, &WriteFromPi::HandleInputInt);
    setLayout(mainLayout);
}

void WriteFromPi::ConvertToBinary(int n) {
    if(n > 127){
        return;
    }

    binaryArray[6-binaryIndex] = (int) floor(n%2);
    binaryIndex++;

    if(n > 1){
        ConvertToBinary((int)floor(n/2));
    } else {
        int k = 0;
        for (int i = 0; i < binaryIndex; ++i, k+=2) {
            printf("i: %d\n", i);
            if(binaryArray[6-i] == 1){
                x10Array[13-k] = 0;
                x10Array[13-(k+1)] = 1;
            } else {
                x10Array[13-k] = 1;
                x10Array[13-(k+1)] = 0;
            }
        }

        binaryIndex = 0;
    }
}

void WriteFromPi::SendSignal() {
    /*    if (!stopSending){
        if(communication[index] == 1){
            pwmWrite(18,5);
        } else{
            pwmWrite(18,0);
        }
        index++;
    }
*/

    //
    //zeroCross();
}

void WriteFromPi::StopSignal() {
    //pwmWrite(18,0);
    stopSending = 1;
}

void WriteFromPi::RestartSignal() {
    stopSending = 0;

}

void WriteFromPi::HandleInputInt() {
    input = brightness->text().toInt();
    for (int j = 0; j <7 ; ++j) {
        binaryArray[j] = 0;
    }
    ConvertToBinary(input);
    printf("\ninput: %d\n", input);
    printf("Binary coming out:\n");
    for (int i = 0; i <7 ; ++i) {
        printf("%d", binaryArray[i]);
    }
    printf("\n");

    printf("x10 coming out:\n");
    for (int i = 0; i <14 ; ++i) {
        printf("%d", x10Array[i]);
    }
    printf("\n");
}