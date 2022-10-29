#include "View.h"
#include "MyTimer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    MyTimer timer(model);
    View w(model);
    w.show();
    return a.exec();
}
