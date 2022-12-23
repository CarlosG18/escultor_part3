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
          SLOT(setR(int)));
          
  connect(ui->horizontalSliderG,
          SIGNAL(valueChanged(int)),
          ui->widget,
          SLOT(setG(int)));
          
  connect(ui->horizontalSliderB,
          SIGNAL(valueChanged(int)),
          ui->widget,
          SLOT(setB(int)));
          
  connect(ui->horizontalSliderRaio,
          SIGNAL(valueChanged(int)),
          ui->widget,
          SLOT(setRaio(int)));

  connect(ui->pushButton,
          SIGNAL(clicked(bool)),
          ui->widget,
          SLOT(salvar()));

  connect(ui->radioButtonPV,
          SIGNAL(toggled(bool)),
          ui->widget,
          SLOT(mudaDesenhoPV()));

  connect(ui->radioButtonCV,
          SIGNAL(toggled(bool)),
          ui->widget,
          SLOT(mudaDesenhoCV()));

  connect(ui->radioButtonPB,
          SIGNAL(toggled(bool)),
          ui->widget,
          SLOT(mudaDesenhoPB()));
          
  connect(ui->radioButtonCB,
          SIGNAL(toggled(bool)),
          ui->widget,
          SLOT(mudaDesenhoCB()));
          
  connect(ui->radioButtonPS,
          SIGNAL(toggled(bool)),
          ui->widget,
          SLOT(mudaDesenhoPS()));
          
  connect(ui->radioButtonCS,
          SIGNAL(toggled(bool)),
          ui->widget,
          SLOT(mudaDesenhoCS()));
          
  connect(ui->radioButtonPE,
          SIGNAL(toggled(bool)),
          ui->widget,
          SLOT(mudaDesenhoPE()));
          
  connect(ui->radioButtonCE,
          SIGNAL(toggled(bool)),
          ui->widget,
          SLOT(mudaDesenhoCE()));
          
  /*connect(ui->actionMudaDim,
          SIGNAL(triggered()),
          this,
          SLOT(mudaDim()));*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::mudaDim(){
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
}*/

//showMaximaded();
