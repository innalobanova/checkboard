#ifndef FONDINNA_H
#define FONDINNA_H
#include <QGraphicsItem>

class fondInna : public QGraphicsItem
{
public:
    fondInna(QGraphicsItem *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // FONDINNA_H
