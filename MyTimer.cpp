#include "MyTimer.h"
#include "Model.h"
#include <QDebug>
#include <iostream>

MyTimer::MyTimer(Model& model)
{
    // create a timer
    timer = new QTimer(this);

    // setup signal and slot
    connect(timer, &QTimer::timeout,
          &model, &Model::timerUpdate);

    // msec
    timer->start(1000);
}
