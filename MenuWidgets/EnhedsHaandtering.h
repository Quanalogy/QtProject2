//
// Created by Munke on 23-04-2016.
//

#ifndef QTPROJECT_ENHEDSHAANDTERING_H
#define QTPROJECT_ENHEDSHAANDTERING_H


//#include <QtWidgets/QWidget>
#include "MenuWidget.h"
#include "../Unit.h"
#include "../Clock.h"
#include <QtWidgets/QLabel>

class EnhedsHaandtering : public MenuWidget{
    Q_OBJECT
public:
    EnhedsHaandtering(QWidget *parent = 0);
    QString getName();
    bool notNull();
    int getEditLineID();
    QString getEditLineName();
    void setUnitsList(QList<Unit *> list);
    QList<Unit *> getUnitsList();
    void addBox();
    void removeBox();
    bool isChecked();
    void removeIfChecked();
    bool checkIfSerieExist();
    bool checkIfNavnExist();
    bool somethingWritten();

private:
    int unitCount;
    QString name = "Enhedshåndtering";
    QList<QLabel *> leftList;
    QList<QLabel *> rightList;
    QLineEdit *serienummerInput;
    QLineEdit *unitNameInput;
    void addUnitsToList();
    QList<Unit *> unitsList;
    QList<QCheckBox *> checkBoxes;
    QVBoxLayout *rVerticalLayout;
    QVBoxLayout *lVerticalLayout;
    QPushButton *save;
    QPushButton *cancel;

    QHBoxLayout *horizontalLayout;
    QHBoxLayout *boxlayout;
    QVBoxLayout *mainlayout;
    QHBoxLayout *topLayout;
    QLabel *userName;
    Clock *tempClock;
    QWidget *horizontalLineWidget;


signals:
    void onSaveClick();
    void onCancelClick();
};


#endif //QTPROJECT_ENHEDSHAANDTERING_H
