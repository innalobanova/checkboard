#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QSlider>
#include <QCheckBox>
#include <QtMath>
#include <QPixmap>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include "libH/iconinna.h"
#include <QFontDatabase>
#include "objet_virtuel.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFontDatabase::addApplicationFont(":/icons/SevenSegment.ttf");
    QFontDatabase::addApplicationFont(":/icons/myicons/mecheffects2bb_ital.ttf");
    QFontDatabase::addApplicationFont(":/icons/myicons/mecheffects2bb_reg.ttf");
   // QResource::registerResource("SevenSegment");


    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(Test()));
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), this, SLOT(Test()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Scene()
{
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

    arrow_tachometer->setZValue(10.0);
    arrow_speedometer->setZValue(10.0);
    arrow_oilT->setZValue(10.0);
    arrow_oilL->setZValue(10.0);
    engineT->setZValue(10.0);
    fuel_level->setZValue(10.0);

    scene->addItem(arrow_tachometer);
    scene->addItem(arrow_oilL);
    scene->addItem(fuel_engine);
    scene->addItem(fuel_level);
    scene->addItem(engineT);
    scene->addItem(oilgauge);
    scene->addItem(info);
    scene->addItem(speedometer);
    scene->addItem(tachometer);
    scene->addItem(arrow_speedometer);
    myicon->setVisible(5);

    scene->addItem(arrow_oilT);
    door1->init(QPoint (930,280), QSize(100,100), ":/myicons/driverDoorOpen.gif");
    door2->init(QPoint (930,280), QSize(100,100), ":/myicons/backrightDoorOpen.gif");
    scene->addItem(door1);
    scene->addItem(door2);
    drive_mode->setZValue(5.0);
    scene->addItem(drive_mode);
    speed->setZValue(5.0);
    scene->addItem(speed);
    scene->addItem(VoyantBatterie);
    scene->addItem(CheckEngine);
    scene->addItem(headlights);
    scene->addItem(RearFogLight);
    scene->addItem(FrontFogLight);
    scene->addItem(RearWindowHeating);
    scene->addItem(SeatBealt);
    scene->addItem(AdaptiveCruiseControl);
    scene->addItem(AdaptiveSuspensionDampers);

//   server = new QTcpServer(this);
//    server->listen(QHostAddress::LocalHost, 2222);
//    connect(server,SIGNAL(newConnection()),this, SLOT(Connexion()));


}

void MainWindow::Test()
{
   // tachometer->font.setFamily(ui->fontComboBox->currentText());
    int v = ui->horizontalSlider->value();
    arrow_speedometer->v = v;
    arrow_tachometer->v = v*30;
    arrow_oilT->t = v;
    arrow_oilL->l = v/5.f;
    fuel_level->setValue(qRound(v/5.0f));
    engineT->t = v;
    fuel_level->l = v/100.0;
   drive_mode->setValue(ui->horizontalSlider_2->value());
   speed->setValue(v);
   headlights->setValue(ui->horizontalSlider_2->value());
   scene->update();

}

void MainWindow::Connexion()
{
    socket = this->server->nextPendingConnection();
    qDebug() << "Connected";
    connect(socket, SIGNAL(readyRead()),this, SLOT(Reception()));
}

void MainWindow::Reception()
{
    //ui->text->setText(QString(socket->readAll()));
    QString string(socket->readAll());
    QString message = string.section(' ',0,1);

    if(message=="CANN SPEED"){
        int vitesse = string.section(' ', 2,2).toInt();
        if(vitesse>=0 && vitesse <= arrow_speedometer->vmax){
            arrow_speedometer->v = vitesse;
            scene->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("vitesse incorrect, vitesse comprise entre 0 et %1").arg(arrow_speedometer->vmax);
            socket->write(text.toUtf8());
        }
    }
    if(message=="CANN RPM"){
        int rpm = string.section(' ', 2,2).toInt();
        if(rpm>=0 && rpm <= arrow_tachometer->vmax){
            arrow_tachometer->v = rpm;
            scene->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("rpm incorrect, vitesse comprise entre 0 et %1").arg(arrow_tachometer->vmax);
            socket->write(text.toUtf8());
        }
    }
    if(message=="CANN BATTERY_LIGHT"){
        int battery_on = string.section(' ', 2,2).toInt();
        if(battery_on==0 || battery_on==1){
        QString pth = (battery_on == 0 ? ":/myicons/OFF.gif" : ":/myicons/battery.gif");
        IconInna *icon1 = new IconInna (QPoint(685,500), QSize(50,50), pth) ;
        scene->addItem(icon1);
        scene->update();
        QString text = "OK";
        socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("valeur incorrecte, doit être égale à 0 ou 1");
            socket->write(text.toUtf8());
        }
    }

}

void MainWindow::Beam()
{

}
