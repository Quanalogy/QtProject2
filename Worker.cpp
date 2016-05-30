//
// Created by Virkman on 24-05-2016.
//

#include "Worker.h"
#include <QApplication>
#include <QtCore/QTime>
#include "portablesleep.h"
#include "QMainApp.h"

Worker::Worker()
        : m_running(true)
{
}

void Worker::doWork()
{
    while (m_running) {
        controlAdfaerd();
        PortableSleep::msleep(1000);
    }
    emit finished();
}

void Worker::stopWork()
{
    m_running = false;
    emit finished();
}

void Worker::setUnitList(QList<Unit *> list) {
    for (int i = 0 ; i < unitList.size() ; i++){
        unitList.removeAt(i);
    }
    unitList = list;
}

void Worker::setDagAftenUnit(QList<Unit *> daglist, QList<Unit *> aftenlist) {
    for(int i = 0 ; i < daglist.size() ; i++){
        dagList.removeAt(i);
        dagStyrker.removeAt(i);
    }
    for(int i = 0 ; i < aftenlist.size() ; i++){
        aftenList.removeAt(i);
        aftenStyrker.removeAt(i);
    }
    dagList = daglist;
    aftenList = aftenlist;
}

void Worker::setStyrker(QList<QString> dagstyrker, QList<QString> aftenstyrker ) {
    dagStyrker.clear();
    aftenStyrker.clear();
    for(int j = 0 ; j < dagstyrker.size() ; j++){
       dagStyrker.append(dagstyrker.at(j));
    }
    for(int j = 0 ; j < aftenstyrker.size() ; j++){
        aftenStyrker.append(aftenstyrker.at(j));
    }
}

void Worker::setTider(QList<QString> dagtider, QList<QString> aftentider) {
    QString temp = dagtider.at(3);

    dagFratid.clear();
    dagTiltid.clear();
    natFratid.clear();
    natTiltid.clear();


    if (dagtider.at(0).length() == 1){
        dagFratid.append("0");
    }
    dagFratid.append(dagtider.at(0));
    dagFratid.append(":");
    dagFratid.append(dagtider.at(1));
    dagFratid.append(":");
    dagFratid.append("00");

    if (dagtider.at(2).length() == 1){
        dagFratid.append("0");
    }
    dagTiltid.append(dagtider.at(2));
    dagTiltid.append(":");
    dagTiltid.append(dagtider.at(3));
    dagTiltid.append(":");
    dagTiltid.append("00");

    if (aftentider.at(0).length() == 1){
        dagFratid.append("0");
    }
    natFratid.append(aftentider.at(0));
    natFratid.append(":");
    natFratid.append(aftentider.at(1));
    natFratid.append(":");
    natFratid.append("00");

    if (aftentider.at(2).length() == 1){
        dagFratid.append("0");
    }
    natTiltid.append(aftentider.at(2));
    natTiltid.append(":");
    natTiltid.append(aftentider.at(3));
    natTiltid.append(":");
    natTiltid.append("00");


}

void Worker::setAAStime(int hour) {
    AAStime = hour;
}

void Worker::controlAdfaerd() {

    QTime temptime = QTime::currentTime();
    QString tempStime = temptime.toString(); //.left(temptime.toString().size() - 3);

    if (tempStime == dagFratid ){
        for (int i = 0 ; i < unitList.size() ; i++){
            for(int j = 0 ; j < dagList.size() ; j++){
                    if (unitList.at(i)->getId() == dagList.at(j)->getId() ) {
                        int temp = dagStyrker.at(j).toInt();
                        unitList.at(i)->setVolume(temp);
                    }

            }
        }
        static_cast<QMainApp *>qApp->setUnitList(unitList);
        static_cast<QMainApp *>qApp->update();
    }
    if (tempStime == natFratid){
        for (int i = 0 ; i < unitList.size() ; i++){
            for(int j = 0 ; j < aftenList.size() ; j++){
                if (unitList.at(i)->getId() == aftenList.at(j)->getId()){
                    int temp = aftenStyrker.at(j).toInt();
                    unitList.at(i)->setVolume(temp);

                }
            }
        }
        static_cast<QMainApp *>qApp->setUnitList(unitList);
        static_cast<QMainApp *>qApp->update();
    }
}


bool Worker::isRunning() {
    return m_running;
}