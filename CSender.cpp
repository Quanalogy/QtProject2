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

CSender::CSender(){
/*    if (wiringPiSetupGpio() == -1){                       //do crash this if we can't setup the wiringPi!!
        //exit (1) ;
        cout << "Problems with wiringpisetupgpio" << endl;
    }*/
    //pinMode(SERIALOUT, OUTPUT);
    pinMode(SERIALIN, INPUT);

    digitalWrite(SERIALOUT, HIGH); // making sure it ends up being high when idle
}

bool CSender::sendToDE2(QString rightCode, QString tryCode){
    //digitalWrite(SERIALOUT, HIGH); // making sure it ends up being high when idle
    // start the old construtor
    int r_size = rightCode.length();
    int t_size = tryCode.length();
    int rightBinCode[8*r_size];
    int tryBinCode[8*t_size];

    cout << "The size of r_size: " << r_size << " = The size of t_size: " << t_size << endl;
    if(r_size <= 0 ||t_size <= 0){
        cout << "One of the values are below 1 in CSender constructor" << endl;
    } else {
        completeCode[0] = 0;    // start with 0 to start communication
        int pos = 1;            // used for position in the array
        int i;                  // used for bitshift
        int j;                  // used for position in the codearray
        cout << "The right code: ";
        for(j = 0; j < r_size; ++j){
            for (i = 0; i < 8; ++i, ++pos) {
                completeCode[pos] = !!((rightCode.at(j).toLatin1()<<(i))&0x80);
                cout << completeCode[pos];
            }
            cout << " ";        // for nice print lines
        }
        cout << endl;
        cout << "The right code new array: ";

        int arraypos = 0;
        for (j = 0; j < r_size; ++j) {
            for (i = 0; i < 8; ++i, ++arraypos) {
                rightBinCode[arraypos] = !!((rightCode.at(j).toLatin1()<<(i))&0x80);
                cout << rightBinCode[arraypos];
            }
        }


        pos = 64;               // make sure that every number gets treated the same way
        cout << "The try code: ";
        for (j = 0; j < t_size; ++j) {
            for (i = 0; i <8 ; ++i, ++pos) {
                completeCode[pos] = !!((tryCode.at(j).toLatin1()<<(i))&0x80);
                cout << completeCode[pos];
            }
            cout << " ";        // for nice print lines
        }
        cout << endl;
        pos = 129;              // Making sure that every size of strings get treated even
        completeCode[pos] = 1;  // Go high to end communication

        arraypos = 0;
        for (j = 0; j < r_size; ++j) {
            for (i = 0; i < 8; ++i, ++arraypos) {
                tryBinCode[arraypos] = !!((rightCode.at(j).toLatin1()<<(i))&0x80);
                cout << tryBinCode[arraypos];
            }
        }
        cout << "Is it empty? " << sendingQueue.empty() << endl
            << "This is the size of the Queue before adding items: " << sendingQueue.size() << endl;
        for (int k = 0; k < r_size; ++k) {      //Fill into the queue
            sendingQueue.push(0);
            for (int l = 0; l < 8; ++l) {
                sendingQueue.push(rightBinCode[l]);
            }
            sendingQueue.push(1);
            sendingQueue.push(1);
            sendingQueue.push(1);
            sendingQueue.push(0);
            for (int l = 0; l < 8; ++l) {
                sendingQueue.push(tryBinCode[l]);
            }
            sendingQueue.push(1);
            sendingQueue.push(1);
            sendingQueue.push(1);
        }
    }

    // start the old sendToDE2
    cout << endl;
    int i = 0;
    while(!sendingQueue.empty()){
        if (sendingQueue.front() == 1){
            digitalWrite(SERIALOUT,HIGH);
            cout << "1" ;
        } else {
            digitalWrite(SERIALOUT,LOW);
            cout << "0" ;
        }
        sendingQueue.pop();
        delayMicroseconds(380);
        if(i != 0 && i%22==0){
            if(!digitalRead(SERIALIN)){
                cout << "The response is false and i is: " << i << endl;
                digitalWrite(SERIALOUT, HIGH); // making sure it ends up being high when idle
                return false;
            }
        }
        ++i;
    }

    digitalWrite(SERIALOUT, HIGH); // making sure it ends up being high when idle

    if(digitalRead(SERIALIN)){
        cout << "The response is true!" << endl;
        return true;
    } else {
        cout << "The response is false!" << endl;
        return false;
    }
}

