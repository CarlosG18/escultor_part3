#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>

class DrawWidget : public QWidget
{
    Q_OBJECT
private:
  std::vector<std::vector<Voxel>> v;
  int nlinhas, ncolunas;
  int planoZ;
  int tamCel;
  int largTela, altTela;
  int largCel, altCel;
  bool pressed;
public:
    explicit DrawWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void setTamanho(int nlinhas, int ncolunas);
    void loadMatrix(std::vector<std::vector<Voxel>> l);
signals:
    void transformarX(int x);
    void transformarY(int y);
public slots:
};

#endif // DRAWWIDGET_H
