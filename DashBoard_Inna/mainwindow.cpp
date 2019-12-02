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
    scene->addItem(arrow_oilT);
    AutomaticTransmissionMode->setZValue(5.0);
    scene->addItem(AutomaticTransmissionMode);
    speed->setZValue(5.0);
    scene->addItem(speed);
    scene->addItem(VoyantBatterie);
    scene->addItem(CheckEngine);
    scene->addItem(headlights);
    scene->addItem(RearAntifog);
    scene->addItem(FrontAntifog);
    scene->addItem(RearWindowHeating);
    scene->addItem(SeatBelt);
    scene->addItem(AdaptiveCruiseControl);
    scene->addItem(AdaptiveSuspensionDampers);
    scene->addItem(AirbagOn);
    scene->addItem(DriversDoor);
    scene->addItem(FrontPassDoor);
    scene->addItem(LeftBackPassDoor);
    scene->addItem(RightBackPassDoor);
    scene->addItem(BonnetOpen);
    scene->addItem(BootOpen);
    scene->addItem(BrakeFluid);
    scene->addItem(BrakePads);
    scene->addItem(ABS_ON);
    scene->addItem(ABS_warning);
    scene->addItem(HandBrake);
   // scene->addItem(clignotant);
//    myGraphicsView->setScene(scene2);
//    myGraphicsView->setGeometry(0,0,1400,600);
//    scene2->addItem(clignotant);

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
   AutomaticTransmissionMode->setValue(ui->horizontalSlider_2->value());
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
    else if(message=="CANN LIGHT"){
        int light = string.section(' ', 2,2).toInt();

        if(light>=0 && light <= 3){
           headlights->setValue(light);
           scene->update();
           QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("valeur incorrect, valeur entre 0 et 3");
            socket->write(text.toUtf8());
        }
    }

    else if(message=="CANN ASD"){
        int asd_on = string.section(' ', 2,2).toInt();
        if(asd_on==0 || asd_on==1){
            AdaptiveSuspensionDampers->setValue(asd_on);
            scene->update();
            QString text = "OK";
            socket->write(text.toLocal8Bit());
        }
        else{
            QString text;
            text = QString("valeur incorrecte, doit être égale à 0 ou 1");
            socket->write(text.toLocal8Bit());
        }
    }
    else if(message=="CANN MODE"){
        int mode = string.section(' ', 2,2).toInt();

        if(mode >=1 && mode <= 4)
        { AutomaticTransmissionMode->setValue(mode);
         scene->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("valeur incorrect, valeur entre 1 et 4");
            socket->write(text.toUtf8());
        }
    }
    else if(message=="CANN FRONT_FOG"){
        int front_fog_on = string.section(' ', 2,2).toInt();
        if(front_fog_on==0 || front_fog_on==1){
            FrontAntifog->setValue(front_fog_on);
            scene->update();
            QString text = "OK";
            socket->write(text.toLocal8Bit());
        }
        else{
            QString text;
            text = QString("valeur incorrecte, doit être égale à 0 ou 1");
            socket->write(text.toLocal8Bit());
        }
    }
    else if(message=="CANN REAR_FOG"){
        int rear_fog_on = string.section(' ', 2,2).toInt();
        if(rear_fog_on==0 || rear_fog_on==1){
            RearAntifog->setValue(rear_fog_on);
            scene->update();
            QString text = "OK";
            socket->write(text.toLocal8Bit());
        }
        else{
            QString text;
            text = QString("valeur incorrecte, doit être égale à 0 ou 1");
            socket->write(text.toLocal8Bit());
        }
    }
    else
        qDebug() << "erreur lors de la reception du message";




}

void MainWindow::Beam()
{

}
