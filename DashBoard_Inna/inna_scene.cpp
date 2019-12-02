#include "inna_scene.h"

inna_scene::inna_scene(scene_globale *parent):scene_globale(parent)
{

}

QRectF inna_scene::boundingRect() const
{

}

void inna_scene::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    addItem(oilgauge);
    addItem(speedometer);
    addItem(tachometer);
    addItem(info);
    addItem(fuel_engine);
    Vitesse = new ArrowSpeedometerInna();
        addItem(Vitesse);
    speed->setValue(Vitesse->getValue());
        addItem(speed);
    Essence = new FuelLevelInna ();
        addItem(Essence);
    CompteTours = new ArrowTachometerInna();
        addItem(CompteTours);
    jaugeTemperature = new EngineTInna ();
        addItem(jaugeTemperature);
    VoyantBatterie = new iconOnOff(QPoint(540,420),QSize(40,40),":/myicons/battery.gif",5.0);
    position = new iconOnOff(QPoint(480,320),QSize(50,50),":/myicons/dayLight.gif",5.0);
    croisement = new iconOnOff(QPoint(480,320),QSize(50,50), ":/myicons/lowBeam.gif",5.0);
    route = new iconOnOff(QPoint(480,320),QSize(50,50), ":/myicons/highBeam.gif",5.0);
    AdaptiveSuspensionDampers = new iconOnOff(QPoint(640,340),QSize(50,50),":/myicons/AdaptiveSuspensionDampers_yellow.gif",5.0);
    AutomaticTransmissionMode = new PRND();
    RearAntifog = new iconOnOff(QPoint(460,360),QSize(50,50),":/myicons/rearFogLight.gif",5.0);
    FrontAntifog = new iconOnOff(QPoint(495,360),QSize(50,50),":/myicons/frontFogLight.gif",5.0);
    SeatBelt = new iconOnOff(QPoint(950,200),QSize(40,40),":/myicons/seatBeltSign_red.gif",5.0);
    RearWindowHeating = new iconOnOff(QPoint(470,400),QSize(50,50),":/myicons/rearWindowHeating_yellow.gif",5.0);
    CheckEngine = new iconOnOff(QPoint(810,420),QSize(50,50),":/myicons/checkEngine.gif",5.0);
    OpenDoorDriver= new iconOnOff(QPoint(1005,210),QSize(60,60),":/myicons/driverDoorOpen.gif", 5.0 );
        addItem(OpenDoorDriver);
    OpenDoorFrontPassenger = new iconOnOff(QPoint(1005,210),QSize(60,60),":/myicons/frontRightDoorOpen.gif", 5.0 );
        addItem(OpenDoorFrontPassenger);
    OpenDoorBackLeftPassenger= new iconOnOff(QPoint(1005,210),QSize(60,60),":/myicons/backLeftDoorOpen.gif", 5.0 );
        addItem(OpenDoorBackLeftPassenger);
    OpenDoorBackRightPassenger = new iconOnOff(QPoint(1005,210),QSize(60,60),":/myicons/backrightDoorOpen.gif", 5.0 );
        addItem(OpenDoorBackRightPassenger);
    AdaptiveCruiseControl= new iconOnOff(QPoint(390,230),QSize(60,60),":/myicons/adaptiveCruiseControl_green.gif",5.0);
        addItem(AdaptiveCruiseControl);
    AirbagOn = new iconOnOff (QPoint(900,195),QSize(50,50),":/myicons/airBag.gif",5.0);
        addItem(AirbagOn);
    BonnetOpen =  new iconOnOff(QPoint(875,230),QSize(60,60),":/myicons/bonnetOpen_red.gif", 5.0 );
        addItem(BonnetOpen);
    BootOpen =  new iconOnOff(QPoint(940,230),QSize(60,60),":/myicons/bootOpen_red.gif", 5.0 );
        addItem(BootOpen);





}
