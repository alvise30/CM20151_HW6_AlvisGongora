#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int rk4_step(float ***r, float ***v, float ***a, float **kr, float **kv, float **ri, float **vi, float h, int cuerpo, int step, int coodernada){
  
  kr[0][coordenada] = r_prime(r[cuerpo][step-1][coordenada], v[cuerpo][step-1][coordenada], a[cuerpo][step-1][coordenada]);
  kv[0][coordenada] = v_prime(r[cuerpo][step-1][coordenada], v[cuerpo][step-1][coordenada], a[cuerpo][step-1][coordenada]); 
  
  //Primer Paso
  ri[0][coordenada] = r[cuerpo][step-1][coordenada] + (h/2.0)*kr[0][coordenada];
  vi[0][coordenada] = v[cuerpo][step-1][coordenada] + (h/2.0)*kv[0][coordenada];
  hallar_aceleracion(); //Nueva aceleracion

  kr[1][coordenada] = r_prime(ri[0][coordenada], vi[0][coordenada], a[cuerpo][step-1][coordenada]);
  kv[1][coordenada] = v_prime(ri[0][coordenada], vi[0][coordenada], a[cuerpo][step-1][coordenada]); 

  //Segundo paso  
  ri[1][coordenada] = r[cuerpo][step-1][coordenada] + (h/2.0)*kr[1][coordenada];
  vi[1][coordenada] = v[cuerpo][step-1][coordenada] + (h/2.0)*kv[1][coordenada];
  hallar_aceleracion(); //Nueva aceleracion
  
  kr[2][coordenada] = r_prime(ri[1][coordenada], vi[1][coordenada], a[cuerpo][step-1][coordenada]);
  kv[2][coordenada] = v_prime(ri[1][coordenada], vi[1][coordenada], a[cuerpo][step-1][coordenada]); 
  
  //Tercer paso
  ri[2][coordenada] = r[cuerpo][step-1][coordenada] + h*kr[2][coordenada];
  vi[2][coordenada] = v[cuerpo][step-1][coordenada] + h*kv[2][coordenada];  
  hallar_aceleracion(); //Nueva Aceleracion  

  kr[3][coordenada] = r_prime(ri[2][coordenada], vi[2][coordenada], a[cuerpo][step-1][coordenada]);
  kv[3][coordenada] = v_prime(ri[2][coordenada], vi[2][coordenada], a[cuerpo][step-1][coordenada]); 
  
  //Cuarto Paso
  average_kr[coordenada] = (1.0/6.0)*(kr[0] + 2.0*kr[1] + 2.0*kr[2] + kr[3]);
  average_kv[coordenada] = (1.0/6.0)*(kv[0] + 2.0*kv[1] + 2.0*kv[2] + kv[3]);
  
  r[cuerpo][step][coordenada] = r[cuerpo][step-1][coordenada] + (h*average_kr[coordenada]);
  v[cuerpo][step][coordenada] = v[cuerpo][step-1][coordenada] + (h*average_kv[coordenada]);
  hallar_aceleracion();
}
