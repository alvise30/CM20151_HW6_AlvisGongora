#include <stdio.h>
#include <math.h>
#include "functions.h"

int rungekutta_step(int i, double *x,double *y,double *t, double h)
{
	double kx1 = x_prime(x[i-1],y[i-1]);
	double ky1 = y_prime(x[i-1],y[i-1]);
	
 	// first step
	double t1 = t[i-1] + (h/2.0);
	double x1 = x[i-1] + (h/2.0) * kx1;
	double y1 = y[i-1] + (h/2.0) * ky1;
	
	double kx2 = x_prime(x1, y1);
	double ky2 = y_prime(x1, y1);
	
	// second step
	double t2 = t[i-1] + (h/2.0);
	double x2 = x[i-1] + (h/2.0) * kx2;
	double y2 = y[i-1] + (h/2.0) * ky2;
	
	double kx3 = x_prime(x2, y2);
	double ky3 = y_prime(x2, y2);
		      
	// third step
 	double t3 = t[i-1] + h;
  	double x3 = x[i-1] + h * kx3;
  	double y3 = y[i-1] + h * ky3;
  	
  	double kx4 = x_prime(x3, y3);
  	double ky4 = y_prime(x3, y3);
  	
  	// fourth step
 	double average_kx = (1.0/6.0)*(kx1 + 2.0*kx2 + 2.0*kx3 + kx4);
 	double average_ky = (1.0/6.0)*(ky1 + 2.0*ky2 + 2.0*ky3 + ky4);
 	
  	t[i] = t[i-1] + h;
   	x[i] = x[i-1] + h * average_kx;
   	y[i] = y[i-1] + h * average_ky;
}   	
