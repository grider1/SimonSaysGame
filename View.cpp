#include "View.h"
#include "ui_View.h"
#include "Model.h"

View::View(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
    ui->blueButton->setEnabled(false);
    ui->redButton->setEnabled(false);
    ui->progressBar->setValue(0);
    ui->loseLabel->setVisible(false);

    connect(ui->startButton,
            &QPushButton::clicked,
            &model,
            &Model::startButtonPress);
    connect(&model,
            &Model::toggleStartButton,
            ui->startButton,
            &QPushButton::setEnabled);
    connect(&model,
            &Model::toggleStartButton,
            ui->loseLabel,
            &QLabel::setVisible);
    connect(&model,
            &Model::playColor,
            this,
            &View::displayColor);
    connect(ui->blueButton,
            &QPushButton::clicked,
            &model,
            &Model::blueButtonPressed);
    connect(ui->redButton,
            &QPushButton::clicked,
            &model,
            &Model::redButtonPressed);
    connect(&model,
            &Model::toggleColorButtons,
            ui->redButton,
            &QPushButton::setEnabled);
    connect(&model,
            &Model::toggleColorButtons,
            ui->blueButton,
            &QPushButton::setEnabled);
    connect(&model,
            &Model::clearColors,
            this,
            &View::turnOffButtons);
    connect(&model,
            &Model::endGame,
            this,
            &View::stopPlayerInput);
    connect(&model,
            &Model::updatePercentageBar,
            ui->progressBar,
            &QProgressBar::setValue);
}

View::~View()
{
    delete ui;
}

void View::displayColor(std::string color) {
    if (color == "red") {
        lightRedButton();
    } else {
        lightBlueButton();
    }
}

void View::lightRedButton() {
    ui->redButton->setStyleSheet( QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
}

void View::lightBlueButton() {
    ui->blueButton->setStyleSheet( QString("QPushButton {background-color: rgb(0,0,255);} QPushButton:pressed {background-color: rgb(142,142,255);}"));
}

void View::turnOffButtons() {
    ui->redButton->setStyleSheet( QString("QPushButton {background-color: rgb(255,255,255);} QPushButton:pressed {background-color: rgb(200,50,50);}"));
    ui->blueButton->setStyleSheet( QString("QPushButton {background-color: rgb(255,255,255);} QPushButton:pressed {background-color: rgb(0,0,255);}"));
}

void View::stopPlayerInput() {
    ui->loseLabel->setVisible(true);
    ui->blueButton->setEnabled(false);
    ui->redButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    ui->progressBar->setValue(0);
}
