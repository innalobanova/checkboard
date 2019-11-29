#ifndef SPEEDINNA_H
#define SPEEDINNA_H
#include "libH/iconinna.h"
#include <QRectF>
#include <QFont>

class speedInna : public IconInna
{
public:
    speedInna(IconInna *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SPEEDINNA_H
