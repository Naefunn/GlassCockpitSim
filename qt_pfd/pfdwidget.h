#ifndef PFDWIDGET_H
#define PFDWIDGET_H

#include <QWidget>

class PFDWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PFDWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

public:
    void setPitch(double pitch) {pitchDegrees = pitch;}
    void setRoll(double roll) {rollDegrees = roll;}

private:
    double pitchDegrees;
    double rollDegrees;
};

#endif // PFDWIDGET_H
