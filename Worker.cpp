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
    unitList = list;
}

void Worker::setDagAftenUnit(QList<Unit *> daglist, QList<Unit *> aftenlist) {
    dagList = daglist;
    aftenList = aftenlist;
}

void Worker::setStyrker(QList<QString *> dagstyrker, QList<QString *> aftenstyrker ) {
    dagStyrker = dagstyrker;
    aftenStyrker = aftenstyrker;

}

void Worker::setTider(QList<QString> dagtider, QList<QString> aftentider) {
    cout << "yes" << endl;

    QString temp = dagtider.at(3);


    qDebug() << temp << endl;

    dagFratid.clear();
    dagTiltid.clear();
    natFratid.clear();
    natTiltid.clear();


    dagFratid.append(dagtider.at(0));
    dagFratid.append(":");
    dagFratid.append(dagtider.at(1));
    dagFratid.append(":");
    dagFratid.append("00");
    cout << "yes" << endl;

    dagTiltid.append(dagtider.at(2));
    dagTiltid.append(":");
    dagTiltid.append(dagtider.at(3));
    dagTiltid.append(":");
    dagTiltid.append("00");

    natFratid.append(aftentider.at(0));
    natFratid.append(":");
    natFratid.append(aftentider.at(1));
    natFratid.append(":");
    natFratid.append("00");

    natTiltid.append(aftentider.at(2));
    natTiltid.append(":");
    natTiltid.append(aftentider.at(3));
    natTiltid.append(":");
    natTiltid.append("00");
    cout << "yes" << endl;


}

void Worker::setAAStime(int hour) {
    AAStime = hour;
}

bool Worker::controlAdfaerd() {
    cout << "tester i sekundet" << endl;
    QTime temptime = QTime::currentTime();
    QString tempStime = temptime.toString();
    if (tempStime == dagFratid){
        cout << "tester i sekundet::: passeger" << dagList.size() << endl;
        for (int i = 0 ; i < dagList.size() ; i++){
            for(int j = 0 ; j < unitList.size() ; j++){
                if (dagList.at(i)->getId() == unitList.at(j)->getId()){
                    int temp = int( dagStyrker.at(i));
                    unitList.at(j)->setVolume(temp);
                    unitList.at(j)->setToggle(true);
                    cout << "tester i sekundet::: sætter unit" << endl;
                }
            }
        }
        static_cast<QMainApp *>qApp->setUnitList(unitList);
    }
    if (tempStime == dagTiltid){
        for (int i = 0 ; i < dagList.size() ; i++){
            for(int j = 0 ; j < unitList.size() ; j++){
                if (dagList.at(i)->getId() == unitList.at(j)->getId()){
                    unitList.at(j)->setVolume(70);
                    unitList.at(j)->setToggle(false);
                }
            }
        }
        static_cast<QMainApp *>qApp->setUnitList(unitList);
    }
    if (tempStime == natFratid){
        for (int i = 0 ; i < aftenList.size() ; i++){
            for(int j = 0 ; j < unitList.size() ; j++){
                if (aftenList.at(i)->getId() == unitList.at(j)->getId()){
                    int temp = int( aftenStyrker.at(i));
                    unitList.at(j)->setVolume(temp);
                    unitList.at(j)->setToggle(true);
                }
            }
        }
        static_cast<QMainApp *>qApp->setUnitList(unitList);
    }
    if (tempStime == natTiltid){
        for (int i = 0 ; i < aftenList.size() ; i++){
            for(int j = 0 ; j < unitList.size() ; j++){
                if (aftenList.at(i)->getId() == unitList.at(j)->getId()){
                    unitList.at(j)->setVolume(70);
                    unitList.at(j)->setToggle(false);
                }
            }
        }
        static_cast<QMainApp *>qApp->setUnitList(unitList);
    }
}

bool Worker::controlAktivitet() {
}

bool Worker::isRunning() {
    return m_running;
}