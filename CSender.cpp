//
// Created by Virkman on 30-05-2016.
//

#include <iostream>
#include "CSender.h"

CSender::CSender(QString rightCode, QString tryCode){
    int r_size = rightCode.length();
    int t_size = tryCode.length();

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
        pos = 64;               // make sure that every number gets treated the same way
        cout << "The try code: ";
        for (j = 0; j <t_size ; ++j) {
            for (i = 0; i <8 ; ++i, ++pos) {
                completeCode[pos] = !!((tryCode.at(j).toLatin1()<<(i))&0x80);
                cout << completeCode[pos];
            }
            cout << " ";        // for nice print lines
        }
        cout << endl;
        pos = 129;              // Making sure that every size of strings get treated even
        completeCode[pos] = 1;  // Go high to end communication

    }

}
void CSender::sendToDE2(){
    cout << endl;
    //pinMode(17, OUTPUT);
    for (int i = 0 ; i < 130 ; i++){
        if (completeCode[i] == 1){
            //digitalWrite(17,HIGH);
            cout << "1" ;
        } else {
            //digitalWrite(17,LOW);
            cout << "0" ;
        }
        //delayMicroseconds(15);
    }

}

