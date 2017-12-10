#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //gScene = new Scene(this);
    //gScene->setSceneRect(0,0,1000,1000);
    ui->graphicsView->setScene(GrapScene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
