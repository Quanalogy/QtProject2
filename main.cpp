#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedLayout>
#include "StackedLayout.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc,argv);

    StackedLayout intro;
    intro.show();
    return app.exec();
}