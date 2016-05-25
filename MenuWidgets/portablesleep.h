//
// Created by Virkman on 24-05-2016.
//

#ifndef QTPROJECT2_PORTABLESLEEP_H
#define QTPROJECT2_PORTABLESLEEP_H

#ifdef _WIN32
#  include <windows.h>
#else
#  include <unistd.h>
#endif

class PortableSleep
{
public:
    static void msleep(unsigned int milliSec)
    {
#ifdef _WIN32
        Sleep(milliSec);
#else
        usleep(milliSec * 1000);
#endif
    };
};

#endif //QTPROJECT2_PORTABLESLEEP_H
