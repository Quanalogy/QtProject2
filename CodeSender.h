//
// Created by Virkman on 30-05-2016.
//

#ifndef QTPROJECT2_CODESENDER_H
#define QTPROJECT2_CODESENDER_H

#include <QtCore/QString>

using namespace std;
class CodeSender {
    public:
        CodeSender(QString rightCode, QString tryCode);
        void sendToDE2();

    private:
        int bin_rightCode [64];
        int bin_tryCode [64];
        int completeCode [130];


};


#endif //QTPROJECT2_CODESENDER_H
