#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fun_r(int dt, float r, float v){
  return r + (dt*v);
}

float fun_v(int dt, float v, float a){
  return v + (dt*a);
}
