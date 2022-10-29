#include "Model.h"
#include "MyTimer.h"
#include <iostream>

Model::Model(QObject *parent)
    : QObject{parent}
{
    resetGame();
}

void Model::startButtonPress() {
    colorSequence = std::vector<std::string> {pickRandomColor()};
    computerTurnFlag = true;
    colorsToDisplay = colorSequence;
    emit toggleStartButton(false);
}

void Model::blueButtonPressed() {

    std::string correctColor = colorSequence[indexOfCurrentColor];
    if (correctColor == "blue") {
        emit updatePercentageBar(getCurrentPercentage());
        indexOfCurrentColor++;
        std::cout << "correct" << std::endl;
        std::cout << getCurrentPercentage() << std::endl;
    } else {
        std::cout << "wrong" << std::endl;
        resetGame();
        return;
    }

    if (indexOfCurrentColor >= colorSequence.size()) {
        std::cout << "over" << std::endl;
        indexOfCurrentColor = 0;
        incrementSequence();
        colorsToDisplay = colorSequence;
        emit toggleColorButtons(false);
        emit updatePercentageBar(0);
        computerTurnFlag = true;
        std::cout << colorSequence[colorSequence.size() - 1] << std::endl;
    }
}

void Model::redButtonPressed() {
    std::string correctColor = colorSequence[indexOfCurrentColor];
    if (correctColor == "red") {
        emit updatePercentageBar(getCurrentPercentage());
        indexOfCurrentColor++;
        std::cout << "correct" << std::endl;
        std::cout << getCurrentPercentage() << std::endl;
    } else {
        std::cout << "wrong" << std::endl;
        resetGame();
        return;
    }

    if (indexOfCurrentColor >= colorSequence.size()) {
        std::cout << "over" << std::endl;
        indexOfCurrentColor = 0;
        incrementSequence();
        colorsToDisplay = colorSequence;
        emit updatePercentageBar(0);
        emit toggleColorButtons(false);
        computerTurnFlag = true;
        std::cout << colorSequence[colorSequence.size() - 1] << std::endl;
    }
}

void Model::timerUpdate() {

    if (computerTurnFlag) {
        if (buttonLitFlag) {
            emit clearColors();
            buttonLitFlag = false;
        } else {
            if (colorsToDisplay.size() > 0) {
                emit playColor(colorsToDisplay[0]);
                colorsToDisplay.erase(colorsToDisplay.begin());
                buttonLitFlag = true;
            } else {
                computerTurnFlag = false;
                buttonLitFlag = false;
                emit clearColors();
                emit toggleColorButtons(true);
            }
        }
    }
}

void Model::resetGame() {
    emit endGame();
    emit clearColors();
    indexOfCurrentColor = 0;
    colorSequence = std::vector<std::string>();
    colorsToDisplay = std::vector<std::string>();
    computerTurnFlag = false;
    buttonLitFlag = false;
}

void Model::incrementSequence() {
    std::string nextColor = pickRandomColor();
    colorSequence.push_back(nextColor);
}

std::string Model::pickRandomColor() {
    int random = rand() % 2;
    if (random == 0) {
        return "red";
    }
    return "blue";
}

int Model::getCurrentPercentage() {
    double colorsLeft = colorSequence.size();
    double percentDecimal = (indexOfCurrentColor + 1)/colorsLeft;
    int percentage = int (100 * percentDecimal);
    return percentage;
}
