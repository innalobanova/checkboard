#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QSlider>

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
    speedometer->vmax=350;
    scene->addItem(speedometer);
    scene->setBackgroundBrush(QBrush(Qt::blue, Qt::Dense4Pattern));
}

void MainWindow::Font()
{

    //vitesse->shift=ui->horizontalSlider->value();
    speedometer->v = ui->horizontalSlider->value();
    scene->update();

}
