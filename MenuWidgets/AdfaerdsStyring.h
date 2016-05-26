//
// Created by Munke on 13-04-2016.
//

#ifndef QTPROJECT_ADFAERDSSTYRING_H
#define QTPROJECT_ADFAERDSSTYRING_H


#include "MenuWidget.h"
#include "../Unit.h"
#include "../Clock.h"
#include "../Worker.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

class AdfaerdsStyring : public MenuWidget {
Q_OBJECT
public:
    AdfaerdsStyring(QWidget *parent = 0);
    QString getName();
    bool notNull();
    void setUnitsList(QList<Unit *> list);
    void addBox();
    void removeBox();
    void changeSave();
    void setFirstTime(bool set);
    void startWork();
    void stopWork();

private:
    QString name = "Adfærdsstyring";
    QList<QLabel *> leftList;
    QList<QLabel *> rightList;

    QVBoxLayout *lefVertivalLayout;
    QVBoxLayout *rigVerticalLayout;
    QHBoxLayout *controlHorizontalLayout;
    QHBoxLayout *timeDagFraHorizontalLayout;
    QHBoxLayout *timeDagTilHorizontalLayout;
    QHBoxLayout *timeNatFraHorizontalLayout;
    QHBoxLayout *timeNatTilHorizontalLayout;
    QVBoxLayout *mainLayout;

    QPushButton *save;
    QPushButton *cancel;

    QLineEdit *dagFraTime;
    QLineEdit *dagFraMin;
    QLineEdit *dagTilTime;
    QLineEdit *dagTilMin;
    QLineEdit *natFraTime;
    QLineEdit *natFraMin;
    QLineEdit *natTilTime;
    QLineEdit *natTilMin;


    QString idagFraTime;
    QString idagFraMin;
    QString idagTilTime;
    QString idagTilMin;
    QString inatFraTime;
    QString inatFraMin;
    QString inatTilTime;
    QString inatTilMin;

    QList<Unit *> unitsList;
    QList<QCheckBox *> lefCheckBoxes;
    QList<QCheckBox *> rigCheckBoxes;
    QList<QLineEdit *> lefLineEdits;
    QList<QLineEdit *> rigLineEdits;

    QList<QString> dagTider;
    QList<QString> aftenTider;

    QList<Unit *> dagUnits;
    QList<Unit *> aftenUnits;

    QList<QString> dagStyrker;
    QList<QString> aftenStyrker;

    QLabel *intervalNat;
    QLabel *intervalDag;

    QHBoxLayout *topLayout;
    QLabel *userName;
    Clock *tempClock;
    QWidget *horizontalLineWidget;

    bool firstTime;

    QThread *workerThread;
    Worker *worker;

    int workCount;


public slots:
    void saveIntervals();;

private slots:
    void ifDagModified();
    void ifNatModified();
};


#endif //QTPROJECT_ADFAERDSSTYRING_H
