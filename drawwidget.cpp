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
  loadMatrix(s.getPlano(5))
  
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
      if(v[i][j][planoZ].isOn == true){
        brush.setColor(QColor(v[i][j][planoZ].r,v[i][j][planoZ].g,v[i][j][planoZ].b));
		    //painter.drawEllipse(QPoint(i*(width()/n)+(width()/2*n),j*(height()/m)+(height()/2*m),10,10));
      }else{
        brush.setColor(QColor(255,255,255));
		    //painter.drawRect(i*width()/n,j*width()/m,width()/n,height()/m);
      }
    }
  }
}

void DrawWidget::mousePressEvent(QMouseEvent *event){
  qDebug() << event->x() << event->y();
  emit transformarX(event->x());
  emit transformaY(event->y());
}

void DrawWidget::loadMatrix(std::vector<std::vector<Voxel>> l){
  
}

void DrawWidget::setTamanho(int nlinhas, int ncolunas){
  
}
