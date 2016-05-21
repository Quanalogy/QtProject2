//
// Created by Munke on 18-05-2016.
//

#ifndef QTPROJECT_WRITEFROMPI_H
#define QTPROJECT_WRITEFROMPI_H


#include <QtWidgets/QLineEdit>

class WriteFromPi : QWidget{
    Q_OBJECT
public:
    WriteFromPi(QWidget *parent =0);

private:
    void ConvertToBinary(int n);
    QLineEdit *brightness;
    int binaryArray[7] = {0};
    int input;
    int x10Array[14] ={0};
    int binaryIndex =0;
public slots:
    void SendSignal();
    void StopSignal();
    void RestartSignal();
    void HandleInputInt();

};


#endif //QTPROJECT_WRITEFROMPI_H
