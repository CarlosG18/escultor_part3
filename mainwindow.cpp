#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);
    
  connect(ui->horizontalSliderZ,
          SIGNAL(valueChanged(int)),
          ui->widget,
          SLOT(mudaZ(int)));
          
  connect(ui->horizontalSliderR,
          SIGNAL(valueChanged(int)),
          ui->widget,
          SLOT(setR(float)));
          
  connect(ui->horizontalSliderG,
          SIGNAL(valueChanged(int)),
          ui->widget,
          SLOT(setG(float)));
          
  connect(ui->horizontalSliderB,
          SIGNAL(valueChanged(int)),
          ui->widget,
          SLOT(setB(float)));
          
  connect(ui->widget,
          SIGNAL(mudaX(int)),
          ui->lcdNumberX,
          SLOT(display(int)));

  connect(ui->widget,
          SIGNAL(mudaY(int)),
          ui->lcdNumberY,
          SLOT(display(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//showMaximaded();
