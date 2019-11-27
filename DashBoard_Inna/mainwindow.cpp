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
    scene->setBackgroundBrush(QBrush(Qt::black, Qt::Dense1Pattern));
    //scene->setBackgroundBrush(QBrush(QPixmap(":/icons/myicons/black-leather-texture-background.jpg")));
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

         server = new QTcpServer(this);
         server->listen(QHostAddress::Any, 2222);
         connect(server,SIGNAL(newConnection()),this, SLOT(connexion()));
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

void MainWindow::connexion()
{
    socket = this->server->nextPendingConnection();
    qDebug() << "Connected";
    connect(socket, SIGNAL(readyRead()),this, SLOT(reception()));
}

void MainWindow::reception()
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
//    if(message=="CANN GAZ"){
//        int essence = string.section(' ', 2,2).toInt();
//        if(essence>=0 && essence <= dashboard->Essence->getValueMax()){
//            dashboard->Essence->setValue(essence);
//            ui->graphicsView->scene()->update();
//            QString text = "OK";
//            socket->write(text.toUtf8());
//        }
//        else{
//            QString text;
//            text = QString("Quantité incorrect, vitesse comprise entre 0 et %1").arg(dashboard->Essence->getValueMax());
//            socket->write(text.toUtf8());
//        }
//    }
//    else
//        qDebug() << "erreur lors de la reception du message";
}
