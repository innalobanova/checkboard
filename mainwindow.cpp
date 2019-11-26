#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->fontComboBox,SIGNAL(currentTextChanged(const QString)), this, SLOT(Font()) );
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(Font()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Scene()
{ui->graphicsView->setScene(scene);

  scene->addItem(vitesse);

}

void MainWindow::Font()
{
    //vitesse->font = ui->fontComboBox->currentText();
    vitesse->shift=ui->horizontalSlider->value();
    scene->update();

}
