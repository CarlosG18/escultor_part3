#include "drawwidget.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <vector>
#include <QDebug>
#include <QMouseEvent>
#include "Sculptor.h"

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent) //construtor do DrawWidget
{
  ncolunas = nlinhas = planoZ = 30;
  setTamanho(nlinhas, ncolunas);
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
  int i, j;
  std::vector<std::vector<Voxel>> l;

  Sculptor s(nlinhas,ncolunas,planoZ);
  s.setColor(r,g,b,a);
  loadMatrix(s.getPlano(planoZ));
  
  QPainter painter(this); //"artista"
  QBrush brush; //"preenchimento"
  QPen pen; //"contorno"
    
  painter.setRenderHint(QPainter::Antialiasing);
    
  //retângulo branco (área de desenho)
  brush.setColor(QColor(255,255,255));
  brush.setStyle(Qt::SolidPattern);
  pen.setColor(QColor(0,0,0));
  pen.setWidth(1);
  painter.setBrush(brush);
  painter.setPen(pen);
  
  for(i=0; i<nlinhas; i++){
    for(j=0; j<ncolunas; j++){
      if(v[i][j].isOn == true){
        brush.setColor(QColor(v[i][j].r,v[i][j].g,v[i][j].b));
        painter.setBrush(brush);
        painter.drawRect(QRect(i*largCel,j*altCel,largCel,altCel));
      }else{
        brush.setColor(QColor(255,255,255));
        painter.setBrush(brush);
        painter.drawRect(QRect(i*largCel,j*altCel,largCel,altCel));
      }
    }
  }

}

void DrawWidget::mousePressEvent(QMouseEvent *event){
  //qDebug() << event->x();
  /*
  
  */
  emit mudaX(event->x()/largCel);
  emit mudaY(event->y()/altCel);
}

void DrawWidget::mouseMoveEvent(QMouseEvent *event)
{
    //emit mudaX(event->x());
    //emit mudaY(event->y());
}

void DrawWidget::loadMatrix(std::vector<std::vector<Voxel>> l){

  int i,j;
  std::vector<Voxel> linha;

  for(i=0; i<nlinhas; i++){
    linha.resize(ncolunas);
    for(j=0; j<ncolunas; j++){
      linha[j].r = l[i][j].r;
      linha[j].g = l[i][j].g;
      linha[j].b = l[i][j].b;
      linha[j].a = l[i][j].a;
      linha[j].isOn = l[i][j].isOn;
    }
    v.push_back(linha);
  }
}

void DrawWidget::mudaZ(int z){
  this->planoZ = z;
}

void DrawWidget::setR(float r){
  this->r = r;
}

void DrawWidget::setG(float g){
  this->g = g;
}

void DrawWidget::setB(float b){
  this->b = b;
}

void DrawWidget::setB(float a){
  this->a = a;
}

void DrawWidget::setTamanho(int nlinhas, int ncolunas){
  this->largTela = 651;
  this->altTela = 411;
  this->largCel = largTela/ncolunas;
  this->altCel = altTela/nlinhas;
}
