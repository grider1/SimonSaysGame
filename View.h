#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include "Model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(Model& model, QWidget *parent = nullptr);
    ~View();

public slots:
    void displayColor(std::string);
    void stopPlayerInput();

private:
    Ui::View *ui;

    void turnOffButtons();
    void lightRedButton();
    void lightBlueButton();
};
#endif // VIEW_H
