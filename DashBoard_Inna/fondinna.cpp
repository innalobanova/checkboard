#include "fondinna.h"
#include <QPainter>

fondInna::fondInna(QGraphicsItem *parent):QGraphicsItem (parent)
{

}

QRectF fondInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void fondInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}
