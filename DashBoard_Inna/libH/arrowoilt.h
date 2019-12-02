#ifndef ARROWOILT_H
#define ARROWOILT_H
#include <QGraphicsItem>
#include <QRectF>
#include <QFont>
#include "objet_virtuel.h"


class ArrowOilT : public objet_virtuel
{
public:
    ArrowOilT(objet_virtuel *parent = nullptr);
    ArrowOilT(int TMAX, int LMAX, int ALPHA0, int ALPHAMAX);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double r;
    int A0 ; //start Angle
    int Amax ; // max Angle
    int tmax ; // maximum oil temperature
    int t ; // current oil temperature
    int lmax ; // maximum oil level
    float l ; // current oil level
    QFont font = QFont("Chandas",12,QFont::Bold); // font parameters par default
    float k ; // coefficient to calculate current angle
    int dx; //text shift
    int dy;
private:
    const double rad=3.14159265359/180;
    double xc = 0.14 * this->boundingRect().width() ; //center of the rectangle
    double yc = 0.63 * this->boundingRect().height() ;

};

#endif // ARROWOILT_H
