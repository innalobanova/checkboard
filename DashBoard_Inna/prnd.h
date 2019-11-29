#ifndef PRND_H
#define PRND_H
#include "libH/iconinna.h"
#include <QRectF>
#include <QFont>

class PRND : public IconInna
{
public:
    PRND(IconInna *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PRND_H
