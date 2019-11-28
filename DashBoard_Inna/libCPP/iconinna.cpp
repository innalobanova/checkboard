#include "libH/iconinna.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>

IconInna::IconInna(QGraphicsItem *parent) :  QGraphicsItem(parent)
{

}

IconInna::IconInna(QPoint p, QSize s, QString pth)
{
    position = p;
    size = s;
    imagePath = pth;
}

QRectF IconInna::boundingRect() const
{
    QRectF rectf(0.0,0.0,1400.0,600.0);
    return rectf;
}

void IconInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{ painter->setRenderHints(QPainter::Antialiasing);

  painter->drawPixmap(position.x(),position.y(),size.width(),size.height(),QPixmap(imagePath));

}

void IconInna::init(QPoint p, QSize s, QString pth)
{
    position = p;
    size = s;
    imagePath = pth;
}


