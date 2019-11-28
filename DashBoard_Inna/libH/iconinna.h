#ifndef ICONINNA_H
#define ICONINNA_H
#include <QGraphicsItem>
#include <QRectF>
#include <QFont>

class IconInna : public QGraphicsItem
{
public:
    IconInna (QGraphicsItem *parent = nullptr);
    IconInna (QPoint p, QSize s, QString pth);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QString imagePath;
    QPoint position;
    QSize size;
    void init(QPoint p, QSize s, QString pth);

};

#endif // ICONINNA_H
