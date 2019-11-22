#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "mygraphicsitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QGraphicsView *view = new QGraphicsView();
    QGraphicsScene *scene = new QGraphicsScene ();
    MyGraphicsItem *myitem = new MyGraphicsItem ();
    ~MainWindow();
public slots:
    void Scene();
    void vitesse();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
