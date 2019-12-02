#include "libH/fuellevelinna.h"
#include "objet_virtuel.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>


FuelLevelInna::FuelLevelInna(objet_virtuel *parent) :  objet_virtuel(parent)

{   value = 0;
    A0 = 0 ;
    Amax = 110 ;
    r = 100.0 ;

}

FuelLevelInna::FuelLevelInna(int ALPHA0, int ALPHAMAX)
{
    value = 0;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 100.0 ;

}

QRectF FuelLevelInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void FuelLevelInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
    double xf=xc + 30.0*cos((A0+220+Amax/2)*rad);
    double yf=yc-30.0*sin((A0+220+Amax/2)*rad);
      // ***Draw central circle for fuel level ***
        QRadialGradient radialGradol(QPointF(xf, yf), 50);
        radialGradol.setColorAt(0, Qt::black);
        radialGradol.setColorAt(1, "#e0e0d1");
        painter->setPen(QPen(Qt::transparent));
        painter->setBrush(QBrush(radialGradol));
        painter->drawEllipse(xf-15,yf-15,30,30);

     //          *** draw fleche fuel level***
    l = value *0.01f;

	if (l < 0.0f || l > 1.0f) l = (l < 0.0f ? 0.0f : 1.0f);

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

        if (l >= 0 && l <=0.2)
                painter->drawPixmap(1270,370,50,50, QPixmap(":/myicons/fuelL_red.gif"));
        else
                painter->drawPixmap(1270,370,50,50, QPixmap(":/myicons/fuelL_white.gif"));



}
