#include "clignotant.h"
#include "libH/iconinna.h"
#include <QPainter>
#include <QDebug>
#include <QTest>

Clignotant::Clignotant(IconInna *parent) : IconInna (parent)
{   visible = true;
    value = 1;
    cligno = 1;
    this->setZValue(5.0);
}

QRectF Clignotant::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void Clignotant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{  painter->setRenderHint(QPainter::Antialiasing);
 if (cligno == 1)
 {
    switch (value)
    {case -1:
        {painter->setOpacity(cligno);
        painter->drawPixmap(500,120,50,50, QPixmap(":/myicons/turnLeft.gif"));
        break;}
    case 1:
        {painter->setOpacity(cligno);
        painter->drawPixmap(840,120,50,50, QPixmap(":/myicons/turnRight.gif"));
        break;}

    case 2:
        {painter->setOpacity(cligno);
         painter->drawPixmap(500,120,50,50, QPixmap(":/myicons/turnLeft.gif"));
         painter->drawPixmap(840,120,50,50, QPixmap(":/myicons/turnRight.gif"));
         break;}
    default:
    {   painter->setPen(Qt::transparent);
        painter->setBrush(QBrush(Qt::transparent));
        painter->drawRect(500,120,50,50);
    }
    }
 MAJ();
 }
 else {   painter->setPen(Qt::transparent);
     painter->setBrush(QBrush(Qt::transparent));
     painter->drawRect(500,120,50,50);
        }
 MAJ();
 }


void Clignotant::MAJ()
{cligno = !cligno;
 QTest::qWait(1000);//
 update();

}
