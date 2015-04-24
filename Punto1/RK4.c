#include <stdio.h>
#include <stdlib.h>
#include "functions.o"

int rk4_step(float ***r, float ***v, float ***a, float ***kr, float ***kv, float ***ri, float ***vi, float *m, float h, int n_cuerpos, int n_coordenadas, int cuerpo, int step, int coodernada){
  
  kr[cuerpo][0][coordenada] = r_prime(r[cuerpo][step-1][coordenada], v[cuerpo][step-1][coordenada], a[cuerpo][step-1][coordenada]);
  kv[cuerpo][0][coordenada] = v_prime(r[cuerpo][step-1][coordenada], v[cuerpo][step-1][coordenada], a[cuerpo][step-1][coordenada]); 
  
  //Primer Paso
  ri[cuerpo][0][coordenada] = r[cuerpo][step-1][coordenada] + (h/2.0)*kr[0][coordenada];
  vi[cuerpo][0][coordenada] = v[cuerpo][step-1][coordenada] + (h/2.0)*kv[0][coordenada];
  hallar_aceleracion(kr, kv, m, n_cuerpos, step, n_coordenadas); //Nueva aceleracion

  kr[cuerpo][1][coordenada] = r_prime(ri[0][coordenada], vi[0][coordenada], a[cuerpo][step-1][coordenada]);
  kv[cuerpo][1][coordenada] = v_prime(ri[0][coordenada], vi[0][coordenada], a[cuerpo][step-1][coordenada]); 

  //Segundo paso  
  ri[cuerpo][1][coordenada] = r[cuerpo][step-1][coordenada] + (h/2.0)*kr[1][coordenada];
  vi[cuerpo][1][coordenada] = v[cuerpo][step-1][coordenada] + (h/2.0)*kv[1][coordenada];
   hallar_aceleracion(kr, kv, m, n_cuerpos, step, n_coordenadas); //Nueva aceleracion
  
  kr[cuerpo][2][coordenada] = r_prime(ri[1][coordenada], vi[1][coordenada], a[cuerpo][step-1][coordenada]);
  kv[cuerpo][2][coordenada] = v_prime(ri[1][coordenada], vi[1][coordenada], a[cuerpo][step-1][coordenada]); 
  
  //Tercer paso
  ri[cuerpo][2][coordenada] = r[cuerpo][step-1][coordenada] + h*kr[2][coordenada];
  vi[cuerpo][2][coordenada] = v[cuerpo][step-1][coordenada] + h*kv[2][coordenada];  
  hallar_aceleracion(kr, kv, m, n_cuerpos, step, n_coordenadas); //Nueva Aceleracion  

  kr[cuerpo][3][coordenada] = r_prime(ri[2][coordenada], vi[2][coordenada], a[cuerpo][step-1][coordenada]);
  kv[cuerpo][3][coordenada] = v_prime(ri[2][coordenada], vi[2][coordenada], a[cuerpo][step-1][coordenada]); 
  
  //Cuarto Paso
  average_kr[coordenada] = (1.0/6.0)*(kr[0][coordenada] + 2.0*kr[1][coordenada] + 2.0*kr[2][coordenada] + kr[3][coordenada]);
  average_kv[coordenada] = (1.0/6.0)*(kv[0][coordenada] + 2.0*kv[1][coordenada] + 2.0*kv[2][coordenada] + kv[3][coordenada]);
  
  r[cuerpo][step][coordenada] = r[cuerpo][step-1][coordenada] + (h*average_kr[coordenada]);
  v[cuerpo][step][coordenada] = v[cuerpo][step-1][coordenada] + (h*average_kv[coordenada]);

  hallar_aceleracion(r, v, m, n_cuerpos, step, n_coordenadas);
}
