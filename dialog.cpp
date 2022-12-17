#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);
}

Dialog::~Dialog()
{
  delete ui;
}

int Dialog::getX()
{
  return ui->horizontalSliderX->value();
}

int Dialog::getY()
{
  return ui->horizontalSliderY->value();
}

int Dialog::getZ()
{
  return ui->horizontalSliderZ->value();
}