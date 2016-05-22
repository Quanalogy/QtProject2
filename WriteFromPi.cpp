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

    int *totalX10Communication = getx10Communication(5,0,input);
    printf("Værdier tilbage:\n");
    for (int i = 0; i <30 ; ++i) {
        printf("%d", totalX10Communication[i]);
    }
}


int* WriteFromPi::getx10Communication(int unit, bool pir, int lightLevel) {
    for (int i = 0; i <3 ; ++i) { // place 111, for the start communation 1110
        x10CommunacationArray[i] = 1;
    }

    convertUnitToX10(unit);

    //Print the values

    printf("\nVaerdier for convertUnitToX10:\n");

    for (int m = 0; m < 10; ++m) {
        printf("%d", x10UnitArray[m]);
    }

    convertLightToX10(lightLevel);
    printf("\nVaerdier for convertLightToX10:\n");
    for (int n = 0; n < 14; ++n) {
        printf("%d", x10LightArray[n]);
    }
    printf("\n");

    int k = 0;
    for (int j = 4; j < 14; ++j, ++k) { // indsæt enhed
        x10CommunacationArray[j] = x10UnitArray[k];
    }

    // insert pir
    if(pir == 1){
        x10CommunacationArray[15] = 1;
        x10CommunacationArray[16] = 0;
    } else {
        x10CommunacationArray[15] = 0;
        x10CommunacationArray[16] = 1;
    }
    // insert lightlevel
    k = 0;
    for (int l = 17; l < 30; ++l, ++k) {
        x10CommunacationArray[l] = x10LightArray[k];
    }
    return x10CommunacationArray;
}

int binaryUnitIndex = 0;

void WriteFromPi::convertUnitToX10(int unitNumber) {
    if(unitNumber > 32){ // can't handle too big unitnumbers
        return;
    }

    binaryUnitArray[4-binaryUnitIndex] = (int) floor(unitNumber%2);
    printf("\nUnitNumber mod 2: %d\n", (int) floor(unitNumber%2));
    ++binaryUnitIndex;

    if(unitNumber != 0){
        convertUnitToX10((int)floor(unitNumber/2));
    } else {
        int k = 0;
        for (int i = 0; i <= binaryUnitIndex; ++i, k+=2) {
            printf("i: %d\n", i);
            printf("k: %d\n", k);
            printf("binaryUnitIndex: %d\n", binaryUnitIndex);
            if(binaryUnitArray[4-i] == 1){
                x10UnitArray[9-k] = 0;
                x10UnitArray[9-(k+1)] = 1;
            } else {
                x10UnitArray[9-k] = 1;
                x10UnitArray[9-(k+1)] = 0;
            }
        }

        binaryUnitIndex = 0;
    }
}

int binaryIndex =0;
void WriteFromPi::convertLightToX10(int lightLevel_) {
    if(lightLevel_ > 127){
        return;
    }

    binaryLightArray[6-binaryIndex] = (int) floor(lightLevel_%2);
    printf("\nLightLevel mod 2: %d\n", (int) floor(lightLevel_%2));
    ++binaryIndex;

    if(lightLevel_ != 0){
        printf("\nCalling convertLightToX10 with value: %d\n",(int)floor(lightLevel_/2) );
        convertLightToX10((int)floor(lightLevel_/2));
    }  else {
        int k = 0;
        for (int i = 0; i <= binaryIndex; ++i, k+=2) {
            printf("i: %d\n", i);
            printf("k: %d\n", k);
            printf("BinaryIndex: %d\n", binaryIndex);
            if(binaryLightArray[6-i] == 1){
                x10LightArray[13-k] = 0;
                x10LightArray[13-(k+1)] = 1;
            } else {
                x10LightArray[13-k] = 1;
                x10LightArray[13-(k+1)] = 0;
            }
        }

        binaryIndex = 0;
    }
}