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
    QGraphicsScene *scene = new QGraphicsScene ();
    InfoWindowInna *info = new InfoWindowInna ();
    FuelEngine *fuel_engine = new FuelEngine ();
    IconInna *myicon = new IconInna;

    ~MainWindow();
public slots:
    void Scene();
    void Font();
    void connexion();
    void reception();

private:
    Ui::MainWindow *ui;
    QTcpServer * server;
    QTcpSocket * socket;
};

#endif // MAINWINDOW_H
