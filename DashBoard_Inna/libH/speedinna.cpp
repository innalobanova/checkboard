#include "libH/speedinna.h"
#include "libH/iconinna.h"
#include <QPainter>

speedInna::speedInna(IconInna *parent) : IconInna (parent)
{
    value = 0;
}

QRectF speedInna::boundingRect() const
{
   return QRectF (0.0,0.0,1400.0,600.0);
}

void speedInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{  painter->setRenderHints(QPainter::Antialiasing);
    position=QPoint(610,400);
   size = QSize (120,42);
   painter->setPen(QPen("#19b5e4"));
   painter->setFont(QFont("Chandas", 12, 0));
   painter->drawText(740,435, "km/h");
   painter->setFont(QFont("SevenSegment", 35, 0));

   QRadialGradient rg(670, 421, 60);
   rg.setColorAt(0, "#4c5959");
   rg.setColorAt(1,Qt::black);
   painter->setBrush(rg);
   painter->drawText(QRect(position,size), Qt::AlignRight, QString("%1").arg(value));


}

