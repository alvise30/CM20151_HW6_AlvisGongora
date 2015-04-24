#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h" //Funciones para integrar
#include "runge-kutta.h" //Metodo de Runge-Kutta de cuarto orden
#include "shellscrip.h" // Para leer el archivo tidy de forma mas sencilla

/*Constantes*/
#define G 39.486 //Unidades¿?


float * get_memory(int n_cuerpos);
float *** get_memory3(int n_cuerpos, int n_steps, int n_coordenadas);
void hallar_aceleracion(float **r, float **a, float *m, int n_cuerpos, int step, int n_coordenadas);
void print_status_on_document(float **r, int n_cuerpos, int step, int n_coordenadas);
void free_memory(float ***arreglo, int n_cuerpos, int n_steps, int n_coordenadas);

/*Main*/
int main(int argc, char **argv){

  /*Posiciones de todos los astros*/
  float ***r; 
  /*Velocidades de todos los astros*/
  float ***v;
  /*Aceleraciones de todos los astros*/
  float ***a;
  /*Masas de tod0s los astros*/
  float *m;
  /*Coordenada temporal*/
  float *t;

  /*timesstep variables--¿?*/
  float dt = 0.001; //lo defino yo¿?
  int n_steps = (int)(100.0/dt); //¿?
  int n_cuerpos = 4;
  int n_coordenadas = 3;
  int i,j,k;

  /*Asignacion de memoria*/
  r = get_memory3(n_cuerpos, n_steps, n_coordenadas);
  v = get_memory3(n_cuerpos, n_steps, n_coordenadas);
  a = get_memory3(n_cuerpos, n_steps, n_coordenadas);
  m = get_memory(n_cuerpos);
  t = get_memory(n_steps);

  /*Condiciones iniciales*/
  //INCONCLUSO
  /*
  //Cargar datos del archivo ic.txt
  float a;
  FILE *readfile;
  readfile = fopen('icb.tzt', 'wr');
  fscanf(readfile,%d, &a)

  fclose(readfile);
  */

  /*Condiciones iniciales a mano*/
  //Pongo todo en 0
  for (i=0;i<n_cuerpos;i++){
    for(j=0;j<n_coordenadas;j++){
      r[i][0][j] = 0.0;
      v[i][0][j] = 0.0;
    }
  }
  //Cambio las diferentes de 0
  r[0][0][0] = 1.0;
  r[2][0][0] = 1.0026;
  r[3][0][0] = 1.0;
  r[3][0][1] = 0.0963;
  v[0][0][1] = 30;
  v[2][0][1] = 1.023;
  v[3][0][0] = 1570;
  v[3][0][2] = 29959;

  m[1] = 1;
  m[0] = 3.003*(pow(10,-6));
  m[2] = 3.695*(pow(10,-8));
  m[3] = 5*(pow(10,-11));

  /*Integracion Runge-Kutta cuarto orden*/
  for(i=0;i<n_steps;i++){
    hallar_aceleracion(r, a, m, n_cuerpos, i, n_coordenadas);
    for(j=0;j<n_cuerpos;j++){
      for(k=0;j<n_coordenadas;k++){
      //Aqui se integra
	rungekutta_step(j, i, k, r, v, a, t, h);
      }
    }
    /*Imprimir las posiciones en el documento*/
    print_status_on_document(r, n_cuerpos, i, n_coordenadas);
  }
  
  /*Liberacion de memoria*/
  r = free_memory(n_cuerpos, n_steps, n_coordenadas);
  v = free_memory(n_cuerpos, n_steps, n_coordenadas);
  a = free_memory(n_cuerpos, n_steps, n_coordenadas);
  free(m);
  free(t);
  
  return 0
}
/*==============================================FIN MAIN=========================================================*/



/*----------------------------------------------Funciones-------------------------------------------------------*/

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

/*Asignacion de memoria 1 dimension*/
float * get_memory(int n_cuerpos){
  float *x;
  if(!(x = malloc(sizeof(float)*n_cuerpos))){
    printf("error en la asignacion de memoria");
    exit(1);
  }
  return x;
}

/*Asignacion de memoria en 3 dimensiones*/
float *** get_memory3(int n_cuerpos, int n_steps, int n_coordenadas){
  float ***x;
  if(!(x = malloc(sizeof(float**)*n_cuerpos))){
    printf("error en la asignacion de memoria");
  }
  for(i=0; i<n_steps; i++){
    if(!(x[i] = malloc(sizeof(float*)*n_coordenadas))){
      printf("error en la asignacion de memoria");
    }
    for(j=0;j<n_coordenadas;j++){
      if(!(x[i][j] = malloc(sizeof(float)*n_coordenadas))){
	printf("error en la asignacion de memoria");
      }
    }
  }
  return x;
}

/*Liberar memoria*/
void free_memory(float ***arreglo, int n_cuerpos, int n_steps, int n_coordenadas){
  int i,j;
  for(i=0;i<n_coordenadas;i++){
    for(j=0;j<n_steps;j++){
      free(x[i][j]);
    }
    free(x[i]);
  }
  free(x);
}


/*Imprimir  archivo*/
//INCOMPLETO
void print_status_on_document(float **r, int n_cuerpos, int step, int n_coordenadas){
  int i,j;
  for(i=0;i<n_cuerpos;i++){
    for(j=0;j<n_coordenadas;j++){
      printf("%f\t",r[i][step][j]);
    }
  }
  printf("\n");
}
