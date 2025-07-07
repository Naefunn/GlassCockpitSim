#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "pfdwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    aircraft = new AircraftState();
    pfdWidget = new PFDWidget(this);
    setCentralWidget(pfdWidget);

    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, [this]() {
        aircraft->update(0.1);
        pfdWidget->setPitch(aircraft->getPitch());
        pfdWidget->setRoll(aircraft->getRoll());
        // update for other attributes
        pfdWidget->update();
    });
    updateTimer->start(100);
}


MainWindow::~MainWindow()
{
    delete ui;
}
