//
// Created by Virkman on 30-05-2016.
//

#ifndef QTPROJECT2_CSENDER_H
#define QTPROJECT2_CSENDER_H

#include <QtCore/QString>
#include <queue>

using namespace std;
class CSender {
public:
    CSender();
    bool sendToDE2(QString rightCode, QString tryCode);

private:
    int completeCode [130] = {0};
    queue<int> sendingQueue;
};

#endif //QTPROJECT2_CSENDER_H
