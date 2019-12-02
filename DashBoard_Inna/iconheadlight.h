#ifndef ICONHEADLIGHT_H
#define ICONHEADLIGHT_H
#include "libH/iconinna.h"
#include <QRectF>
#include <QFont>

class IconHeadlight : public IconInna
{
public:
    IconHeadlight(IconInna *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // ICONHEADLIGHT_H
