#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRectF>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QGraphicsItem>
#include <mygraphicsitem.h>
#include <QStyleOptionGraphicsItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->verticalSlider->setValue(0);

   connect(ui->verticalSlider,SIGNAL(actionTriggered(int)),this, SLOT(vitesse()));
   connect(ui->actionclose, SIGNAL(triggered()),this,SLOT(close()));


}

MainWindow::~MainWindow()
{
    delete ui;
    delete view;
    delete scene;
    delete myitem;
}

void MainWindow::Scene()
{ui->graphicsView->setScene(scene);
 // rectangular background
//     QBrush brush;
//     QPen pen;
//     brush.setStyle(Qt::SolidPattern);
//     brush.setColor(Qt::transparent);
//     pen.setStyle(Qt::SolidLine);
//     pen.setColor(Qt::red);

//     scene->addRect(myitem->boundingRect(),pen,brush);

     myitem->v1 = ui->verticalSlider->value();
     scene->addItem(myitem);


}

void MainWindow::vitesse()
{//scene->removeItem(myitem);
    myitem->v1 = ui->verticalSlider->value();
    scene->update();

}
