#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int rk4_step(float ***r, float ***v, float ***a, float **kr, float **kv, float **ri, float **vi, float h, int cuerpo, int step, int coodernada){

  for(i=0;i<3;i++){
    kr[i][coordenada] = ; 
    kv[i][coordenada] = r_prime(dt, v[cuerpo][step-1][coordenada], a);
    
    //Paso
    ri[i][coordenada] = r[cuerpo][step-1][coordenada] + (h/2.0) * kr[i];
    vi[i][coordenada] = v[cuerpo][step-1][coordenada] + (h/2.0) * kv[i];
  }

  //  
  kr[3][coordenada] = ;
  kv[3][coordenada] = r_prime(ri[2][coordenada], vi[2][coordenada]);

  //Promedio
  average_kr[coordenada] = (1.0/6.0)*(kr[0] + 2.0*kr[1] + 2.0*kr[2] + kr[3]);
  average_kv[coordenada] = (1.0/6.0)*(kv[0] + 2.0*kv[1] + 2.0*kv[2] + kv[3]);
  
  r[cuerpo][step][coordenada] = r[cuerpo][step-1][coordenada] + (h*average_kr[coordenada]);
  v[cuerpo][step][coordenada] = v[cuerpo][step-1][coordenada] + (h*average_kv[coordenada]);
}