#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QSlider>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(Font()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Scene()
{ui->graphicsView->setScene(scene);

//  scene->addItem(vitesse);

    scene->addItem(speedometer);
    scene->addItem(tachometer);
    scene->addItem(oilgauge);
    scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
}

void MainWindow::Font()
{

    //vitesse->shift=ui->horizontalSlider->value();
    int v = ui->horizontalSlider->value();
    speedometer->v = v;
    tachometer->v = v*27;
    oilgauge->t = v/2;
    oilgauge->l = v/60.f;
    scene->update();

}
