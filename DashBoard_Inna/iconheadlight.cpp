#include "iconheadlight.h"
#include "libH/iconinna.h"
#include <QPainter>
#include "objet_virtuel.h"




IconHeadlight::IconHeadlight(IconInna *parent) : IconInna (parent)
{
    value = 1;
    this->setZValue(5.0);
}


QRectF IconHeadlight::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void IconHeadlight::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch (value)
    {case 1:
        {painter->drawPixmap(480,320,50,50, QPixmap(":/myicons/dayLight.gif"));
        break;}
    case 2:
        {painter->drawPixmap(480,320,50,50, QPixmap(":/myicons/lowBeam.gif"));
        break;}

    case 3:
        {painter->drawPixmap(480,320,50,50, QPixmap(":/myicons/highBeam.gif"));
        break;}
    default:
    {   painter->setPen(Qt::transparent);
        painter->setBrush(QBrush(Qt::transparent));
        painter->drawRect(480,320,40,40);
    }



        }







}
