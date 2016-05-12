#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedLayout>
#include "StackedLayout.h"
#include "MenuWidgets/EnhedsHaandtering.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc,argv);
    cout << "Hello World" << endl;
    Q
    //EnhedsHaandtering test;
    //test.show();
    StackedLayout intro;
    intro.show();
    return app.exec();
}