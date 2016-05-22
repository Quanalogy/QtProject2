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
    void convertLightToX10(int lightLevel_);
    void convertUnitToX10(int unitNumber);
    QLineEdit *brightness;
    int binaryLightArray[7] = {0};   // a temp array for holding binary light level
    int binaryUnitArray[5] = {0};     // a temp array for holding binary unit number
    int input;
    int x10LightArray[14] = {0};
    int x10UnitArray[10] = {0};
    int * getx10Communication(int unit, bool pir, int lightLevel);
    int x10CommunacationArray[30] = {0};
public slots:
    void SendSignal();
    void StopSignal();
    void RestartSignal();
    void HandleInputInt();

};


#endif //QTPROJECT_WRITEFROMPI_H
