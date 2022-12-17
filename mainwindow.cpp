#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QMessageBox>
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
          
  connect(ui->horizontalSliderRaio,
          SIGNAL(valueChanged(int)),
          ui->widget,
          SLOT(setRaio(int)));
          
  connect(ui->widget,
          SIGNAL(mudaX(int)),
          ui->lcdNumberX,
          SLOT(display(int)));

  connect(ui->widget,
          SIGNAL(mudaY(int)),
          ui->lcdNumberY,
          SLOT(display(int)));
          
  connect(ui->actionMudaDim,
          SIGNAL(triggered()),
          this,
          SLOT(mudaDim()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mudaDim(){
  Dialog d;
  QMessageBox box;
  QString s;
  if (d.exec() == QDialog::Accepted){
    s = QString("<b>X = </b>") +
        QString().setNum(d.getX()) + QString("<br>")+
        QString("<b>Y = </b>") +
        QString().setNum(d.getY()) + QString("<br>")+
        QString("<b>Z = </b>") +
        QString().setNum(d.getZ()) + QString("<br>");

    box.setText(s);
    box.exec();
    ui->widget->setSculptor(d.getX(), d.getY(), d.getZ());
}

//showMaximaded();
