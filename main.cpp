#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedLayout>
#include <MainPage.h>
#include "LoginDialog.h"

using namespace std;
int main(int argc, char *argv[]) {
    QApplication app(argc,argv);
    cout << "Hello World" << endl;


    //EnhedsHaandtering test;
    //test.show();
    //StackedLayout intro;
    //intro.show();
    MainPage page;
    page.show();
    return app.exec();
}