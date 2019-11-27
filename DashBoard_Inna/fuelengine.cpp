#include "fuelengine.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>


FuelEngine::FuelEngine(QGraphicsItem *parent) :  QGraphicsItem(parent)

{
    tmax = 140 ;
    A0 = 0 ;
    Amax = 110 ;
    r = 100.0 ;
    dx = 10;
    dy = 9;
}

FuelEngine::FuelEngine(int TMAX, int ALPHA0, int ALPHAMAX)
{
    tmax = TMAX ;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 100.0 ;
    dx = 10;
    dy = 9;
}

QRectF FuelEngine::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void FuelEngine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
    painter->setBrush(QBrush("#0a0f0f",Qt::SolidPattern));
    painter->drawEllipse(QRectF(xc-r-20,yc-r-20,(r+20)*2,(r+20)*2));
      QRadialGradient radialGrad(QPointF(xc, yc), r+30);
      radialGrad.setColorAt(0, Qt::transparent);
      radialGrad.setColorAt(0.8, "#f2f2f2");
      radialGrad.setColorAt(0.9, "#333333");
      radialGrad.setColorAt(1, "#f2f2f2");
      painter->setPen(QPen(QBrush(radialGrad),4,Qt::SolidLine,Qt::FlatCap));
      painter->drawArc(QRectF(xc-r-20,yc-r-20,(r+20)*2,(r+20)*2),206*16,285*16) ;
      double xet=xc+20.0*cos((A0+20+Amax/2)*rad); //position of engine temperature arrow
      double yet=yc-20.0*sin((A0+20+Amax/2)*rad);

      double xf=xc + 30.0*cos((A0+220+Amax/2)*rad);
;
      double yf=yc-30.0*sin((A0+220+Amax/2)*rad);

      k = Amax * 1.0f / (tmax - 60.0f) ;
      for (int i = 0; i <= (tmax - 60) ; i+=10) {
          if (i % 30 == 0)
              {
              i<60 ? painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap)) : painter->setPen(QPen(QBrush("#e60000"),6,Qt::SolidLine,Qt::FlatCap));

              painter->drawLine(xc+(r+15)*cos((A0+20+k*i)*rad),yc-(r+15)*sin((A0+20+k*i)*rad),xc+(r+3)*cos((A0+20+k*i)*rad),yc-(r+3)*sin((A0+20+k*i)*rad));
              painter->setFont(font);
              painter->setPen(QPen("#f5f5ef"));
              painter->drawText(xc-dx+(r-10)*cos((A0+20+k*i)*rad),yc+dy-(r-10)*sin((A0+20+k*i)*rad),QString("%1").arg(i+60));
              }
          else {
              i<60 ? painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap)) : painter->setPen(QPen(QBrush("#e60000"),6,Qt::SolidLine,Qt::FlatCap));

             painter->drawLine( xc+(r+15)*cos((A0+20+k*i)*rad),yc-(r+15)*sin((A0+20+k*i)*rad),xc+(r+8)*cos((A0+20+k*i)*rad),yc-(r+8)*sin((A0+20+k*i)*rad));

              }

          }

      // ***Draw central circle for engine temp ***

      QRadialGradient radialGradet(QPointF(xet, yet), 50);
      radialGradet.setColorAt(0, Qt::black);
      radialGradet.setColorAt(1, "#e0e0d1");
      painter->setPen(QPen(Qt::transparent));
      painter->setBrush(QBrush(radialGradet));
      painter->drawEllipse(xet-15,yet-15,30,30);

      //          *** draw fleche engine temp ***

      k = (Amax+30) * 1.0f / (tmax-60) ;
      QLinearGradient linearGradot(QPointF(xet-(5*cos((A0+5+k*(t-60)-90)*rad)),yet+(5*sin((A0+5+k*(t-60)-90)*rad))), QPointF(xet+(7*cos((A0+5+k*(t-60)-90)*rad)),yet-(7*sin((A0+5+k*(t-60)-90)*rad))));
      linearGradot.setColorAt(0, "#F93737");
      linearGradot.setColorAt(0.5, "#ff4d4d");
      linearGradot.setColorAt(1, "#F93737");

      painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
      painter->setBrush(QBrush(linearGradot));
      QPointF points[3] = {
          QPointF(xet-(5*cos((A0+5+k*(t-60)-90)*rad)),yet+(5*sin((A0+5+k*(t-60)-90)*rad))),
          QPointF(xet+(r-15)*cos((A0+5+k*(t-60))*rad),yet-5-(r-15)*sin((A0+5+k*(t-60))*rad)),
          QPointF(xet+(5*cos((A0+5+k*(t-60)-90)*rad)),yet-(5*sin((A0+5+k*(t-60)-90)*rad))),
         };

      painter->drawConvexPolygon(points, 3);

      // ** fuel level ticks and numbers **
       k = Amax * 1.0f;
      for (int i=0; i <= 10 ; i++) {
          if (i%5==0)
          {painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap));
          painter->drawLine(xc+(r+15)*cos((A0+220+k*i/10.0)*rad),yc-(r+15)*sin((A0+220+k*i/10.0)*rad),xc+(r+3)*cos((A0+220+k*i/10.0)*rad),yc-(r+3)*sin((A0+220+k*i/10.0)*rad));
          painter->setFont(QFont("Chandas",12,QFont::Bold));
          painter->setPen(QPen("#f5f5ef"));
          painter->drawText(xc-5+(r-10)*cos((220+k*i/10.0)*rad),yc+7-(r-10)*sin((220+k*i/10.0)*rad),QString("%1").arg(i*1./10));
          }
          else {
             painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
             painter->drawLine( xc+(r+15)*cos((A0+220+k*i/10.0)*rad),yc-(r+15)*sin((A0+220+k*i/10.0)*rad),xc+(r+8)*cos((A0+220+k*i/10.0)*rad),yc-(r+8)*sin((A0+220+k*i/10.0)*rad));

}
}

      // ***Draw central circle for fuel level ***
        QRadialGradient radialGradol(QPointF(xf, yf), 50);
        radialGradol.setColorAt(0, Qt::black);
        radialGradol.setColorAt(1, "#e0e0d1");
        painter->setPen(QPen(Qt::transparent));
        painter->setBrush(QBrush(radialGradol));
        painter->drawEllipse(xf-15,yf-15,30,30);

     //          *** draw fleche fuel level***
        k = (Amax+20) * 1.0f;
        QLinearGradient linearGradol  (QPointF(xf-(5*cos((A0+210+k*l-90)*rad)),yf+(5*sin((A0+210+k*l-90)*rad))), QPointF(xf+(7*cos((A0+210+k*l-90)*rad)),yf-(7*sin((A0+210+k*l-90)*rad))));
            linearGradol.setColorAt(0, "#F93737");
            linearGradol.setColorAt(0.5, "#ff4d4d");
            linearGradol.setColorAt(1, "#F93737");

        painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
        //painter->drawLine(xc,yc, xc+160*cos((225-shift)*rad),yc-160*sin((225-shift)*rad));
        painter->setBrush(QBrush(linearGradol));
        QPointF pointsF[3] = {
            QPointF(xf-(5*cos((A0+210+k*l-90)*rad)),yf+(5*sin((A0+210+k*l-90)*rad))),
            QPointF(xf+(r-15)*cos((A0+210+k*l)*rad),yf-5-(r-15)*sin((A0+210+k*l)*rad)),
            QPointF(xf+(5*cos((A0+210+k*l-90)*rad)),yf-(5*sin((A0+210+k*l-90)*rad))),
           };

        painter->drawConvexPolygon(pointsF, 3);


}
