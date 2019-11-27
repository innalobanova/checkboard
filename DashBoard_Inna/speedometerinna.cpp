#include "speedometerinna.h"
#include <QFont>
#include <QtMath>
#include <QPainter>

SpeedometerInna::SpeedometerInna()
{
    vmax = 300 ;
    A0 = 225 ;
    Amax = 180 ;
    r = 150.0 ;
    dx = 7;
    dy = 10;
    k = Amax * 1.0f / vmax ;

}

SpeedometerInna::SpeedometerInna(int VMAX, int ALPHA0, int ALPHAMAX)
{
    vmax = VMAX ;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 150.0 ;
    dx = 7;
    dy = 10;
    k = Amax * 1.0f / vmax ;



}

QRectF SpeedometerInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void SpeedometerInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{ painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
     QRadialGradient radialGrad(QPointF(xc, yc), r+20); //setting the gradient to draw the outer arc
     radialGrad.setColorAt(0, Qt::transparent);
     radialGrad.setColorAt(0.8, "#f2f2f2");
     radialGrad.setColorAt(0.9, "#333333");
     radialGrad.setColorAt(1, "#f2f2f2");
     painter->setPen(QPen(QBrush(radialGrad),4,Qt::SolidLine,Qt::FlatCap)); // setting the brush with a gradient
     painter->setBrush(QBrush(Qt::transparent)); // to have a transparent background
     painter->drawArc(QRectF(xc-r,yc-r,r*2,r*2),37*16,298*16); // coordinates for the arc

     // *** draw text and ticks***
     k = Amax * 1.0f / vmax ;
     for (int i = 0; i <= vmax ; i += 10) {
     if (i % 50 == 0)
         {
         painter->setPen(QPen(QBrush("#f2f2f2"),6,Qt::SolidLine,Qt::FlatCap));
         painter->drawLine( qRound(xc+(r-5)*cos((A0-k*i)*rad)),qRound(yc-(r-5)*sin((A0-k*i)*rad)),qRound(xc+(r-20)*cos((A0-k*i)*rad)),qRound(yc-(r-20)*sin((A0-k*i)*rad)));
         painter->setFont(QFont("Chandas",12,QFont::Bold));
         painter->setPen(QPen("#f5f5ef"));
         painter->drawText(xc-dx+(r-35)*cos((A0-k*i)*rad),yc+10-(r-35)*sin((A0-k*i)*rad),QString("%1").arg(i));
         }
     else {
         painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
         painter->drawLine(xc+(r-5)*cos((A0-k*i)*rad), yc-(r-5)*sin((A0-k*i)*rad),xc+(r-15)*cos((A0-k*i)*rad),yc-(r-15)*sin((A0-k*i)*rad));
     }
    }
    // ***Draw central circle ***
     QRadialGradient radialGrad2(QPointF(xc, yc), 50);
         radialGrad2.setColorAt(0, Qt::black);
         radialGrad2.setColorAt(1, "#e0e0d1");
     painter->setPen(QPen(Qt::transparent));
     painter->setBrush(QBrush(radialGrad2));
     painter->drawEllipse(xc-15,yc-15,30,30);

       v *= k; // correction of the speed to angle

     QLinearGradient linearGradl(QPointF(xc-(9*cos((A0-v-90)*rad)),yc+(9*sin((A0-v-90)*rad))), QPointF(xc+(9*cos((A0-v-90)*rad)),yc-(9*sin((A0-v-90)*rad))));
         linearGradl.setColorAt(0, "#F93737");
         linearGradl.setColorAt(0.5, "#ff3333");
         linearGradl.setColorAt(1, "#F93737");

     painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
     painter->setBrush(QBrush(linearGradl));
     QPointF points[3] = {
         QPointF(xc-5*cos((A0-v-90)*rad),yc+5*sin((A0-v-90)*rad)),
         QPointF(xc+(r-20)*cos((A0-v)*rad),yc-(r-20)*sin((A0-v)*rad)),
         QPointF(xc+5*cos((A0-v-90)*rad),yc-5*sin((A0-v-90)*rad))
          };
     painter->drawConvexPolygon(points, 3);


}
