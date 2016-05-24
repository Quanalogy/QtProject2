//
// Created by Virkman on 23-05-2016.
//

#ifndef QTPROJECT2_CLOCK_H
#define QTPROJECT2_CLOCK_H

#include <QWidget>
#include <QLabel>
#include <QtWidgets/QHBoxLayout>

class Clock : public QLabel {

public:
    Clock(QLabel *parent = 0);
    //QVBoxLayout *hbox;
protected:
    void timerEvent(QTimerEvent *e);

private:
    QLabel *label;

};

#endif //QTPROJECT2_CLOCK_H
