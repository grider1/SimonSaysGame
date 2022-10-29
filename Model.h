#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <vector>

class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);

public slots:
    void timerUpdate();
    void blueButtonPressed();
    void redButtonPressed();
    void startButtonPress();

signals:
    void updateView(int);
    void toggleStartButton(bool);
    void toggleColorButtons(bool);
    void playColor(std::string);
    void clearColors();
    void endGame();
    void updatePercentageBar(int);

private:
    std::vector<std::string> colorSequence;
    std::vector<std::string> colorsToDisplay;
    int indexOfCurrentColor;
    bool computerTurnFlag;
    bool buttonLitFlag;

    void incrementSequence();
    int getCurrentPercentage();
    std::string pickRandomColor();
    void playThroughColorSequence();
    void resetGame();
};

#endif // MODEL_H
