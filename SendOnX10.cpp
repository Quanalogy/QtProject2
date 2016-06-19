//
// Created by Munke on 30-05-2016.
//

#include "SendOnX10.h"
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cmath>
//#include <wiringPi.h>

int x10Index = -1;
int x10Communication[30] = {0};
int x10Communication3[108] = {0};
void writeX10Communication();

SendOnX10::SendOnX10() {
    printf ("Raspberry Pi wiringPi test program\n") ;
/*    if (wiringPiSetupGpio() == -1){                       //do crash this if we can't setup the wiringPi!!
        //exit (1) ;
        cout << "Problems with wiringpisetupgpio" << endl;
    }
    pinMode(18,PWM_OUTPUT);                                // set pwmoutput
    wiringPiISR(24,INT_EDGE_BOTH,&writeX10Communication); //setup interrupt on pin 24 GPIO wise
    pwmSetClock(80);                                        // Clock and range set to make a 120kHz pwm signal
    pwmSetRange (10);
    pwmWrite(18, 0);
*/}


void SendOnX10::SendCommunication(int unitID, bool aktivSim, int lightLevel) {
    cout << "Sending X10" << endl;
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

    for (int m = 0; m < 30; ++m) {
        x10Communication3[m] = x10Communication[m];
    }

    k=0;
    for (int i1 = 36; i1 < 66; ++i1, ++k) {
        x10Communication3[i1] = x10Communication[k];
    }
    k = 0;
    for (int j1 = 72; j1 < 102 ; ++j1, ++k) {
        x10Communication3[j1] = x10Communication[k];
    }

    x10Index = 0;

}

void writeX10Communication(){
    if(x10Index != -1){
        if(x10Communication3[x10Index]){
          /*  pwmWrite(18, 5);
            delay(2);
            pwmWrite(18,0);
            */cout << 1;
        } else {
            //pwmWrite(18, 0);
            cout << 0;
        }
    }

    if(x10Index == 107){
        x10Index = -1;
    } if(x10Index != -1){
        ++x10Index;
    }
}


void SendOnX10::convertUnitToX10(int unitNumber) {
    if(unitNumber > 30){
        return;
    }
    int binaryUnitArray[5] = {0};     // a temp array for holding binary unit number

    int tempUnitNumber = unitNumber;

    int binaryStep[] = {16,8,4,2,1}; // Retard solution to modulus gave 25%2 = 0, but only sometimes

    for (int l = 0; l < 5; ++l) {   //convert int to binary in the retard way
        if (tempUnitNumber < binaryStep[l]){
            binaryUnitArray[l] = 0;
        } else{
            binaryUnitArray[l] = 1;
            tempUnitNumber = tempUnitNumber-binaryStep[l];
        }
    }

    int k = 0;
    for (int j = 0; j <5 ; ++j, k+=2) {// convert binary to x.10
        if(binaryUnitArray[j]){
            x10UnitArray[k] = 1;
            x10UnitArray[k+1] = 0;
        } else {
            x10UnitArray[k] = 0;
            x10UnitArray[k+1] = 1;
        }
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

    int binaryStep[] = {64,32,16,8,4,2,1};// Retard solution to modulus gave 25%2 = 0, but only sometimes

    for (int i = 0; i < 7; ++i) {       //convert int to binary in the retard way
        if(tempLightLevel < binaryStep[i]){
            binaryLightArray[i]=0;
        } else {
            binaryLightArray[i]=1;
            tempLightLevel = tempLightLevel-binaryStep[i];
        }
    }

    int k = 0;
    for (int j = 0; j < 7 ; ++j, k+=2) { // convert binary to x.10
        if(binaryLightArray[j]){
            x10LightArray[k] = 1;
            x10LightArray[k+1] = 0;
        } else {
            x10LightArray[k] = 0;
            x10LightArray[k+1] = 1;
        }
    }
}

















