#include "star5.h"
#include <cmath>

Star5::Star5() {}

QRectF Star5::boundingRect() const {
    return QRectF(-outerRadius, -outerRadius, outerRadius * 2, outerRadius * 2);
}

void Star5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    QPen rect;
    rect.setColor(Qt::black);
    painter->setPen(rect);

    QPolygonF starPolygon;
    for (int i = 0; i < 10; ++i) {
        qreal angle = i * 2.0 * M_PI / 10 - M_PI / 2;
        qreal radius = (i % 2 == 0) ? outerRadius : outerRadius / dif;
        QPointF point(centerX + radius * cos(angle), centerY + radius * sin(angle));
        starPolygon << point;
    }

    painter->drawPolygon(starPolygon);
}

qreal Star5::Perimeter() {

    qreal angle1 = 2.0 * M_PI / 10 - M_PI / 2;
    qreal angle2 = 2.0 * 2.0 * M_PI / 10 - M_PI / 2;

    QPointF point1 = QPointF(centerX + outerRadius * cos(angle1), centerY + outerRadius * sin(angle1));
    QPointF point2 = QPointF(centerX + (outerRadius / dif) * cos(angle2), centerY + (outerRadius / dif) * sin(angle2));

    qreal length = sqrt((point1.x() - point2.x()) * (point1.x() - point2.x()) + (point1.y() - point2.y()) * (point1.y() - point2.y()));

    qreal perimeter = length * 10;
    return perimeter;
}

qreal Star5::Area() {

    qreal angle1 = 2.0 * M_PI / 10 - M_PI / 2;
    qreal angle2 = 2.0 * 2.0 * M_PI / 10 - M_PI / 2;
    qreal angle4 = 4.0 * 2.0 * M_PI / 10 - M_PI / 2;

    QPointF p1 = QPointF(centerX + outerRadius * cos(angle1), centerY + outerRadius * sin(angle1));
    QPointF p2 = QPointF(centerX + (outerRadius / dif) * cos(angle2), centerY + (outerRadius / dif) * sin(angle2));
    QPointF p4 = QPointF(centerX + (outerRadius / dif) * cos(angle4), centerY + (outerRadius / dif) * sin(angle4));

    qreal len = sqrt((p1.x() - p2.x()) * (p1.x() - p2.x()) + (p1.y() - p2.y()) * (p1.y() - p2.y()));
    qreal sidebase = sqrt((p4.x() - p2.x()) * (p4.x() - p2.x()) + (p4.y() - p2.y()) * (p4.y() - p2.y()));

    qreal areatriangle = (sidebase / 4) * sqrt(4 * len * len - sidebase * sidebase);
    qreal areadop = (5 * sidebase * sidebase) / (4 * tan(M_PI / 5));

    return 5 * areatriangle + areadop;
}

qreal Star5::newArea(qreal number) {

    return outerRadius += number;
}

void Star5::newparametrs(double side_1, double side_2, double side_3) {

    qreal a;
    if(side_2 > side_1) {
        a = side_1;
        side_1 = side_2;
        side_2 = a;
    }
    outerRadius = side_1;
    dif = side_1 / side_2;
}
