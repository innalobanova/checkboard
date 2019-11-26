#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "gauge.h"
#include "speedometerinna.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    Gauge *vitesse = new Gauge();
    SpeedometerInna *speedometer = new SpeedometerInna();
    QGraphicsScene *scene = new QGraphicsScene ();

    ~MainWindow();
public slots:
    void Scene();
    void Font();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
