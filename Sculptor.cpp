#include <iostream>
#include <fstream>
#include "Sculptor.h"
#include <vector>
#include <QDebug>

Sculptor::~Sculptor()
{
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

Sculptor::Sculptor(int _nx, int _ny, int _nz){


  int i,j,k;

  this->nz = _nz;
  this->ny = _ny;
  this->nx = _nx;

  	//alocando dinamicamente a matriz 3d
  	v = (Voxel***) new Voxel[nz];
	v[0] = (Voxel**) new Voxel[nz*nx];
	v[0][0] = new Voxel[nz*nx*ny];

	//ajustando os endereços
	for(i=1;i<nz;i++){
		v[i] = v[i-1] + ny;
	}
	for(i=1; i<nz*ny;i++){
		v[0][i] = v[0][i-1] + nx;
	}

	//set padrao de cada elemento de Voxel
	for(i=0; i<nz; i++){
		for(j=0; j<ny; j++){
			for(k=0; k<nx; k++){
				v[i][j][k].r = 255;
				v[i][j][k].g = 255;
				v[i][j][k].b = 255;
				v[i][j][k].a = 1.0;
				v[i][j][k].isOn = false;
			}
		}
	}
}

void Sculptor::setColor(float r, float g, float b, float a){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[z][y][x].isOn = true;
    v[z][y][x].r = r;
    v[z][y][x].g = g;
    v[z][y][x].b = b;
    v[z][y][x].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[z][y][x].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int i,j,k;

    for(k=z0; k<=z1; k++){
        for(j=y0; j<=y1; j++){
            for(i=x0; i<=x1; i++){
                putVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int i,j,k;

    for(k=z0; k<=z1; k++){
        for(j=y0; j<=y1; j++){
            for(i=x0; i<=x1; i++){
                cutVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
   int i,j,k;

    for(k=0; k<nz; k++){
        for(j=0; j<ny; j++){
            for(i=0; i<nx; i++){
                if((((i-xcenter)*(i-xcenter))+((j-ycenter)*(j-ycenter))+((k-zcenter)*(k-zcenter))) <= ((radius)*(radius))){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    int i,j,k;

    for(k=0; k<nz; k++){
        for(j=0; j<ny; j++){
            for(i=0; i<nx; i++){
                if((((i-xcenter)*(i-xcenter))+((j-ycenter)*(j-ycenter))+((k-zcenter)*(k-zcenter))) <= ((radius)*(radius))){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int i,j,k;

    for(k=0; k<nz; k++){
        for(j=0; j<ny; j++){
            for(i=0; i<nx; i++){
                if(((((float(i-xcenter)/rx))*(float(i-xcenter)/rx))+((float(j-ycenter)/ry)*(float(j-ycenter)/ry))+(((float(k-zcenter)/rz))*((float(k-zcenter)/rz)))) <= 1.0 ){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int i,j,k;

    for(k=0; k<nz; k++){
        for(j=0; j<ny; j++){
            for(i=0; i<nx; i++){
                if(((((float(i-xcenter)/rx))*(float(i-xcenter)/rx))+((float(j-ycenter)/ry)*(float(j-ycenter)/ry))+(((float(k-zcenter)/rz))*((float(k-zcenter)/rz)))) <= 1.0 ){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename){
    int i,j,k,l = 0,cont = 0;
    int n_v, n_f;

    std::ofstream file;
    file.open(filename);

    for(k=0;k<nz;k++){
        for(j=0;j<ny;j++){
            for(i=0;i<nx;i++){
                if(v[k][j][i].isOn == true){
                    cont++;
                }
            }
        }
    }

    n_v = 8 * cont;
    n_f = 6 * cont;

    file << "OFF" << std::endl;
    //colocando o numero de Nverticies NFaces  NArestas
    file << n_v << " " << n_f << " 0" << std::endl;

    //verticies
    for(k=0;k<nz;k++){
        for(j=0;j<ny;j++){
            for(i=0;i<nx;i++){
                if(v[k][j][i].isOn == true){
                    file << k-0.5 << " " << j+0.5 << " " << i-0.5 << std::endl;
                    file << k-0.5 << " " << j-0.5 << " " << i-0.5 << std::endl;
                    file << k+0.5 << " " << j-0.5 << " " << i-0.5 << std::endl;
                    file << k+0.5 << " " << j+0.5 << " " << i-0.5 << std::endl;
                    file << k-0.5 << " " << j+0.5 << " " << i+0.5 << std::endl;
                    file << k-0.5 << " " << j-0.5 << " " << i+0.5 << std::endl;
                    file << k+0.5 << " " << j-0.5 << " " << i+0.5 << std::endl;
                    file << k+0.5 << " " << j+0.5 << " " << i+0.5 << std::endl;
                }
            }
        }
    }

    //planos
        for(k=0;k<nz;k++){
            for(j=0;j<ny;j++){
                for(i=0;i<nx;i++){
                    if(v[k][j][i].isOn == true){
                      file << "4 " << (8*l)+0 << " " << (8*l)+3 << " " << (8*l)+2 << " " << (8*l)+1 << " " << std::fixed << v[k][j][i].r << " " << std::fixed << v[k][j][i].g << " " << std::fixed << v[k][j][i].b << " " << v[k][j][i].a << std::endl;
                      file << "4 " << (8*l)+4 << " " << (8*l)+5 << " " << (8*l)+6 << " " << (8*l)+7 << " " << std::fixed << v[k][j][i].r << " " << std::fixed << v[k][j][i].g << " " << std::fixed << v[k][j][i].b << " " << v[k][j][i].a << std::endl;
                      file << "4 " << (8*l)+0 << " " << (8*l)+1 << " " << (8*l)+5 << " " << (8*l)+4 << " " << std::fixed << v[k][j][i].r << " " << std::fixed << v[k][j][i].g << " " << std::fixed << v[k][j][i].b << " " << v[k][j][i].a << std::endl;
                      file << "4 " << (8*l)+0 << " " << (8*l)+4 << " " << (8*l)+7 << " " << (8*l)+3 << " " << std::fixed << v[k][j][i].r << " " << std::fixed << v[k][j][i].g << " " << std::fixed << v[k][j][i].b << " " << v[k][j][i].a << std::endl;
                      file << "4 " << (8*l)+3 << " " << (8*l)+7 << " " << (8*l)+6 << " " << (8*l)+2 << " " << std::fixed << v[k][j][i].r << " " << std::fixed << v[k][j][i].g << " " << std::fixed << v[k][j][i].b << " " << v[k][j][i].a << std::endl;
                      file << "4 " << (8*l)+1 << " " << (8*l)+2 << " " << (8*l)+6 << " " << (8*l)+5 << " " << std::fixed << v[k][j][i].r << " " << std::fixed << v[k][j][i].g << " " << std::fixed << v[k][j][i].b << " " << v[k][j][i].a << std::endl;
                      l++;
                    }
                }
            }
        }
    file.close();
}

std::vector<std::vector<Voxel>> Sculptor::getPlano(int z){
  std::vector<std::vector<Voxel>> retorno;
  std::vector<Voxel> linha;
  int i,j;

  for(i = 0; i<nx; i++){
    linha.resize(ny);
    for(j = 0; j<ny; j++){
      linha[j].r = v[i][j][z].r;
      linha[j].g = v[i][j][z].g;
      linha[j].b = v[i][j][z].b;
      linha[j].a = v[i][j][z].a;
      linha[j].isOn = v[i][j][z].isOn;
    }
    retorno.push_back(linha);
  }
  
  return retorno;
  
}


