#ifndef CLIGNOTANT_H
#define CLIGNOTANT_H
#include "libH/iconinna.h"
#include <QRectF>
#include <QFont>


class Clignotant : public IconInna
{
public:
    Clignotant(IconInna *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int cligno;
    bool visible;
    void MAJ();

};

#endif // CLIGNOTANT_H
