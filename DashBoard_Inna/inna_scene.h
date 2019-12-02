#ifndef INNA_SCENE_H
#define INNA_SCENE_H
#include "scene_globale.h"
#include <QMainWindow>
#include "objet_virtuel.h"
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
#include "clignotant.h"

class inna_scene : public scene_globale
{
public:
    inna_scene(scene_globale *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    SpeedometerInna *speedometer = new SpeedometerInna();
    TachometerInna *tachometer = new TachometerInna();
    OilGaugeInna *oilgauge = new OilGaugeInna();
    InfoWindowInna *info = new InfoWindowInna ();
    FuelEngine *fuel_engine = new FuelEngine ();
    speedInna *speed = new speedInna();



//    ArrowSpeedometerInna *arrow_speedometer = new ArrowSpeedometerInna();

//    ArrowTachometerInna *arrow_tachometer = new ArrowTachometerInna();

//    ArrowOilT *arrow_oilT = new ArrowOilT ();
//    ArrowOilL *arrow_oilL = new ArrowOilL ();



//    FuelLevelInna *fuel_level = new FuelLevelInna ();
//    EngineTInna *engineT = new EngineTInna ();
//    PRND *AutomaticTransmissionMode = new PRND();
//    speedInna *speed = new speedInna();
//    IconHeadlight *headlights = new IconHeadlight ();
//    iconOnOff *VoyantBatterie = new iconOnOff(QPoint(540,420),QSize(40,40),":/myicons/battery.gif",5.0);
//    iconOnOff *CheckEngine = new iconOnOff(QPoint(810,420),QSize(50,50),":/myicons/checkEngine.gif",5.0);
//    iconOnOff *RearAntifog = new iconOnOff(QPoint(460,360),QSize(50,50),":/myicons/rearFogLight.gif",5.0);
//    iconOnOff *FrontAntifog = new iconOnOff(QPoint(495,360),QSize(50,50),":/myicons/frontFogLight.gif",5.0);
//    iconOnOff *RearWindowHeating = new iconOnOff(QPoint(470,400),QSize(50,50),":/myicons/rearWindowHeating_yellow.gif",5.0);
//    iconOnOff *SeatBelt = new iconOnOff(QPoint(950,200),QSize(40,40),":/myicons/seatBeltSign_red.gif",5.0);
//    iconOnOff *AdaptiveCruiseControl= new iconOnOff(QPoint(390,230),QSize(60,60),":/myicons/adaptiveCruiseControl_green.gif",5.0);
//    iconOnOff * AdaptiveSuspensionDampers = new iconOnOff(QPoint(640,340),QSize(50,50),":/myicons/AdaptiveSuspensionDampers_yellow.gif",5.0);
//    //Clignotant *clignotant = new Clignotant();
//    iconOnOff *AirbagOn = new iconOnOff (QPoint(900,195),QSize(50,50),":/myicons/airBag.gif",5.0);
//    iconOnOff *DriversDoor = new iconOnOff(QPoint(1005,210),QSize(60,60),":/myicons/driverDoorOpen.gif", 5.0 );
//    iconOnOff *FrontPassDoor = new iconOnOff(QPoint(1005,210),QSize(60,60),":/myicons/frontRightDoorOpen.gif", 5.0 );
//    iconOnOff *LeftBackPassDoor = new iconOnOff(QPoint(1005,210),QSize(60,60),":/myicons/backLeftDoorOpen.gif", 5.0 );
//    iconOnOff *RightBackPassDoor = new iconOnOff(QPoint(1005,210),QSize(60,60),":/myicons/backrightDoorOpen.gif", 5.0 );
//    iconOnOff *BonnetOpen =  new iconOnOff(QPoint(875,230),QSize(60,60),":/myicons/bonnetOpen_red.gif", 5.0 );
//    iconOnOff *BootOpen =  new iconOnOff(QPoint(940,230),QSize(60,60),":/myicons/bootOpen_red.gif", 5.0 );
//    iconOnOff *BrakeFluid = new iconOnOff(QPoint(900,415), QSize(60,60), ":/myicons/brakeLiquid_red.gif",5.0);
//    iconOnOff *BrakePads = new iconOnOff(QPoint(955,425), QSize(40,40), ":/myicons/brakePads_red.gif",5.0);
//    iconOnOff *ABS_ON = new iconOnOff (QPoint(995,420), QSize(50,50), ":/myicons/ABS_ON.gif",5.0);
//    iconOnOff *ABS_warning = new iconOnOff (QPoint(995,420), QSize(50,50), ":/myicons/abs_warning.gif",7.0);
//    iconOnOff *HandBrake = new iconOnOff(QPoint(400,350),QSize(40,40), ":/myicons/hand_brake.gif", 5.0);


};

#endif // INNA_SCENE_H
