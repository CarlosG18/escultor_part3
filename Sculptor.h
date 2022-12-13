#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel{
    float r, g, b; // cores: vermelho, verde e azul
    float a; //transparencia
    bool isOn; // "aparecer"
};

/**
 * @brief The Sculptor class
 */

class Sculptor
{
    private:
      Voxel ***v; // 3D matrix
      int nx,ny,nz; // Dimensions
      float r,g,b,a; // Current drawing color
    public:
      /**
       * @brief Sculptor é o construtor da classe Sculptor
       * @param _nx é o número de linhas da matriz 3d
       * @param _ny é o número de colunas da matriz 3d
       * @param _nz é o número de planos da matriz 3d
       */
      Sculptor(int _nx, int _ny, int _nz);
      ~Sculptor();
      /**
       * @brief setColor é o metódo para definir a cor que será usada na criação da estrutura.
       * @param r é o parâmetro para o vermelho - 0 até 1.
       * @param g é o parâmetro para o verde - 0 até 1.
       * @param b é o parâmetro para o azul - 0 até 1.
       * @param a é o parâmetro para o alfa (visibilidade) - 0 até 1.
       */
      void setColor(float r, float g, float b, float a);
      /**
       * @brief putVoxel é o metódo para criar um elemento de voxel.
       * @param x é o parâmetro para a posição x do voxel.
       * @param y é o parâmetro para a posição y do voxel.
       * @param z é o parâmetro para a posição z do voxel.
       */
      void putVoxel(int x, int y, int z);
      /**
       * @brief cutVoxel é o metódo para "apagar" o voxel;
       * @param x é o parâmetro para a posição x do voxel.
       * @param y é o parâmetro para a posição y do voxel.
       * @param z é o parâmetro para a posição z do voxel.
       */
      void cutVoxel(int x, int y, int z);
      /**
       * @brief putBox é o metódo para criar uma caixa de voxels
       * @param x0 é o parâmetro x inicial da caixa.
       * @param x1 é o parâmetro x final da caixa.
       * @param y0 é o parâmetro y inicial da caixa.
       * @param y1 é o parâmetro y final da caixa.
       * @param z0 é o parâmetro z inicial da caixa.
       * @param z1 é o parâmetro z final da caixa.
       */
      void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
      /**
       * @brief cutBox é o metódo para "apagar" uma caixa de voxels.
       * @param x0 é o parâmetro x inicial da caixa.
       * @param x1 é o parâmetro x final da caixa.
       * @param y0 é o parâmetro y inicial da caixa.
       * @param y1 é o parâmetro y final da caixa.
       * @param z0 é o parâmetro z inicial da caixa.
       * @param z1 é o parâmetro z final da caixa.
       */
      void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
      /**
       * @brief putSphere é o metódo para criar uma esfera de voxels.
       * @param xcenter é o parâmetro que define o centro da esfera em x
       * @param ycenter é o parâmetro que define o centro da esfera em y
       * @param zcenter é o parâmetro que define o centro da esfera em z
       * @param radius é o parâmetro que define o tamanho do raio da esfera
       */
      void putSphere(int xcenter, int ycenter, int zcenter, int radius);
      /**
       * @brief cutSphere é o metódo para "apagar" uma esfera de voxels
       * @param xcenter é o parâmetro que define o centro da esfera em x
       * @param ycenter é o parâmetro que define o centro da esfera em y
       * @param zcenter é o parâmetro que define o centro da esfera em z
       * @param radius é o parâmetro que define o tamanho do raio da esfera
       */
      void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
      /**
       * @brief putEllipsoid é o metódo para definir um elipsoide de voxels
       * @param xcenter é o parâmetro que define o centro do elipsoide em x
       * @param ycenter é o parâmetro que define o centro do elipsoide em y
       * @param zcenter é o parâmetro que define o centro do elipsoide em z
       * @param rx é o parâmetro que define o tamanho do raio da elipsoide em torno do eixo x
       * @param ry é o parâmetro que define o tamanho do raio da elipsoide em torno do eixo y
       * @param rz é o parâmetro que define o tamanho do raio da elipsoide em torno do eixo z
       */
      void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
      /**
       * @brief cutEllipsoid é o metódo para "apagar" um elipsoide de voxels
       * @param xcenter é o parâmetro que define o centro do elipsoide em x
       * @param ycenter é o parâmetro que define o centro do elipsoide em y
       * @param zcenter é o parâmetro que define o centro do elipsoide em z
       * @param rx é o parâmetro que define o tamanho do raio da elipsoide em torno do eixo x
       * @param ry é o parâmetro que define o tamanho do raio da elipsoide em torno do eixo y
       * @param rz é o parâmetro que define o tamanho do raio da elipsoide em torno do eixo z
       */
      void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
      /**
       * @brief writeOFF é o metódo que transcreverá todos os verticíes e faces aplicados para o formato (OFF).
       * @param filename é o arquivo de saída no formato off resultante
       */
      void writeOFF(const char* filename);
      vector <vector<Voxel> > getPlano(int z);
};

#endif // SCULPTOR_H
