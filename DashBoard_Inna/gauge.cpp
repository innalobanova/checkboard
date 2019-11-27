#include "gauge.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>

Gauge::Gauge()
{   vmax=270;
    startAngle=225*16;
    spanAngle= -qRound(vmax*vmax/270.0)*16;
    alpha=270;
    font ="Sans Serif";
    shift=0;


}

QRectF Gauge::boundingRect() const
{
    QRectF rectf(0.0,0.0,1400.0,600.0);


    return rectf;
}

void Gauge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{painter->setRenderHint(QPainter::Antialiasing);
    // *** background ***
    painter->setPen(QPen(QBrush(Qt::transparent,Qt::SolidPattern),3,Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QBrush("#0a0f0f",Qt::SolidPattern));
    painter->drawRect(this->boundingRect());

  //CENTER

{

  xc=0.5*this->boundingRect().width(); //center of the rectangle
  yc=0.5*this->boundingRect().height(); //center of the rectangle
  QRadialGradient radialGrad(QPointF(xc, yc), 170);
 radialGrad.setColorAt(0, Qt::transparent);
 radialGrad.setColorAt(150.0/170.0, "#595959");
 radialGrad.setColorAt(0.975, "#f2f2f2");
 radialGrad.setColorAt(0.98, "#333333");
 radialGrad.setColorAt(0.985, "#f2f2f2");
 radialGrad.setColorAt(1, "#f2f2f2");
 //QPen pen1(QPen(QBrush(radialGrad),20,Qt::SolidLine,Qt::FlatCap));
 painter->setPen(QPen(QBrush(radialGrad),4,Qt::SolidLine,Qt::FlatCap));
 painter->drawEllipse(qRound(xc-167.0),qRound(yc-167.0),334,334) ;
 painter->setPen(QPen(QBrush(radialGrad),20,Qt::SolidLine,Qt::FlatCap));
 painter->drawArc(qRound(xc-160),qRound(yc-160),320,320,startAngle,-270*16);

 // *** draw text ***
 for (int i=0; i<41; i++) {
 if (i%5==0)
     {i<34 ? painter->setPen(QPen(QBrush("#f2f2f2"),6,Qt::SolidLine,Qt::FlatCap)) : painter->setPen(QPen(QBrush("#e60000"),6,Qt::SolidLine,Qt::FlatCap));
     painter->drawLine( xc+167*cos((225-27*i/4.0)*pi/180),yc-167*sin((225-27*i/4.0)*pi/180),xc+140*cos((225-27*i/4.0)*pi/180),yc-140*sin((225-27*i/4.0)*pi/180));

     painter->setPen(QPen(QBrush(Qt::black),1,Qt::SolidLine,Qt::FlatCap));
     painter->drawLine( xc+167*cos((225-27*i/4.0)*pi/180),yc-167*sin((225-27*i/4.0)*pi/180),xc+141*cos((225-27*i/4.0)*pi/180),yc-141*sin((225-27*i/4.0)*pi/180));
     painter->setFont(QFont("Chandas",25,QFont::ExtraBold));
     painter->setPen(QPen("#f5f5ef"));
     painter->drawText(xc-12+118*cos((225-27*i/4.0)*pi/180),yc+18-118*sin((225-27*i/4.0)*pi/180),QString("%1").arg(i/5));
     }
 else {
     i<35 ? painter->setPen(QPen(QBrush("#f2f2f2"),3,Qt::SolidLine,Qt::FlatCap)) : painter->setPen(QPen(QBrush("#e60000"),3,Qt::SolidLine,Qt::FlatCap));
     painter->drawLine( xc+168*cos((225-27*i/4.0)*pi/180),yc-168*sin((225-27*i/4.0)*pi/180),xc+152*cos((225-27*i/4.0)*pi/180),yc-152*sin((225-27*i/4.0)*pi/180));
 }
}
// ***Draw central circle ***
 QRadialGradient radialGrad2(QPointF(xc, yc), 50);
        radialGrad.setColorAt(0, Qt::black);
        radialGrad.setColorAt(1, "#e0e0d1");
        //radialGrad.setColorAt(1, Qt::black);
 painter->setPen(QPen(Qt::transparent));
 painter->setBrush(QBrush(radialGrad2));
 painter->drawEllipse(xc-15,yc-15,30,30);

// *** draw fleche ***
// painter->setPen(QPen(QBrush("#d6d6c2",Qt::SolidPattern),4,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
// painter->drawLine(xc,yc, xc+150*cos((225-shift)*pi/180),yc-150*sin((225-shift)*pi/180));

 QLinearGradient linearGrad(QPointF(xc-(9*cos((225-shift-90)*pi/180)),yc+(9*sin((225-shift-90)*pi/180))), QPointF(xc+(9*cos((225-shift-90)*pi/180)),yc-(9*sin((225-shift-90)*pi/180))));
     linearGrad.setColorAt(0, "#F93737");
     linearGrad.setColorAt(0.5, "#ff3333");
     linearGrad.setColorAt(1, "#F93737");

 painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
 //painter->drawLine(xc,yc, xc+160*cos((225-shift)*pi/180),yc-160*sin((225-shift)*pi/180));
 painter->setBrush(QBrush(linearGrad));
 QPointF points[3] = {
       QPointF(xc-5*cos((225-shift-90)*pi/180),yc+5*sin((225-shift-90)*pi/180)),

       QPointF(xc+145*cos((225-shift)*pi/180),yc-145*sin((225-shift)*pi/180)),
       QPointF(xc+5*cos((225-shift-90)*pi/180),yc-5*sin((225-shift-90)*pi/180))
        };

 painter->drawConvexPolygon(points, 3);
}

  // LEFT

  {
   xl= 0.3*this->boundingRect().width(); //center of the rectangle
   yl= 0.55*this->boundingRect().height(); //center of the rectangle
   int d=150;
   painter->setBrush(QBrush(Qt::transparent));
   QRadialGradient radialGradl(QPointF(xl, yl), d+20);
   radialGradl.setColorAt(0, Qt::transparent);
   radialGradl.setColorAt(0.8, "#f2f2f2");
   radialGradl.setColorAt(0.9, "#333333");
   radialGradl.setColorAt(1, "#f2f2f2");
   painter->setPen(QPen(QBrush(radialGradl),4,Qt::SolidLine,Qt::FlatCap));
   painter->drawArc(QRectF(xl-d,yl-d,d*2,d*2),37*16,298*16);

   // *** draw text ***
   for (int i=0; i<301; i+=10) {
   if (i%50==0)
       {painter->setPen(QPen(QBrush("#f2f2f2"),6,Qt::SolidLine,Qt::FlatCap));
       painter->drawLine( xl+(d-5)*cos((225-3.*i/5.0)*pi/180),yl-(d-5)*sin((225-3*i/5.0)*pi/180),xl+(d-20)*cos((225-3*i/5.0)*pi/180),yl-(d-20)*sin((225-3*i/5.0)*pi/180));
       painter->setFont(QFont("Chandas",12,QFont::Bold));
       painter->setPen(QPen("#f5f5ef"));
       painter->drawText(xl-7+(d-35)*cos((225-3*i/5.0)*pi/180),yl+10-(d-35)*sin((225-3*i/5.0)*pi/180),QString("%1").arg(i));
       }
   else {
       painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
       painter->drawLine( xl+(d-5)*cos((225-3*i/5.0)*pi/180),yl-(d-5)*sin((225-3*i/5.0)*pi/180),xl+(d-15)*cos((225-3*i/5.0)*pi/180),yl-(d-15)*sin((225-3*i/5.0)*pi/180));
   }
  }
  // ***Draw central circle ***
   QRadialGradient radialGradl2(QPointF(xl, yl), 50);
       radialGradl2.setColorAt(0, Qt::black);
       radialGradl2.setColorAt(1, "#e0e0d1");
   painter->setPen(QPen(Qt::transparent));
   painter->setBrush(QBrush(radialGradl2));
   painter->drawEllipse(xl-15,yl-15,30,30);

   QLinearGradient linearGradl(QPointF(xl-(9*cos((225-shift-90)*pi/180)),yl+(9*sin((225-shift-90)*pi/180))), QPointF(xl+(9*cos((225-shift-90)*pi/180)),yl-(9*sin((225-shift-90)*pi/180))));
       linearGradl.setColorAt(0, "#F93737");
       linearGradl.setColorAt(0.5, "#ff3333");
       linearGradl.setColorAt(1, "#F93737");

   painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
   painter->setBrush(QBrush(linearGradl));
   QPointF points[3] = {
       QPointF(xl-5*cos((225-shift-90)*pi/180),yl+5*sin((225-shift-90)*pi/180)),
       QPointF(xl+(d-20)*cos((225-shift)*pi/180),yl-(d-20)*sin((225-shift)*pi/180)),
       QPointF(xl+5*cos((225-shift-90)*pi/180),yl-5*sin((225-shift-90)*pi/180))
        };
   painter->drawConvexPolygon(points, 3);
    }

  // THE OUTMOST LEFT

 { double xll=0.14*this->boundingRect().width();
   double yll=0.63*this->boundingRect().height();
   int r=120;

   painter->setBrush(QBrush(Qt::transparent));
   QRadialGradient radialGradll(QPointF(xll, yll), r+10);
   radialGradll.setColorAt(0, Qt::transparent);
   //radialGrad.setColorAt(0.88, "#f2f2f2");
   //radialGradl.setColorAt(140.0/d, "#595959");
   radialGradll.setColorAt(0.8, "#f2f2f2");
   radialGradll.setColorAt(0.9, "#333333");
   //radialGradl.setColorAt(149.0/d, "#f2f2f2");
   radialGradll.setColorAt(1, "#f2f2f2");
   //QPen pen1(QPen(QBrush(radialGrad),20,Qt::SolidLine,Qt::FlatCap));
   painter->setPen(QPen(QBrush(radialGradll),4,Qt::SolidLine,Qt::FlatCap));
   painter->drawArc(QRectF(xll-r,yll-r,r*2,r*2),50*16,285*16) ;


   // *** draw OIL TEMP

   double xot=xll-10.0; //position of oil temperature arrow
   double yot=yll-30.0;
   double xol=xot;
   double yol=yll+30.0;
   int rot=100;
   int rol=100;

   // ** Block oil temperature **

   {
       int A0=170;

        // ** oil temp ticks and numbers **
   for (int i=0; i<101; i+=10) {
       if (i%30==0)
       {painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap));
       painter->drawLine(xll+(r-5)*cos((A0-6*i/5.0)*pi/180),yll-(r-5)*sin((A0-6*i/5.0)*pi/180),xll+(r-17)*cos((A0-6*i/5.0)*pi/180),yll-(r-17)*sin((A0-6*i/5.0)*pi/180));
       painter->setFont(QFont("Chandas",12,QFont::Bold));
       painter->setPen(QPen("#f5f5ef"));
       painter->drawText(xll-10+(r-30)*cos((A0-6*i/5.0)*pi/180),yll+9-(r-30)*sin((A0-6*i/5.0)*pi/180),QString("%1").arg(i+60));
       }
       else {
          painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
          painter->drawLine( xll+(r-5)*cos((A0-6*i/5.0)*pi/180),yll-(r-5)*sin((A0-6*i/5.0)*pi/180),xll+(r-12)*cos((A0-6*i/5.0)*pi/180),yll-(r-12)*sin((A0-6*i/5.0)*pi/180));

       }

       }

 // ***Draw central circle for oil temp ***
   QRadialGradient radialGradot(QPointF(xot, yot), 50);
          radialGradot.setColorAt(0, Qt::black);
          radialGradot.setColorAt(1, "#e0e0d1");
         // radialGradl2.setColorAt(1, Qt::black);
   painter->setPen(QPen(Qt::transparent));
   painter->setBrush(QBrush(radialGradot));
   painter->drawEllipse(xot-15,yot-15,30,30);

//          *** draw fleche oil temp ***

   QLinearGradient linearGradot(QPointF(xot-(5*cos((A0-shift-90)*pi/180)),yot+(5*sin((A0-shift-90)*pi/180))), QPointF(xot+(7*cos((A0-shift-90)*pi/180)),yot-(7*sin((A0-shift-90)*pi/180))));
       linearGradot.setColorAt(0, "#F93737");
       linearGradot.setColorAt(0.5, "#ff4d4d");
       linearGradot.setColorAt(1, "#F93737");

   painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
   //painter->drawLine(xc,yc, xc+160*cos((225-shift)*pi/180),yc-160*sin((225-shift)*pi/180));
   painter->setBrush(QBrush(linearGradot));
   QPointF points[3] = {
       QPointF(xot-(5*cos((A0-shift-90)*pi/180)),yot+(5*sin((A0-shift-90)*pi/180))),
       QPointF(xot+(rot-15)*cos((A0-shift)*pi/180),yot-5-(rot-15)*sin((A0-shift)*pi/180)),
       QPointF(xot+(5*cos((A0-shift-90)*pi/180)),yot-(5*sin((A0-shift-90)*pi/180))),
      };

   painter->drawConvexPolygon(points, 3);
    }

   // ** Block oil level **

   { int A0=220;
     int k=11;
        // ** oil temp ticks and numbers **
   for (int i=0; i<11; i++) {
       if (i%2==0)
       {painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap));
       painter->drawLine(xll+(r-5)*cos((A0+k*i)*pi/180),yll-(r-5)*sin((A0+k*i)*pi/180),xll+(r-17)*cos((A0+k*i)*pi/180),yll-(r-17)*sin((A0+k*i)*pi/180));
       painter->setFont(QFont("Chandas",12,QFont::Bold));
       painter->setPen(QPen("#f5f5ef"));
       painter->drawText(xll-5+(r-30)*cos((220+k*i)*pi/180),yll+7-(r-30)*sin((220+k*i)*pi/180),QString("%1").arg(i/2));
       }
       else {
          painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
          painter->drawLine( xll+(r-5)*cos((A0+k*i)*pi/180),yll-(r-5)*sin((A0+k*i)*pi/180),xll+(r-12)*cos((A0+k*i)*pi/180),yll-(r-12)*sin((A0+k*i)*pi/180));

       }

       }
   // ***Draw central circle for oil temp ***
     QRadialGradient radialGradol(QPointF(xol, yol), 50);
            radialGradol.setColorAt(0, Qt::black);
            radialGradol.setColorAt(1, "#e0e0d1");
           // radialGradl2.setColorAt(1, Qt::black);
     painter->setPen(QPen(Qt::transparent));
     painter->setBrush(QBrush(radialGradol));
     painter->drawEllipse(xol-15,yol-15,30,30);

  //          *** draw fleche oil temp ***

     QLinearGradient linearGradol  (QPointF(xol-(5*cos((A0-shift-90)*pi/180)),yol+(5*sin((A0-shift-90)*pi/180))), QPointF(xol+(7*cos((A0-shift-90)*pi/180)),yol-(7*sin((A0-shift-90)*pi/180))));
         linearGradol.setColorAt(0, "#F93737");
         linearGradol.setColorAt(0.5, "#ff4d4d");
         linearGradol.setColorAt(1, "#F93737");

     painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
     //painter->drawLine(xc,yc, xc+160*cos((225-shift)*pi/180),yc-160*sin((225-shift)*pi/180));
     painter->setBrush(QBrush(linearGradol));
     QPointF points[3] = {
         QPointF(xol-(5*cos((A0+shift-90)*pi/180)),yol+(5*sin((A0+shift-90)*pi/180))),
         QPointF(xol+(rol-15)*cos((A0+shift)*pi/180),yol-5-(rol-15)*sin((A0+shift)*pi/180)),
         QPointF(xol+(5*cos((A0+shift-90)*pi/180)),yol-(5*sin((A0+shift-90)*pi/180))),
        };

     painter->drawConvexPolygon(points, 3);
      }

    }

  // RIGHT


    {
     double xr= 0.7*this->boundingRect().width(); //center of the rectangle
     double yr= 0.55*this->boundingRect().height(); //center of the rectangle
     int d=150;
     painter->setBrush(QBrush(Qt::transparent));
     QRadialGradient radialGradl(QPointF(xr, yr), d+20);
     radialGradl.setColorAt(0, Qt::transparent);
     radialGradl.setColorAt(0.8, "#f2f2f2");
     radialGradl.setColorAt(0.9, "#333333");
     radialGradl.setColorAt(1, "#f2f2f2");
     painter->setPen(QPen(QBrush(radialGradl),4,Qt::SolidLine,Qt::FlatCap));
     painter->drawArc(QRectF(xr-d,yr-d,d*2,d*2),205*16,298*16);

     }


  // THE OUTMOST RIGHT


    { double xrr=0.86*this->boundingRect().width();
      double yrr=0.63*this->boundingRect().height();
      int rr=120;

      painter->setBrush(QBrush(Qt::transparent));
      QRadialGradient radialGradrr(QPointF(xrr, yrr), rr+10);
      radialGradrr.setColorAt(0, Qt::transparent);
      radialGradrr.setColorAt(0.8, "#f2f2f2");
      radialGradrr.setColorAt(0.9, "#333333");
      radialGradrr.setColorAt(1, "#f2f2f2");
      painter->setPen(QPen(QBrush(radialGradrr),4,Qt::SolidLine,Qt::FlatCap));
      painter->drawArc(QRectF(xrr-rr,yrr-rr,rr*2,rr*2),206*16,285*16) ;


      // *** draw ENGINE TEMP and FUEL

      double xet=xrr-10.0; //position of engine temperature arrow
      double yet=yrr-30.0;
      double xf=xet;
      double yf=yrr+30.0;
      int rot=100;
      int rol=100;

      // ** Block engine temperature **

      {
          int A0=25;

           // ** engine temp ticks and numbers **
      for (int i=0; i<81; i+=10) {
          if (i%30==0)
          {
          i<60 ? painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap)) : painter->setPen(QPen(QBrush("#e60000"),6,Qt::SolidLine,Qt::FlatCap));
          painter->drawLine(xrr+(rr-5)*cos((A0+6*i/5.0)*pi/180),yrr-(rr-5)*sin((A0+6*i/5.0)*pi/180),xrr+(rr-17)*cos((A0+6*i/5.0)*pi/180),yrr-(rr-17)*sin((A0+6*i/5.0)*pi/180));
          painter->setFont(QFont("Chandas",12,QFont::Bold));
          painter->setPen(QPen("#f5f5ef"));
          painter->drawText(xrr-12+(rr-30)*cos((A0+6*i/5.0)*pi/180),yrr+9-(rr-30)*sin((A0+6*i/5.0)*pi/180),QString("%1").arg(i+60));
          }
          else {
             i<60 ? painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap)) : painter->setPen(QPen(QBrush("#e60000"),6,Qt::SolidLine,Qt::FlatCap));
             painter->drawLine( xrr+(rr-5)*cos((A0+6*i/5.0)*pi/180),yrr-(rr-5)*sin((A0+6*i/5.0)*pi/180),xrr+(rr-12)*cos((A0+6*i/5.0)*pi/180),yrr-(rr-12)*sin((A0+6*i/5.0)*pi/180));

          }

          }

    // ***Draw central circle for engine temp ***
      QRadialGradient radialGradet(QPointF(xet, yet), 50);
             radialGradet.setColorAt(0, Qt::black);
             radialGradet.setColorAt(1, "#e0e0d1");
            // radialGradl2.setColorAt(1, Qt::black);
      painter->setPen(QPen(Qt::transparent));
      painter->setBrush(QBrush(radialGradet));
      painter->drawEllipse(xet-15,yet-15,30,30);

   //          *** draw fleche engine temp ***

      QLinearGradient linearGradet(QPointF(xet-(5*cos((A0-shift-90)*pi/180)),yet+(5*sin((A0-shift-90)*pi/180))), QPointF(xet+(7*cos((A0-shift-90)*pi/180)),yet-(7*sin((A0-shift-90)*pi/180))));
          linearGradet.setColorAt(0, "#F93737");
          linearGradet.setColorAt(0.5, "#ff4d4d");
          linearGradet.setColorAt(1, "#F93737");

      painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
      //painter->drawLine(xc,yc, xc+160*cos((225-shift)*pi/180),yc-160*sin((225-shift)*pi/180));
      painter->setBrush(QBrush(linearGradet));
      QPointF points[3] = {
          QPointF(xet-(5*cos((A0-shift-90)*pi/180)),yet+(5*sin((A0-shift-90)*pi/180))),
          QPointF(xet+(rot-15)*cos((A0-shift)*pi/180),yet-5-(rot-15)*sin((A0-shift)*pi/180)),
          QPointF(xet+(5*cos((A0-shift-90)*pi/180)),yet-(5*sin((A0-shift-90)*pi/180))),
         };

      painter->drawConvexPolygon(points, 3);
       }

