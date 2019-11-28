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
    IconInna *myicon = new IconInna;
    IconInna *door1 = new IconInna ();
    IconInna *door2 = new IconInna ();

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
