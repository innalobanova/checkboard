#include "mygraphicsitem.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>

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
    pen.setWidth(40);
    painter->setPen(pen);
    painter->drawArc(40,40,320,320,startAngle,spanAngle);
    xc=200;
    yc=200;

    xpos=xc+qRound(160*cos((225-v)*pi/180));
    ypos=yc-qRound(160*sin((225-v)*pi/180));
    qDebug()<<(160*cos((225-v)*pi/180.0))<<"\n"<<qRound(160*cos((225-v)*pi/180));
    pen.setColor(Qt::red);
    pen.setWidth(5);
    painter->setPen(pen);
    painter->drawLine(xc,yc,xpos,ypos);









}
