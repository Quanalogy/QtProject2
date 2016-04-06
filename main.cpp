#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedLayout>
#include "VerticalBox.h"
#include "Nesting.h"
#include "StackedLayout.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "Hello, World!" << endl;

    QApplication app(argc,argv);
/*
    VerticalBox window;
    window.resize(300,400);
    window.setWindowTitle("This is the title");
    window.show();
*/
/*
    Nesting window;
    window.setWindowTitle("This is the title");
    window.show();
*/

    StackedLayout stackedLayout;
    stackedLayout.setWindowTitle("This is the title");
    stackedLayout.show();
    return app.exec();
}