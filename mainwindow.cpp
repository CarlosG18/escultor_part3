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
          
  connect(ui->widget,
          SIGNAL(transformarX(int)),
          ui->lcdNumberX,
          SLOT(display(int)));

  connect(ui->widget,
          SIGNAL(transformarY(int)),
          ui->lcdNumberY,
          SLOT(display(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//showMaximaded();
