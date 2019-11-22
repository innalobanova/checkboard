#include "mygraphicsitem.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>

MyGraphicsItem::MyGraphicsItem (QGraphicsItem *parent) :
    QGraphicsItem(parent)
{


}

QRectF MyGraphicsItem::boundingRect() const
{
    QRectF rectf(0,0,400,400);


    return rectf;
}

void MyGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{ QPen pen;
   // QRectF rect(0,0,400,400);
    int startAngle = -45 * 16;
    int spanAngle = 270 * 16;
    pen.setColor(Qt::blue);
    pen.setWidth(5);
    painter->setPen(pen);
    painter->drawArc(40,40,320,320,startAngle,spanAngle);
    xc=200;
    yc=200;

    xpos=xc+qRound(160*cos((225-v)*pi/180));
    ypos=yc-qRound(160*sin((225-v)*pi/180));
    qDebug()<<(160*cos((225-v)*pi/180.0))<<"\n"<<qRound(160*cos((225-v)*pi/180));
   /* pen.setColor(Qt::red);
    pen.setWidth(5);
    painter->setPen(pen);
    painter->drawLine(xc,yc,xpos,ypos);*/
    QBrush brush;
    pen.setWidth(1);
    brush.setStyle(Qt::SolidPattern);


    pen.setColor(Qt::red);
    brush.setColor(Qt::red);
    painter->setPen(pen);
    painter->setBrush(brush);
    QPointF points[3] = {
          QPointF(xc-qRound(7*cos((225-v-90)*pi/180)),yc+qRound(7*sin((225-v-90)*pi/180))),
          QPointF(xpos, ypos),
          QPointF(xc+qRound(7*cos((225-v-90)*pi/180)),yc-qRound(7*sin((225-v-90)*pi/180)))
           };

    painter->drawConvexPolygon(points, 3);
    pen.setColor(Qt::black);
    brush.setColor(Qt::black);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(xc-15,yc-15,30,30);









}
