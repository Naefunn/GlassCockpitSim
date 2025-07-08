#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "pfdwidget.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , aircraft(new AircraftState())
{
    ui->setupUi(this);

    pfdWidget = new PFDWidget(this);
    setCentralWidget(pfdWidget);

    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateDisplay);
    updateTimer->start(50);
}


MainWindow::~MainWindow()
{
    delete aircraft;
    delete ui;
}

void MainWindow::updateDisplay()
{
    static double t = 0.0;
    const double dt = 0.05;

    t += dt;

    aircraft->setTargetPitch(10.0);
    aircraft->setTargetRoll(15);

    aircraft->update(dt);

    pfdWidget->setPitch(aircraft->getPitch());
    pfdWidget->setRoll(aircraft->getRoll());

    pfdWidget->update();
}
