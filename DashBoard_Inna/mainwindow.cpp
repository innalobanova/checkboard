#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QSlider>
#include <QCheckBox>
#include <QtMath>
#include <QPixmap>
#include "iconinna.h"


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

    scene->setBackgroundBrush(QBrush(QPixmap(":/icons/texture1.png")));
    scene->addItem(fuel_engine);
    scene->addItem(oilgauge);
    scene->addItem(info);
    scene->addItem(speedometer);
    scene->addItem(tachometer);
    myicon->imagePath = ":/myicons/hand_brake.png";
    myicon->position = QPoint(685,350);
    myicon->size = QSize(50,50);
    scene->addItem(myicon);
    scene->addItem(arrow_speedometer);
    scene->addItem(arrow_tachometer);
    scene->addItem(arrow_oilT);
     scene->update();
    // delete myicon;


}

void MainWindow::Font()
{

    //vitesse->shift=ui->horizontalSlider->value();
    int v = ui->horizontalSlider->value();
    arrow_speedometer->v = v;
    arrow_tachometer->v = v/27;
    arrow_oilT->t = v;
    oilgauge->l = v/60.f;
    fuel_engine->t = v;
    fuel_engine->l = v/100.0;
    scene->update();

}

void MainWindow::HandBreak(bool ON)
{


}
