#ifndef ENGINETINNA_H
#define ENGINETINNA_H
#include <QGraphicsItem>
#include <QRectF>
#include <QFont>

class EngineTInna : public QGraphicsItem
{
public:
    EngineTInna(QGraphicsItem *parent = nullptr);
    EngineTInna(int TMAX, int ALPHA0, int ALPHAMAX);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double r;
    int A0 ; //start Angle
    int Amax ; // max Angle
    int tmax ; // maximum engine temperature
    int t ; // current engine temperature
    float k ; // coefficient to calculate current angle

private:
    const double rad=3.14159265359/180;
    
    double xc = 0.86 * this->boundingRect().width() ; //center of the rectangle
    double yc = 0.63 * this->boundingRect().height() ;

};

#endif // ENGINETINNA_H
