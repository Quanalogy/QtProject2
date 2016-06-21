//
// Created by Virkman on 24-05-2016.
//

#ifndef QTPROJECT2_WORKER_H
#define QTPROJECT2_WORKER_H

#include <QObject>
#include <QThread>
#include "Unit.h"

class Worker : public QThread
{
Q_OBJECT

public:
    Worker(QObject *parent);
    void setUnitList(QList<Unit *> list);
    void setDagAftenUnit(QList<Unit *> daglist, QList<Unit *> aftenlist);
    void setStyrker(QList<QString> dagstyrker, QList<QString> aftenstyrker );
    void setTider(QList<QString> dagtider , QList<QString> aftentider);
    void setAAStime(int hour);
    void nfcChecked();
    void stopWork();
    bool isRunning();

public slots:
    //void stopWork();

signals:
    void finished();

private:
    void run();
    bool m_running;
    QList<Unit *> unitList;
    QList<Unit *> aftenList;
    QList<Unit *> dagList;

    QString dagFratid;
    QString dagTiltid;
    QString natFratid;
    QString natTiltid;

    int AAStime;

    int idagFraTime;
    int idagFraMin;
    int idagTilTime;
    int idagTilMin;

    int inatFraTime;
    int inatFraMin;
    int inatTilTime;
    int inatTilMin;

    QList<Unit *> *dagUnits;
    QList<Unit *> *aftenUnits;

    QList<int *> dagTider;
    QList<int *> aftenTider;

    QList<QString> dagStyrker;
    QList<QString> aftenStyrker;

    void controlAdfaerd();


};

#endif //QTPROJECT2_WORKER_H
