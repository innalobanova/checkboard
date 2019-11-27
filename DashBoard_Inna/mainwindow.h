#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "speedometerinna.h"
#include "arrowspeedometerinna.h"
#include "tachometerinna.h"
#include "arrowtachometerinna.h"
#include "oilgaugeinna.h"
#include "arrowoilt.h"
#include "infowindowinna.h"
#include "fuelengine.h"
#include "iconinna.h"


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
    void HandBreak(bool);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
