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
{ int v;
    if (v1>=0 && v1 <=270) {v=v1;}
    else if (v1<0) {v=0;}
    else {v=270;}
    QPen pen;
    QBrush brush(Qt::SolidPattern);
    brush.setColor("#F1EDED");
    painter->fillRect(this->boundingRect(),brush);
    xc=200.0;
    yc=200.0;
    double c=cos((225-v)*pi/180);
    double s=sin((225-v)*pi/180);


    xpos=xc+160*c;
    ypos=yc-160*s;
   // qDebug()<<(160*c)<<"\n"<<qRound(160*c);
    // Block drawArc

   { int startAngle = 225 * 16;
    int spanAngle = - v * 16;
    pen.setColor("#BBE7DD");
    pen.setWidth(30);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setStyle(Qt::SolidLine);

    painter->setPen(pen);
    painter->drawArc(40,40,320,320,startAngle,spanAngle);
    }

   //Block draw Fleche

   {
    pen.setWidth(1);
    pen.setColor("#310B0B");
    QLinearGradient linearGrad(QPointF(xc-(9*cos((225-v-90)*pi/180)),yc+(9*sin((225-v-90)*pi/180))), QPointF(xc+(9*cos((225-v-90)*pi/180)),yc-(9*sin((225-v-90)*pi/180))));
        linearGrad.setColorAt(0, "#8F0909");
        linearGrad.setColorAt(0.5, "#F8F2F2");
        linearGrad.setColorAt(1, "#F93737");


   /*QRadialGradient radialGrad(QPointF(xc, yc), 200);
        radialGrad.setColorAt(0, "#F93737");
        //radialGrad.setColorAt(0.5, Qt::green);
        radialGrad.setColorAt(1, "#F1DFDF");
       // QRect rect_radial(300,50,200,200);
       // painter.fillRect(rect_radial, radialGrad);
    //QGradient grad;
    //grad.setSpread(QGradient::PadSpread);*/
    QBrush brush2(linearGrad);
   // QBrush brush2(radialGrad);

    //brush2.setStyle(Qt::SolidPattern);
    //brush2.setColor("#F93737");
    pen.setJoinStyle(Qt::RoundJoin);
    painter->setPen(pen);
    painter->setBrush(brush2);
    QPointF points[3] = {
          QPointF(xc-9*cos((225-v-90)*pi/180),yc+9*sin((225-v-90)*pi/180)),
          QPointF(xpos, ypos),
          QPointF(xc+9*cos((225-v-90)*pi/180),yc-9*sin((225-v-90)*pi/180))
           };

    painter->drawConvexPolygon(points, 3);
    }



    // draw blac circle int he middle
    {
    pen.setColor(Qt::black);
    brush.setColor(Qt::black);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(xc-15,yc-15,30,30);
    }

    // Block draw traites
    {   pen.setColor(Qt::black);
        //pen.setCapStyle(Qt::RoundCap);
        for (int i=0;i<=270;i+=10) {
        i%20==0 ? pen.setWidth(25) : pen.setWidth(20) ;
         //painter->drawLine(xc+qRound(150*cos((225-i)*pi/180)),yc-qRound(150*sin((225-i)*pi/180)),xc+qRound(170*cos((225-i)*pi/180)), yc-qRound(170*sin((225-i)*pi/180)));

            pen.setColor(Qt::black);
            pen.setCapStyle(Qt::FlatCap);
            pen.setStyle(Qt::SolidLine);

            painter->setPen(pen);
            painter->drawArc(40,40,320,320,(i-45)*16,20);

        if (i%20==0) painter->drawText(xc-10+130*cos((225-i)*pi/180),yc+5-130*sin((225-i)*pi/180),QString("%1").arg(i));

        }




    }








}
