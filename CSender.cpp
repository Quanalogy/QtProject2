//
// Created by Virkman on 30-05-2016.
//

#include <iostream>
#include "CSender.h"
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cmath>
#define SERIALIN 17
#define SERIALOUT 4
#define readingPIN 22

CSender::CSender(){
/*    if (wiringPiSetupGpio() == -1){                       //do crash this if we can't setup the wiringPi!!
        //exit (1) ;
        cout << "Problems with wiringpisetupgpio" << endl;
    }*/
    //pinMode(SERIALOUT, OUTPUT);
    pinMode(SERIALIN, INPUT);
    pinMode(readingPIN, OUTPUT);
    digitalWrite(readingPIN, LOW);
    digitalWrite(SERIALOUT, HIGH); // making sure it ends up being high when idle
}

bool CSender::sendToDE2(QString rightCode, QString tryCode){
    //digitalWrite(SERIALOUT, HIGH); // making sure it ends up being high when idle
    // start the old construtor

    int r_size = rightCode.length();
    int t_size = tryCode.length();
    //int rightBinCode[8*r_size];
    //int tryBinCode[8*t_size];
    int completeSIZE = 12*(r_size+t_size);

    int completeCode [completeSIZE] = {0};
    cout << "The size of r_size: " << r_size << " = The size of t_size: " << t_size
    << "The size of completeCode: " << completeSIZE << endl;
    if(r_size <= 0 ||t_size <= 0){
        cout << "One of the values are below 1 in CSender constructor" << endl;
    } else {
        //completeCode[0] = 0;    // start with 0 to start communication
        int pos = 0;            // used for position in the array
        int i;                  // used for bitshift
        int j;                  // used for position in the codearray

        for(j = 0; j < r_size; ++j){
            completeCode[pos] = 0;    // start with 0 to start communication
            ++pos;
            cout << "The right code: ";
            for (i = 0; i < 8; ++i, ++pos) {
                completeCode[pos] = !!((rightCode.at(j).toLatin1()<<(i))&0x80);
                cout << completeCode[pos];
            }
            completeCode[pos] = 1;
            ++pos;
            completeCode[pos] = 1;
            ++pos;
            completeCode[pos] = 1;
            ++pos;
            completeCode[pos] = 0;
            ++pos;
            cout << endl;        // for nice print lines
            cout << "The try code: ";
            for (i = 0; i <8 ; ++i, ++pos) {
                completeCode[pos] = !!((tryCode.at(j).toLatin1()<<(i))&0x80);
                cout << completeCode[pos];
            }
            cout << endl;        // for nice print lines
            completeCode[pos] = 1;
            ++pos;
            completeCode[pos] = 1;
            ++pos;
            completeCode[pos] = 1;
            ++pos;
        }
    }

    cout << "CompleteSIZE is: " << completeSIZE << endl << "Starting digitalwrite: ";
    int i = 1;
    for (int k = 0; k < completeSIZE; ++k) {
        if(completeCode[k]){
            digitalWrite(SERIALOUT,HIGH);
            cout << "1" ;
        } else {
            digitalWrite(SERIALOUT,LOW);
            cout << "0" ;
        }
        if(k != 0 && !k%(24*i-3)){
            ++i;
            cout << "Reading now: ";
            //digitalWrite(readingPIN, HIGH);
            delayMicroseconds(180);
            //digitalWrite(readingPIN, HIGH);
            if(!digitalRead(SERIALIN)){
                cout << "The response is false!" << endl;
                digitalWrite(SERIALOUT, HIGH); // making sure it ends up being high when idle
                return false;
            } else {
                cout << "The char response is true!" << endl;
            }
        }
        delayMicroseconds(360);
    }
    digitalWrite(SERIALOUT, HIGH); // making sure it ends up being high when idle

    cout << "The Full response is true!" << endl;
    return true;

/*    cout << endl;


    if(digitalRead(SERIALIN)){
        cout << "The response is true!" << endl;
        return true;
    } else {
        cout << "The response is false!" << endl;
        return false;
    }*/
}

