//
// Created by Munke on 30-05-2016.
//

#ifndef QTPROJECT2_SENDONX10_H
#define QTPROJECT2_SENDONX10_H


class SendOnX10 {

public:
    SendOnX10();
    void SendCommunication(int unitID, bool aktivSim, int lightLevel);
private:
    void convertLightToX10(int lightLevel_);
    void convertUnitToX10(int unitNumber);
    int x10LightArray[14] = {0};
    int x10UnitArray[10] = {0};
};


#endif //QTPROJECT2_SENDONX10_H
