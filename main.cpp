#include <iostream>
#include "QMainApp.h"
#include "MenuWidget.h"
#include "CSender.h"

using namespace std;
int main(int argc, char *argv[]) {
/*
    QApplication app(argc, argv);
    *//*QMainApp app(argc,argv);
     *
    cout << "Hello World" << endl;
    return app.exec();*//*

    return app.exec();*/

    CSender sender("Hej", "Med");
    sender.sendToDE2();
}