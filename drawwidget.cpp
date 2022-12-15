#include "drawwidget.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <vector>
#include <QDebug>
#include "Sculptor.h"

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent) //construtor do DrawWidget
{
  ncolunas = nlinhas = planoZ = 30;
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
  int i, j;
  Sculptor s(nlinhas,ncolunas,planoZ)
  loadMatrix(s.getPlano(planoZ))
  
  QPainter painter(this); //"artista"
  QBrush brush; //"preenchimento"
  QPen pen; //"contorno"
    
  painter.setRenderHint(QPainter::Antialiasing);
    
  //retângulo branco (área de desenho)
  brush.setColor(QColor(255,255,255));
  brush.setStyle(Qt::SolidPattern);
  pen.setColor(QColor(0,0,0));
  pen.setWidth(2);
  painter.setBrush(brush);
  painter.setPen(pen);
  painter.drawRect(2,2,width()-2, height()-2);
  
  for(int i=0; i<nlinhas; i++){
    for(int j=0; j<ncolunas; j++){
      if(v[i][j].isOn == true){
        brush.setColor(QColor(v[i][j].r,v[i][j].g,v[i][j].b));
		    //painter.drawEllipse(QPoint(i*(width()/n)+(width()/2*n),j*(height()/m)+(height()/2*m),10,10));
      }else{
        brush.setColor(QColor(255,255,255));
		    //painter.drawRect(i*width()/n,j*width()/m,width()/n,height()/m);
      }
    }
  }
}

void DrawWidget::mousePressEvent(QMouseEvent *event){
  //qDebug() << event->x() << event->y();
  emit transformarX(event->x());
  emit transformaY(event->y());
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

void DrawWidget::setTamanho(int nlinhas, int ncolunas){
  
}
