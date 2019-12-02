#include "tachometerinna.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>

TachometerInna::TachometerInna()
{
    
    vmax = 8*1000 ;
    A0 = 225 ;
    Amax = 270 ;
    r = 170.0 ;
    dx = 10;
    dy = 12;
    k = Amax * 1.0f / vmax ;  
}

TachometerInna::TachometerInna(int VMAX, int ALPHA0, int ALPHAMAX)
{
    vmax = VMAX*1000 ;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 170.0 ;
    dx = 10;
    dy = 12;
    k = Amax * 1.0f / vmax ;
    
}

QRectF TachometerInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf; 
}

void TachometerInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
   QRadialGradient radialGrad(QPointF(xc, yc), r);
   radialGrad.setColorAt(0, Qt::transparent);
   radialGrad.setColorAt(150.0/r, "#595959");
   radialGrad.setColorAt(0.975, "#f2f2f2");
   radialGrad.setColorAt(0.98, "#333333");
   radialGrad.setColorAt(0.985, "#f2f2f2");
   radialGrad.setColorAt(1, "#f2f2f2");
   painter->setPen(QPen(QBrush(radialGrad),4,Qt::SolidLine,Qt::FlatCap));
   painter->drawEllipse(qRound(xc-r+2),qRound(yc-r+2),2*(r-2),2*(r-2)) ;
   painter->setPen(QPen(QBrush(radialGrad),20,Qt::SolidLine,Qt::FlatCap));
   painter->drawArc(qRound(xc-r+10),qRound(yc-r+10),2*(r-10),2*(r-10),A0*16,-Amax*16);

   // *** draw text ***
   k = Amax * 1.0f / vmax ;
   for (int i = 0; i <= vmax; i += 200) {
   if (i%1000==0)
       {i<7000 ? painter->setPen(QPen(QBrush("#f2f2f2"),6,Qt::SolidLine,Qt::FlatCap)) : painter->setPen(QPen(QBrush("#e60000"),6,Qt::SolidLine,Qt::FlatCap));
       painter->drawLine( xc+(r-3)*cos((A0-k*i)*rad), yc-(r-3)*sin((A0-k*i)*rad), xc+(r-30)*cos((A0-k*i)*rad),yc-(r-30)*sin((A0-k*i)*rad));

       painter->setPen(QPen(QBrush(Qt::black),1,Qt::SolidLine,Qt::FlatCap));
       painter->drawLine( xc+(r-3)*cos((A0-k*i)*rad),yc-(r-3)*sin((A0-k*i)*rad),xc+(r-29)*cos((A0-k*i)*rad),yc-(r-29)*sin((A0-k*i)*rad));
       painter->setFont(font);
       painter->setPen(QPen("#f5f5ef"));
       painter->drawText(xc-dx+(r-52)*cos((A0-k*i)*rad),yc+dy-(r-52)*sin((A0-k*i)*rad),QString("%1").arg(i/1000));
       }
   else {
       i<7000 ? painter->setPen(QPen(QBrush("#f2f2f2"),3,Qt::SolidLine,Qt::FlatCap)) : painter->setPen(QPen(QBrush("#e60000"),3,Qt::SolidLine,Qt::FlatCap));
       painter->drawLine( xc+(r-2)*cos((A0-k*i)*rad),yc-(r-2)*sin((A0-k*i)*rad),xc+(r-18)*cos((A0-k*i)*rad),yc-(r-18)*sin((A0-k*i)*rad));
   }
  }
  // ***Draw central circle ***
   QRadialGradient radialGrad2(QPointF(xc, yc), 50);
   radialGrad.setColorAt(0, Qt::black);
   radialGrad.setColorAt(1, "#e0e0d1");
   painter->setPen(QPen(Qt::transparent));
   painter->setBrush(QBrush(radialGrad2));
   painter->drawEllipse(xc-15,yc-15,30,30);

  // *** draw fleche ***
  QLinearGradient linearGrad(QPointF(xc-(5*cos((A0-k*v-90)*rad)),yc+(5*sin((A0-k*v-90)*rad))), QPointF(xc+(5*cos((A0-k*v-90)*rad)),yc-(5*sin((A0-k*v-90)*rad))));
   linearGrad.setColorAt(0, "#F93737");
   linearGrad.setColorAt(0.5, "#ff3333");
   linearGrad.setColorAt(1, "#F93737");
   painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
   painter->setBrush(QBrush(linearGrad));
   QPointF points[3] = {
         QPointF(xc-5*cos((A0-k*v-90)*rad),yc+5*sin((A0-k*v-90)*rad)),

         QPointF(xc+(r-25)*cos((A0-k*v)*rad),yc-(r-25)*sin((A0-k*v)*rad)),
         QPointF(xc+5*cos((A0-k*v-90)*rad),yc-5*sin((A0-k*v-90)*rad))
          };

   painter->drawConvexPolygon(points, 3);

}

