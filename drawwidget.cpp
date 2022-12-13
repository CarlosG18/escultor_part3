#include "drawwidget.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <vector>
#include <QDebug>
#include "Sculptor.h"

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent) //construtor do DrawWidget
{

}

void DrawWidget::paintEvent(QPaintEvent *event)
{
  int i, j,m, n; // m e n => dimensoes x e y
  m = n = 10;
  //Sculptor s(30,30,30)
  //s.getPlano(5);
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

  //traços da "matriz"
  pen.setColor(QColor(0,0,0));
  //painter.setPen(pen);
  for(int i=0; i<m; i++){
    painter.drawLine(0, i*height()/m,width(), i*height()/m);
  }
  for(int i=0; i<n; i++){
    painter.drawLine(i*width()/n, 0,i*width()/n,height());
  }
    
  //testando o clique - definindo o tipo do desenho do voxel
  std::vector< std::vector<int> > matriz;
  std::vector<int> linha;
  for(i = 0; i < n; i++){
    for(j = 0; j < m; j++){
      linha.push_back(0);
    }
    matriz.push_back(linha);
  }
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(matriz[i][j] == 1){
        brush.setColor(QColor(255,0,0));
		    painter.drawEllipse(QPoint(i*(width()/n)+(width()/2*n),j*(height()/m)+(height()/2*m),10,10));
      }else{
        brush.setColor(QColor(255,255,255));
		    painter.drawRect(i*width()/n,j*width()/m,width()/n,height()/m);
      }
    }
  }
}

void DrawWidget::mousePressEvent(QMouseEvent *event){
  qDebug() << event->x() << event->y();
  emit transformarX(event->x());
  emit transformaY(event->y());
}
