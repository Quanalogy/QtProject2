//
// Created by Munke on 30-05-2016.
//

#include "SendOnX10.h"
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//#include <wiringPi.h>

int x10Index = -1;
int x10Communication[30] = {0};
void writeX10Communication();

SendOnX10::SendOnX10() {
    printf ("Raspberry Pi wiringPi test program\n") ;
/*    if (wiringPiSetupGpio() == -1){                       //do crash this if we can't setup the wiringPi!!
        exit (1) ;
    }
    wiringPiISR(24,INT_EDGE_BOTH,&writeX10Communication); //setup interrupt on pin 24 GPIO wise
    pinMode(18,PWM_OUTPUT);                                // set pwmoutput
    pwmSetClock(80);                                        // Clock and range set to make a 120kHz pwm signal
    pwmSetRange (10);*/
}


void SendOnX10::SendCommunication(int unitID, bool aktivSim, int lightLevel) {
    convertUnitToX10(unitID);
    convertLightToX10(lightLevel);
    for (int i = 0; i < 3; ++i) {
        x10Communication[i] = 1;
    } // inserting 111 as start, begin from 4 because 3 has to be 0
    int k = 0;
    // insert unit
    for (int j = 4; j < 14; ++j, ++k) {
        x10Communication[j] = x10UnitArray[k];
    }
    // insert aktivsim
    if(aktivSim){
        x10Communication[14] = 1;
        x10Communication[15] = 0;
    } else {
        x10Communication[14] = 0;
        x10Communication[15] = 1;
    }
    // insert lightlevel
    k=0;
    for (int l = 16; l < 30; ++l, ++k) {
        x10Communication[l] = x10LightArray[k];
    }
    x10Index = 0;

}

void writeX10Communication(){
    if(x10Index > -1){
        if(x10Communication[x10Index]){
            //pwmWrite(18, 5);
        } else {
            //pwmWrite(18, 0);
        }
    }

    if(x10Index == 29){
        x10Index = -1;
    }
}


void SendOnX10::convertUnitToX10(int unitNumber) {
    if(unitNumber > 30){
        return;
    }
    int binaryUnitArray[5] = {0};     // a temp array for holding binary unit number

    int tempUnitNumber = unitNumber;
    int i=0;
    while (tempUnitNumber > 0){
        binaryUnitArray[4-i] = tempUnitNumber%2;

        cout << "Inserting into array, on spot: " << 5-i << "\nThe value of " << binaryUnitArray[4-i]
            << "\nThe couter i is: " << i << endl << endl;
        tempUnitNumber = tempUnitNumber/2;
        ++i;
    }
    cout << "This is the inserted values: ";
    int k = 0;
    for (int j = 0; j <5 ; ++j, k+=2) {
        if(binaryUnitArray[j]){
            x10UnitArray[k] = 1;
            x10UnitArray[k+1] = 0;
        } else {
            x10UnitArray[k] = 0;
            x10UnitArray[k+1] = 1;
        }
        cout << x10UnitArray[k] << x10UnitArray[k+1];
    }
}

void SendOnX10::convertLightToX10(int lightLevel_) {
    int tempLightLevel;
    if(lightLevel_ > 100){
        tempLightLevel = 100;
    } else {
        tempLightLevel = lightLevel_;
    }

    int binaryLightArray[7] = {0};   // a temp array for holding binary light level

    int i = 0;
    while (tempLightLevel > 0){
        binaryLightArray[6-i] = tempLightLevel%2;
        cout << "Inserting into array, on spot: " << 6-i << "\nThe value of " << binaryLightArray[6-i]
        << "\nThe couter i is: " << i << endl << endl;
        tempLightLevel = tempLightLevel/2;
        ++i;
    }

    cout << "This is the inserted values: ";

    int k = 0;
    for (int j = 0; j < 7 ; ++j, k+=2) {
        if(binaryLightArray[i]){
            x10LightArray[k] = 1;
            x10LightArray[k+1] = 0;
        } else {
            x10LightArray[k] = 0;
            x10LightArray[k+1] = 1;
        }
        cout << x10LightArray[k] << x10LightArray[k+1];
    }
}

















