#ifndef GAUGE_H
#define GAUGE_H

#include <QGraphicsItem>
#include <QRectF>

class Gauge : public QGraphicsItem
{
public:
    Gauge();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    const double pi=3.14159265359;
  // double xpos;
  // double ypos;
   double xc;
   double yc;
   double xl;
   double yl;
   int startAngle;
   int spanAngle;
   int vmax;
   int alpha;//vitesse
   QString font;
   int shift;


};

#endif // GAUGE_H
