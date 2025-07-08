#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "aircraftstate.h"
#include "pfdwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateDisplay();

private:
    Ui::MainWindow *ui;

    AircraftState *aircraft;
    PFDWidget *pfdWidget;
    QTimer *updateTimer;
};

#endif // MAINWINDOW_H
