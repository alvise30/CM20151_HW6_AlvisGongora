#include <stdio.h>
#include <math.h>
#include "functions.h"

int rungekutta_step(int cuerpo, int step, int coordenada, float ***r, float ***v, float ***a, float *t, float h){

a = a[cuerpo][step-1][coordenada]
  float kr1 = fun_r(dt, r[cuerpo][step-1][coordenada], v[cuerpo][step-1][coordenada]);
  float kv1 = fun_v(dt, v[cuerpo][step-1][coordenada], a);
 
  // first step
  double t1 = t[step-1] + (h/2.0);
  double r1 = r[cuerpo][step-1][coordenada] + (h/2.0) * kr1;
  double v1 = v[cuerpo][step-1][coordenada] + (h/2.0) * kv1;
  
  double kr2 = fun_r(dt, r1, v1);
  double kv2 = fun_v(dt, v1, a);
  
  // second step
  double t2 = t[step-1] + (h/2.0);
  double x2 = r[cuerpo][step-1][coordenada] + (h/2.0) * kr2;
  double y2 = v[cuerpo][step-1][coordenada] + (h/2.0) * kv2;
  
  double kx3 = fun_r(dt, r2, v2);
  double ky3 = fun_y(dt, v2, a);
  
  // third step
  double t3 = t[step-1] + h;
  double x3 = r[cuerpo][step-1][coordenada] + h * kr3;
  double y3 = v[cuerpo][step-1][coordenada] + h * kv3;
  
  double kx4 = fun_r(dt, r3, v3);
  double ky4 = fun_v(dt, v3, a);
  
  // fourth step
  double average_kr = (1.0/6.0)*(kr1 + 2.0*kr2 + 2.0*kr3 + kr4);
  double average_kv = (1.0/6.0)*(kv1 + 2.0*kv2 + 2.0*kv3 + kv4);
  
  t[i] = t[step-1] + h;
  r[i] = r[cuerpo][step-1][coordenada] + h * average_kr;
  v[i] = v[cuerpo][step-1][coordenada] + h * average_kv;
}   	
