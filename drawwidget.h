#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H
#include "Sculptor.h"

#include <QWidget>

/*enum Desenho{
  putVoxel, cutVoxel, putBox, cutBox, putSphere, cutSphere, putEllipsoid, cutEllipsoid
};*/

class DrawWidget : public QWidget
{
    Q_OBJECT
private:
  std::vector<std::vector<Voxel>> v;
  //Sculptor *s;
  //Desenho modoDesenho;
  int nlinhas, ncolunas;
  int planoZ;
  int tamCel;
  int largTela, altTela;
  int largCel, altCel;
  float r, g, b, a;
  int Raio;
  bool pressed;
public:
  explicit DrawWidget(QWidget *parent = nullptr);
  void paintEvent(QPaintEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void setTamanho(int nlinhas, int ncolunas);
  void loadMatrix(std::vector<std::vector<Voxel>> l);
signals:
  void mudaX(int x);
  void mudaY(int y);
public slots:
  void mudaZ(int z);
  void setR(float r);
  void setG(float g);
  void setB(float b);
  void setA(float a);
  void setRaio(int raio);
};

#endif // DRAWWIDGET_H
