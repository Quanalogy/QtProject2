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
    int i = 0;
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

bool Worker::controlAdfaerd() {

    QTime temptime = QTime::currentTime();
    QString tempStime = temptime.toString(); //.left(temptime.toString().size() - 3);

    if (tempStime == dagFratid && !isItNat){
        for (int i = 0 ; i < dagList.size() ; i++){
            for(int j = 0 ; j < unitList.size() ; j++){
                    if (dagList.at(i)->getId() == unitList.at(j)->getId() ) {
                        int temp = dagStyrker.at(i).toInt();
                        unitList.at(j)->setVolume(temp);
                        unitList.at(j)->setToggle(true);
                    }

            }
        }
        isItDay = true;
        static_cast<QMainApp *>qApp->setUnitList(unitList);
    }
    if (tempStime == dagTiltid && !isItNat){
        for (int i = 0 ; i < dagList.size() ; i++){
            for(int j = 0 ; j < unitList.size() ; j++){
                if (dagList.at(i)->getId() == unitList.at(j)->getId()){
                    unitList.at(j)->setVolume(70);
                    unitList.at(j)->setToggle(false);
                }
            }
        }
        isItDay = false;
        static_cast<QMainApp *>qApp->setUnitList(unitList);
    }
    if (tempStime == natFratid && !isItDay){
        for (int i = 0 ; i < aftenList.size() ; i++){
            for(int j = 0 ; j < unitList.size() ; j++){
                if (aftenList.at(i)->getId() == unitList.at(j)->getId()){
                    int temp = aftenStyrker.at(i).toInt();
                    cout << temp << endl;
                    unitList.at(j)->setVolume(temp);
                    unitList.at(j)->setToggle(true);

                }
            }
        }
        isItNat = true;
        static_cast<QMainApp *>qApp->setUnitList(unitList);
    }
    if (tempStime == natTiltid && !isItDay){
        for (int i = 0 ; i < aftenList.size() ; i++){
            for(int j = 0 ; j < unitList.size() ; j++){
                if (aftenList.at(i)->getId() == unitList.at(j)->getId()){
                    unitList.at(j)->setVolume(70);
                    unitList.at(j)->setToggle(false);
                }
            }
        }
        isItNat = false;
        static_cast<QMainApp *>qApp->setUnitList(unitList);
    }
}

bool Worker::controlAktivitet() {
}

bool Worker::isRunning() {
    return m_running;
}