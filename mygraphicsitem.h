#ifndef MYGRAPHICSITEM_H
#define MYGRAPHICSITEM_H

#include <QGraphicsItem>
#include <QRectF>


class MyGraphicsItem : public QGraphicsItem
{

public:
    MyGraphicsItem(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
   double xpos;
   double ypos;
   double xc;
   double yc;
   int v1; //vitesse
   const double pi=3.14159265359;



signals:

public slots:
};

#endif // MYGRAPHICSITEM_H
