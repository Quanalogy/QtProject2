#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedLayout>
#include <MainPage.h>
#include "LoginDialog.h"
#include "QMainApp.h"

using namespace std;
int main(int argc, char *argv[]) {
    QMainApp app(argc,argv);
    cout << "Hello World" << endl;


    return app.exec();
}