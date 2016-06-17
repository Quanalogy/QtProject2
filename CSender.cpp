//
// Created by Virkman on 30-05-2016.
//

#include <iostream>
#include <bitset>
#include "CSender.h"

CSender::CSender(QString rightCode, QString tryCode){
    int r_size = rightCode.length();
    int t_size = tryCode.length();
    cout << "This is the size of the password: " << r_size << " = size of try: " << t_size << endl;
    if(r_size <= 0 ||t_size <= 0){
        cout << "One of the values are numm in CSender constructor" << endl;
    } else {
        completeCode[0] = 0;
        int pos = 1;
        for (int i = 0 ; i < r_size ; i++){
            const std::string result = std::bitset<8>((int) rightCode.at(i).toLatin1()).to_string();
            for (int j = 0 ; j < 8 ; j++){
                if (result.at(j) == 48){
                    completeCode[pos] = 0;
                }
                if (result.at(j) == 49){
                    completeCode[pos] = 1;
                }
                pos++;
            }
        }
        int r_lastBits = 8 - r_size;
        for (int k = 0 ; k < r_lastBits ; k++){
            for (int l = 0 ; l < 8 ; l++){
                completeCode[pos] = 0;
                pos++;
            }
        }
        for (int i = 0 ; i < t_size ; i++){
            const std::string result = std::bitset<8>((int) tryCode.at(i).toLatin1()).to_string();
            for (int j = 0 ; j < 8 ; j++){
                if (result.at(j) == 48){
                    completeCode[pos] = 0;
                }
                if (result.at(j) == 49){
                    completeCode[pos] = 1;
                }
                pos++;
            }
        }
        int t_lastBits = 8 - r_size;
        for (int k = 0 ; k < t_lastBits ; k++){
            for (int l = 0 ; l < 8 ; l++){
                completeCode[pos] = 0;
                pos++;
            }
        }
        completeCode[pos] = 1;
        for (int m = 0 ; m < 130 ; m++){
            cout << completeCode[m];
        }
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

