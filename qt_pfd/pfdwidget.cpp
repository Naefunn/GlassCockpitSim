#include "pfdwidget.h"
#include <QPainter>

PFDWidget::PFDWidget(QWidget *parent)
    : QWidget(parent)
{
}

void PFDWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    double pitchOffset = pitchDegrees * 4.0;

    double rollRadians = rollDegrees * M_PI / 180;

    // move painter origin to center
    painter.translate(width() / 2, height() / 2);

    // apply roll
    painter.rotate(-rollDegrees);

    // apply pitch
    painter.translate(0, pitchOffset);

    // sky
    painter.fillRect(QRect(-width(), -height() * 2, width() * 2, height() * 2), QColor(80, 160, 255));

    // ground
    painter.fillRect(QRect(-width(), 0, width() * 2, height() * 2), QColor(180, 120, 60));

    // horizon line
    painter.setPen(QPen(Qt::white, 2));
    painter.drawLine(-width(), 0, width(), 0);

}
