//
// Created by Munke on 05-04-2016.
//

#ifndef QTPROJECT_STACKEDLAYOUT_H
#define QTPROJECT_STACKEDLAYOUT_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QStackedLayout>

class StackedLayout : public QWidget{
public:
    StackedLayout(QWidget *parent = 0);

public slots:
    void onPrevClick();
    void onNextClick();

private:
    QStackedLayout *stackedLayout = new QStackedLayout;
    //QStackedLayout *stackedLayout;
};


#endif //QTPROJECT_STACKEDLAYOUT_H