//      // ** Block fuel level **

      { int A0=220;
        int k=11;
           // ** oil temp ticks and numbers **
      for (int i=0; i<11; i++) {
          if (i%5==0)
          {painter->setPen(QPen(QBrush("#f2f2f2"),5,Qt::SolidLine,Qt::FlatCap));
          painter->drawLine(xrr+(rr-5)*cos((A0+k*i)*pi/180),yrr-(rr-5)*sin((A0+k*i)*pi/180),xrr+(rr-17)*cos((A0+k*i)*pi/180),yrr-(rr-17)*sin((A0+k*i)*pi/180));
          painter->setFont(QFont("Chandas",12,QFont::Bold));
          painter->setPen(QPen("#f5f5ef"));
          painter->drawText(xrr-5+(rr-30)*cos((220+k*i)*pi/180),yrr+7-(rr-30)*sin((220+k*i)*pi/180),QString("%1").arg(i*1./10));
          }
          else {
             painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
             painter->drawLine( xrr+(rr-5)*cos((A0+k*i)*pi/180),yrr-(rr-5)*sin((A0+k*i)*pi/180),xrr+(rr-12)*cos((A0+k*i)*pi/180),yrr-(rr-12)*sin((A0+k*i)*pi/180));

          }

          }
      // ***Draw central circle for oil temp ***
        QRadialGradient radialGradol(QPointF(xf, yf), 50);
               radialGradol.setColorAt(0, Qt::black);
               radialGradol.setColorAt(1, "#e0e0d1");
              // radialGradl2.setColorAt(1, Qt::black);
        painter->setPen(QPen(Qt::transparent));
        painter->setBrush(QBrush(radialGradol));
        painter->drawEllipse(xf-15,yf-15,30,30);

     //          *** draw fleche oil temp ***

        QLinearGradient linearGradol  (QPointF(xf-(5*cos((A0-shift-90)*pi/180)),yf+(5*sin((A0-shift-90)*pi/180))), QPointF(xf+(7*cos((A0-shift-90)*pi/180)),yf-(7*sin((A0-shift-90)*pi/180))));
            linearGradol.setColorAt(0, "#F93737");
            linearGradol.setColorAt(0.5, "#ff4d4d");
            linearGradol.setColorAt(1, "#F93737");

        painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
        //painter->drawLine(xc,yc, xc+160*cos((225-shift)*pi/180),yc-160*sin((225-shift)*pi/180));
        painter->setBrush(QBrush(linearGradol));
        QPointF points[3] = {
            QPointF(xf-(5*cos((A0+shift-90)*pi/180)),yf+(5*sin((A0+shift-90)*pi/180))),
            QPointF(xf+(rol-15)*cos((A0+shift)*pi/180),yf-5-(rol-15)*sin((A0+shift)*pi/180)),
            QPointF(xf+(5*cos((A0+shift-90)*pi/180)),yf-(5*sin((A0+shift-90)*pi/180))),
           };

        painter->drawConvexPolygon(points, 3);
         }

       }



}
