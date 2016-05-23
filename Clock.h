//
// Created by Virkman on 23-05-2016.
//

#ifndef QTPROJECT2_CLOCK_H
#define QTPROJECT2_CLOCK_H

#include <QtWidgets/QLCDNumber>
#include <QtCore/QTimer>

class Clock : public QLCDNumber
{
    Q_OBJECT

public:
    Clock(QWidget *parent = 0);

public slots:
    QString showTime();

private:
    QTimer *timer;
};

#endif //QTPROJECT2_CLOCK_H
