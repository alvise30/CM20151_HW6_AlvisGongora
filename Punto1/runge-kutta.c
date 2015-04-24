#include <stdio.h>
#include <math.h>
#include "functions.o"

int rungekutta_step(int cuerpo, int step, int coordenada, float ***r, float ***v, float ***a, float *t, float h){

  a = a[cuerpo][step-1][coordenada];
  float kr1[coordenada] = r_prime(r, v, a, cuerpo, (step-1), coordenada);
  float kv1[coordenada] = fun_v(dt, v[cuerpo][step-1][coordenada], a);
  
  // first step
  float t1[coordenada] = t[step-1] + (h/2.0);
  float r1[coordenada] = r[cuerpo][step-1][coordenada] + (h/2.0) * kr1;
  float v1[coordenada] = v[cuerpo][step-1][coordenada] + (h/2.0) * kv1;
  
  float kr2[coordenada] = fun_r(dt, r1, v1);
  float kv2[coordenada] = fun_v(dt, v1, a1);

  // second step
  float t2 = t[step-1] + (h/2.0);
  float r2 = r[cuerpo][step-1][coordenada] + (h/2.0) * kr2;
  float v2 = v[cuerpo][step-1][coordenada] + (h/2.0) * kv2;
  float a2 = v[cuerpo][step-1][coordenada] + (h/2.0) * ka2;  
  
  float kr3 = fun_r(dt, r2, v2);
  float kv3 = fun_y(dt, v2, a2);
  float ka3 = hallar_aceleracion(r, a, m, n_cuerpos, step, n_coordenadas);

  // third step
  float t3 = t[step-1] + h;
  float r3 = r[cuerpo][step-1][coordenada] + h * kr3;
  float v3 = v[cuerpo][step-1][coordenada] + h * kv3;
  float a3 = v[cuerpo][step-1][coordenada] + h * a2;

  float kr4 = fun_r(dt, r3, v3);
  float kv4 = fun_v(dt, v3, a3);
  
  // fourth step
  float average_kr = (1.0/6.0)*(kr1 + 2.0*kr2 + 2.0*kr3 + kr4);
  float average_kv = (1.0/6.0)*(kv1 + 2.0*kv2 + 2.0*kv3 + kv4);
  
  t[i] = t[step-1] + h;
  r[i] = r[cuerpo][step-1][coordenada] + h * average_kr;
  v[i] = v[cuerpo][step-1][coordenada] + h * average_kv;
}   	
