#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include "point.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    for(int i = 0; i<n; i++){
        points[i]->draw(&painter);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int k = 0;
    Point *p=nullptr;
    if(n>=10) return;
    p = new Point(event->x(), event->y());
    points[n] = p;
    if(n>0){
        k = points[n-1]->getSize()+1;
        points[n]->setSize(k);
        if(n > 4) points[n]->setWidth(2);
    }
    n++;
    repaint();
}
