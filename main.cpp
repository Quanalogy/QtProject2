#include <iostream>
#include "QMainApp.h"
#include "MenuWidget.h"
#include "CSender.h"

using namespace std;
int main(int argc, char *argv[]) {
    QMainApp app(argc,argv);
    cout << "Hello World" << endl;
    return app.exec();

}