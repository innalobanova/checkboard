#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTcpServer>
#include "libH/speedometerinna.h"
#include "libH/arrowspeedometerinna.h"
#include "libH/tachometerinna.h"
#include "libH/arrowtachometerinna.h"
#include "libH/oilgaugeinna.h"
#include "libH/arrowoilt.h"
#include "libH/infowindowinna.h"
#include "libH/fuelengine.h"
#include "libH/iconinna.h"
#include "libH/arrowoill.h"
#include "libH/fuellevelinna.h"
#include "libH/enginetinna.h"
#include "prnd.h"
#include "libH/speedinna.h"
#include "icononoff.h"
#include "iconheadlight.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    SpeedometerInna *speedometer = new SpeedometerInna();
    ArrowSpeedometerInna *arrow_speedometer = new ArrowSpeedometerInna();
    TachometerInna *tachometer = new TachometerInna();
    ArrowTachometerInna *arrow_tachometer = new ArrowTachometerInna();
    OilGaugeInna *oilgauge = new OilGaugeInna();
    ArrowOilT *arrow_oilT = new ArrowOilT ();
    ArrowOilL *arrow_oilL = new ArrowOilL ();
    QGraphicsScene *scene = new QGraphicsScene ();
    InfoWindowInna *info = new InfoWindowInna ();
    FuelEngine *fuel_engine = new FuelEngine ();
    FuelLevelInna *fuel_level = new FuelLevelInna ();
    EngineTInna *engineT = new EngineTInna ();
    PRND *drive_mode = new PRND();
    speedInna *speed = new speedInna();
    IconHeadlight *headlights = new IconHeadlight ();
    IconInna *myicon = new IconInna;
    IconInna *door1 = new IconInna ();
    IconInna *door2 = new IconInna ();
    iconOnOff *VoyantBatterie = new iconOnOff(QPoint(900,420),QSize(40,40),":/myicons/battery.gif",5.0);
    iconOnOff *CheckEngine = new iconOnOff(QPoint(950,420),QSize(40,40),":/myicons/checkEngine.gif",5.0);
    iconOnOff *RearFogLight = new iconOnOff(QPoint(460,360),QSize(50,50),":/myicons/rearFogLight.gif",5.0);
    iconOnOff *FrontFogLight = new iconOnOff(QPoint(495,360),QSize(50,50),":/myicons/frontFogLight.gif",5.0);
    iconOnOff *RearWindowHeating = new iconOnOff(QPoint(470,400),QSize(50,50),":/myicons/rearWindowHeating_yellow.gif",5.0);
    iconOnOff *SeatBealt = new iconOnOff(QPoint(900,220),QSize(50,50),":/myicons/seatBeltSign_red.gif",5.0);
    iconOnOff *AdaptiveCruiseControl= new iconOnOff(QPoint(390,230),QSize(60,60),":/myicons/adaptiveCruiseControl_green.gif",5.0);
    iconOnOff * AdaptiveSuspensionDampers = new iconOnOff(QPoint(640,340),QSize(50,50),":/myicons/AdaptiveSuspensionDampers_yellow.gif",5.0);




    ~MainWindow();
public slots:
    void Scene();
    void Test();
    void Connexion();
    void Reception();
    void Beam ();

private:
    Ui::MainWindow *ui;
    QTcpServer * server;
    QTcpSocket * socket;
    IconInna *beam = new IconInna;
};

#endif // MAINWINDOW_H
