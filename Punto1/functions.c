#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Constantes*/
#define G 39.486 //Unidades¿?

/*r prima*/
float r_prime(float r, float v, float a){
  return v;
}
/*v prima*/
float v_prime(float r, float v, float a){
  return a;
}





//==========================================
/*Hallar Aceleracion*/
void hallar_aceleracion(float ***r, float ***a, float *m, int n_cuerpos, int step, int n_coordenadas){

  int i,j,k;
  float r_ij;

  for(i=0;i<n_cuerpos;i++){
    for(k=0;k<n_coordenadas;k++){
      a[i][step][k]=0.0;
    }
    for(j=0;j<n_cuerpos;j++){
      if(j!=i){
	for(k=0;k<n_coordenadas;k++){
	  r_ij += pow((r[i][step][k]-r[j][step][k]),2.0);
	}
	r_ij = sqrt(r_ij);
	for(k=0;k<n_coordenadas;k++){
	  a[i][step][k] += -G * m[j]/pow(r_ij,1.5) * (r[i][step][k]-r[j][step][k]);

	}
      }
    }
  }
}
