//
// Created by Virkman on 30-05-2016.
//

#ifndef QTPROJECT2_CSENDER_H
#define QTPROJECT2_CSENDER_H

#include <QtCore/QString>

using namespace std;
class CSender {
public:
    CSender(QString rightCode, QString tryCode);
    void sendToDE2();
    bool isItOpen();

private:
    int completeCode [130];


};

#endif //QTPROJECT2_CSENDER_H
