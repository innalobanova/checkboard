#ifndef OILGAUGEINNA_H
#define OILGAUGEINNA_H
#include <QGraphicsItem>
#include <QRectF>
#include <QFont>


class OilGaugeInna : public QGraphicsItem
{
public:
    OilGaugeInna();
    OilGaugeInna(int TMAX, float LMAX, int ALPHA0, int ALPHAMAX);
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

#endif // OILGAUGEINNA_H
