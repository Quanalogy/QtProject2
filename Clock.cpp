//
// Created by Virkman on 23-05-2016.
//

#include "Clock.h"
#include <QHBoxLayout>
#include <QTime>
#include <QtGui/QtGui>

Clock::Clock(QLabel *parent)
        : QLabel(parent) {

    //hbox = new QVBoxLayout(this);
    //hbox->setSpacing(0);


    label = new QLabel("", this);
    //hbox->addWidget(label);

    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString();
    label->setText("<h4>" + stime + "<h4\>");
    label->setStyleSheet("QLabel { background-color : ; color : #a0a0a0; }");

    startTimer(1000);
}

void Clock::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);

    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString();
    label->setText("<h4>" + stime + "<h4\>");
}