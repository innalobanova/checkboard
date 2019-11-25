#include "gauge.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>

Gauge::Gauge()
{   vmax=270;
    startAngle=225*16;
    spanAngle= -qRound(vmax*vmax/270.0)*16;
    alpha=270;
    font ="Sans Serif";
    shift=10;

}

QRectF Gauge::boundingRect() const
{
    QRectF rectf(0,0,400,400);


    return rectf;
}

void Gauge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{painter->setRenderHint(QPainter::Antialiasing);
 // *** background ***
 painter->setPen(QPen(QBrush(Qt::transparent,Qt::SolidPattern),3,Qt::SolidLine,Qt::FlatCap));
 painter->setBrush(QBrush("#0a0f0f",Qt::SolidPattern));
 painter->drawRect(this->boundingRect());
  xc=0.5*this->boundingRect().width(); //center of the rectangle
  yc=0.5*this->boundingRect().height(); //center of the rectangle
  QRadialGradient radialGrad(QPointF(xc, yc), 170);
 radialGrad.setColorAt(0, Qt::transparent);
 //radialGrad.setColorAt(0.88, "#f2f2f2");
 radialGrad.setColorAt(150.0/170.0, "#595959");
 radialGrad.setColorAt(0.975, "#f2f2f2");
 radialGrad.setColorAt(0.98, "#333333");
 radialGrad.setColorAt(0.985, "#f2f2f2");
 radialGrad.setColorAt(1, "#f2f2f2");
 //QPen pen1(QPen(QBrush(radialGrad),20,Qt::SolidLine,Qt::FlatCap));
 painter->setPen(QPen(QBrush(radialGrad),4,Qt::SolidLine,Qt::FlatCap));
 painter->drawEllipse(33,33,334,334) ;
 painter->setPen(QPen(QBrush(radialGrad),20,Qt::SolidLine,Qt::FlatCap));
 painter->drawArc(40,40,320,320,startAngle,-270*16);

 // *** draw text ***
 for (int i=0; i<41; i++) {
 if (i%5==0)
     {i<34 ? painter->setPen(QPen(QBrush("#f2f2f2"),6,Qt::SolidLine,Qt::FlatCap)) : painter->setPen(QPen(QBrush("#e60000"),6,Qt::SolidLine,Qt::FlatCap));
     painter->drawLine( xc+167*cos((225-27*i/4.0)*pi/180),yc-167*sin((225-27*i/4.0)*pi/180),xc+140*cos((225-27*i/4.0)*pi/180),yc-140*sin((225-27*i/4.0)*pi/180));

     painter->setPen(QPen(QBrush(Qt::black),1,Qt::SolidLine,Qt::FlatCap));
     painter->drawLine( xc+167*cos((225-27*i/4.0)*pi/180),yc-167*sin((225-27*i/4.0)*pi/180),xc+141*cos((225-27*i/4.0)*pi/180),yc-141*sin((225-27*i/4.0)*pi/180));
     painter->setFont(QFont("Chandas",25,QFont::ExtraBold));
     painter->setPen(QPen("#f5f5ef"));
     painter->drawText(xc-12+118*cos((225-27*i/4.0)*pi/180),yc+18-118*sin((225-27*i/4.0)*pi/180),QString("%1").arg(i/5));
     }
 else {
     i<35 ? painter->setPen(QPen(QBrush("#f2f2f2"),3,Qt::SolidLine,Qt::FlatCap)) : painter->setPen(QPen(QBrush("#e60000"),3,Qt::SolidLine,Qt::FlatCap));
     painter->drawLine( xc+168*cos((225-27*i/4.0)*pi/180),yc-168*sin((225-27*i/4.0)*pi/180),xc+152*cos((225-27*i/4.0)*pi/180),yc-152*sin((225-27*i/4.0)*pi/180));
 }
}
// ***Draw central circle ***
 QRadialGradient radialGrad2(QPointF(xc, yc), 50);
        radialGrad.setColorAt(0, Qt::black);
        radialGrad.setColorAt(0.3, "#e0e0d1");
        radialGrad.setColorAt(1, Qt::black);
 painter->setPen(QPen(Qt::transparent));
 painter->setBrush(QBrush(radialGrad2));
 painter->drawEllipse(xc-15,yc-15,30,30);

// *** draw fleche ***
 painter->setPen(QPen(QBrush("#d6d6c2",Qt::SolidPattern),4,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
 painter->drawLine(xc,yc, xc+150*cos((225-shift)*pi/180),yc-150*sin((225-shift)*pi/180));

 QLinearGradient linearGrad(QPointF(xc-(9*cos((225-shift-90)*pi/180)),yc+(9*sin((225-shift-90)*pi/180))), QPointF(xc+(9*cos((225-shift-90)*pi/180)),yc-(9*sin((225-shift-90)*pi/180))));
     linearGrad.setColorAt(0, "##F93737");
     linearGrad.setColorAt(0.5, "#ff3333");
     linearGrad.setColorAt(1, "#F93737");

 painter->setPen(QPen(QBrush("#310B0B",Qt::Dense4Pattern),1,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
 //painter->drawLine(xc,yc, xc+160*cos((225-shift)*pi/180),yc-160*sin((225-shift)*pi/180));
 painter->setBrush(QBrush(linearGrad));
 QPointF points[3] = {
       QPointF(xc-5*cos((225-shift-90)*pi/180),yc+5*sin((225-shift-90)*pi/180)),

       QPointF(xc+145*cos((225-shift)*pi/180),yc-145*sin((225-shift)*pi/180)),
       QPointF(xc+5*cos((225-shift-90)*pi/180),yc-5*sin((225-shift-90)*pi/180))
        };

 painter->drawConvexPolygon(points, 3);




}
