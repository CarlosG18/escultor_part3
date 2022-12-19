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
  s = new Sculptor(nlinhas,ncolunas,planoZ);
  setTamanho(nlinhas, ncolunas);
  a = 1;
  planoZ = 1;
  r = g = b = 0;
  s->setColor(r,g,b,a);
  loadMatrix(s->getPlano(planoZ));
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
  int i, j;
  QPainter painter(this); //"artista"
  QBrush brush; //"preenchimento"
  QPen pen; //"contorno"
    
  painter.setRenderHint(QPainter::Antialiasing);
    
  //configurações de desenho
  brush.setStyle(Qt::SolidPattern);
  pen.setWidth(1);
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

  s->setColor(r,g,b,a);
  s->putVoxel(event->x()/largCel,event->y()/altCel,planoZ);
  loadMatrix(s->getPlano(planoZ));
  repaint();
    /*
  if(modoDesenho == putVoxel){
    s->putVoxel(event->x()/largCel,event->y()/altCel,planoZ);
  }else if(modoDesenho == cutVoxel){
    s->cutVoxel(event->x()/largCel,event->y()/altCel,planoZ);
  }else if(modoDesenho == putBox){
    s->putBox(event->x()/largCel,largBoxX,event->y()/altCel,altBoxY,planoZ,Zbox);
  }else if(modoDesenho == cutBox){
    s->cutBox(event->x()/largCel,largBoxX,event->y()/altCel,altBoxY,planoZ,Zbox);
  }else if(modoDesenho == putSphere){
    s->putSphere(event->x()/largCel,event->y()/altCel,planoZ,Raio);
  }else if(modoDesenho == cutSphere){
    s->cutSphere(event->x()/largCel,event->y()/altCel,planoZ,Raio);
  }else if(modoDesenho == putEllipsoid){
    s->putEllipsoid(event->x()/largCel,event->y()/altCel,planoZ,RaioX,RaioY,RaioZ);
  }else if(modoDesenho == cutEllipsoid){
    s->cutEllipsoid(event->x()/largCel,event->y()/altCel,planoZ,RaioX,RaioY,RaioZ);
  }*/

  s->listCores();
  s->writeOFF("teste1.off");

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

void DrawWidget::setR(int r){
  this->r = r;
    s->setColor(r,g,b,a);
  repaint();
}

void DrawWidget::setG(int g){
  this->g = g;
    s->setColor(r,g,b,a);
  repaint();
}

void DrawWidget::setB(int b){
  this->b = b;
    s->setColor(r,g,b,a);
  repaint();
}

void DrawWidget::setRaio(int raio){
  this->Raio = raio;
}

void DrawWidget::setTamanho(int nlinhas, int ncolunas){
  this->largTela = 651;
  this->altTela = 411;
  this->largCel = largTela/ncolunas;
  this->altCel = altTela/nlinhas;
}

void DrawWidget::setSculptor(int x, int y, int z){
  s->~Sculptor();
  this->nlinhas = x;
  this->ncolunas = y;
  this->planoZ = z;
  s = new Sculptor(nlinhas,ncolunas,planoZ);
  setTamanho(nlinhas, ncolunas);
}
