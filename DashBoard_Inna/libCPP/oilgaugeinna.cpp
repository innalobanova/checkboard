#include "oilgaugeinna.h"
#include <QFont>
#include <QtMath>
#include <QPainter>

OilGaugeInna::OilGaugeInna(QGraphicsItem *parent) :  QGraphicsItem(parent)
{
    tmax = 160 ;
    lmax = 5;
    A0 = 180 ;
    Amax = 110 ;
    r = 100.0 ;
    dx = 10;
    dy = 9;

}

OilGaugeInna::OilGaugeInna(int TMAX, int LMAX, int ALPHA0, int ALPHAMAX)
{
    tmax = TMAX ;
    lmax = LMAX;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 100.0 ;
    dx = 10;
    dy = 9;

}

QRectF OilGaugeInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void OilGaugeInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{ painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
  painter->setBrush(QBrush("#0a0f0f",Qt::SolidPattern));
  painter->drawEllipse(QRectF(xc-r-20,yc-r-20,(r+20)*2,(r+20)*2));
  QRadialGradient radialGrad(QPointF(xc, yc), r+30);
  radialGrad.setColorAt(0, Qt::transparent);
  radialGrad.setColorAt(0.8, "#f2f2f2");
  radialGrad.setColorAt(0.9, "#333333");
  radialGrad.setColorAt(1, "#f2f2f2");
  painter->setPen(QPen(QBrush(radialGrad),4,Qt::SolidLine,Qt::FlatCap));
  painter->drawArc(QRectF(xc-r-20,yc-r-20,(r+20)*2,(r+20)*2),50*16,285*16) ;


    // *** draw OIL TEMP

    double xot = xc+30.0*cos((A0-15-Amax/2)*rad) ; //position of oil temperature arrow
    double yot = yc - 30.0*sin((A0-15-Amax/2)*rad);
    double  xol = xc +30.0*cos((A0+40+Amax/2)*rad) ;
    double yol = yc - 30.0*sin((A0+40+Amax/2)*rad);

    // ** Block oil temperature **

    {
      k = Amax * 1.0f / (tmax - 60.0f) ;

         // ** oil temp ticks and numbers **
    for (int i = 0; i <= (tmax - 60) ; i+=10) {
        if (i % 30 == 0)
            {
            painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap));
            painter->drawLine(xc+(r+15)*cos((A0-15-k*i)*rad),yc-(r+15)*sin((A0-15-k*i)*rad),xc+(r+3)*cos((A0-15-k*i)*rad),yc-(r+3)*sin((A0-15-k*i)*rad));
            painter->setFont(font);
            painter->setPen(QPen("#f5f5ef"));
            painter->drawText(xc-dx+(r-10)*cos((A0-15-k*i)*rad),yc+dy-(r-10)*sin((A0-15-k*i)*rad),QString("%1").arg(i+60));
            }
        else {
           painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
           painter->drawLine( xc+(r+15)*cos((A0-15-k*i)*rad),yc-(r+15)*sin((A0-15-k*i)*rad),xc+(r+8)*cos((A0-15-k*i)*rad),yc-(r+8)*sin((A0-15-k*i)*rad));

            }

        }

     }

    painter->drawPixmap(85,395,50,50, QPixmap(":/myicons/Oil_white.gif"));
    painter->drawPixmap(87,350,50,50, QPixmap(":/myicons/Oil_t_white.gif"));

    // ** Block oil level **
    k = Amax * 1.0f / lmax ;
    {
         // ** oil level ticks and numbers **
    for (int i=0; i <= lmax*2; i++) {
        if (i%2==0)
        {painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap));
        painter->drawLine(xc+(r+15)*cos((A0+40+k*i/2.0)*rad),yc-(r+15)*sin((A0+40+k*i/2.0)*rad),xc+(r+3)*cos((A0+40+k*i/2.0)*rad),yc-(r+3)*sin((A0+40+k*i/2.0)*rad));
        painter->setFont(font);
        painter->setPen(QPen("#f5f5ef"));
        painter->drawText(xc-dx+5+(r-10)*cos((A0+40+k*i/2.0)*rad),yc+dy-(r-10)*sin((A0+40+k*i/2.0)*rad),QString("%1").arg(i/2));
        }
        else {
           painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
           painter->drawLine( xc+(r+15)*cos((A0+40+k*i/2.0)*rad),yc-(r+15)*sin((A0+40+k*i/2.0)*rad),xc+(r+8)*cos((A0+40+k*i/2.0)*rad),yc-(r+8)*sin((A0+40+k*i/2.0)*rad));

        }

        }
    // ***Draw central circle for oil level ***
      QRadialGradient radialGradol(QPointF(xol, yol), 50);
             radialGradol.setColorAt(0, Qt::black);
             radialGradol.setColorAt(1, "#e0e0d1");
            // radialGradl2.setColorAt(1, Qt::black);
      painter->setPen(QPen(Qt::transparent));
      painter->setBrush(QBrush(radialGradol));
      painter->drawEllipse(xol-15,yol-15,30,30);

   //          *** draw fleche oil level ***

    k = (Amax+20) * 1.0f / lmax ;
      QLinearGradient linearGradol  (QPointF(xol-(5*cos((A0+30+k*l-90)*rad)),yol+(5*sin((A0+30+k*l-90)*rad))), QPointF(xol+(7*cos((A0+30+k*l-90)*rad)),yol-(7*sin((A0+30+k*l-90)*rad))));
          linearGradol.setColorAt(0, "#F93737");
          linearGradol.setColorAt(0.5, "#ff4d4d");
          linearGradol.setColorAt(1, "#F93737");

      painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
      painter->setBrush(QBrush(linearGradol));
      QPointF points[3] = {
          QPointF(xol-(5*cos((A0+30+k*l-90)*rad)),yol+(5*sin((A0+30+k*l-90)*rad))),
          QPointF(xol+(r-10)*cos((A0+30+k*l)*rad),yol-5-(r-10)*sin((A0+30+k*l)*rad)),
          QPointF(xol+(5*cos((A0+30+k*l-90)*rad)),yol-(5*sin((A0+30+k*l-90)*rad))),
         };

      painter->drawConvexPolygon(points, 3);
       }



}

