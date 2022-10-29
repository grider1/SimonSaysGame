#ifndef MYTIMER_H
#define MYTIMER_H

#include "Model.h"
#include <QTimer>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer(Model& model);
    QTimer *timer;
};

#endif // MYTIMER_H
