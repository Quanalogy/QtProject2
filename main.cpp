#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedLayout>
#include <MainPage.h>
#include "LoginDialog.h"
#include "QMainApp.h"
/*//#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>*/
using namespace std;
int main(int argc, char *argv[]) {
    QMainApp app(argc,argv);
    cout << "Hello World" << endl;
/*    if (wiringPiSetupGpio() == -1){
        exit (1) ;
    }
    pinMode(18,PWM_OUTPUT);
    pwmSetClock(80);
    pwmSetRange (10);
  */  //pwmWrite(18,5);
    //    wiringPiISR (24, INT_EDGE_BOTH, &Send120kHz::SendSignal);


    return app.exec();
}