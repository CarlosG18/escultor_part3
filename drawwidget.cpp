#include "drawwidget.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <vector>
#include <QDebug>


DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent) //construtor do DrawWidget
{

}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;
    int i, j,m, n;
    m = n = 10;
    std::vector< std::vector<int> > matriz;
    std::vector<int> linha;

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            qDebug() << j;
            linha[j] = 1;
        }
        //matriz.push_back(linha);
    }

    painter.setRenderHint(QPainter::Antialiasing);

    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0,0,0));
    pen.setWidth(2);

    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0,0,width(), height());

    pen.setColor(QColor(255,200,200));

    painter.setPen(pen);
    for(int i=0; i<m; i++){
        painter.drawLine(0, i*height()/m,
                         width(), i*height()/m);
    }
    for(int i=0; i<n; i++){
    painter.drawLine(i*width()/n, 0,
                         i*width()/n,
                         height());
    }

    /*for(int i=0; i<m; i++){
        for(int j=0; i<n; j++){
            if(matriz[i][j] == 1){

            }else{

            }
        }
    }*/



}
