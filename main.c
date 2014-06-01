#include <stdio.h>
#include <stdlib.h>
#include "arbolb.h"

void main(){
  Arbol *arbol;
  Arbol *temporal;
  char elemento;
  int opcion, nivel = 1;
  arbol = NULL;
  FILE *cfPtr;

  fopen("arbol.txt", "r");
  if ((cfPtr = fopen("arbol.txt", "r")) == NULL)
    printf("\aEL ARCHIVO NO EXISTE\n");
  else{
    while(!feof(cfPtr)){
      fscanf(cfPtr,"%c", &elemento);
      if(isalpha(elemento))//Un valor distinto de cero (es decir, verdadera ) si es que c es una letra alfabética. Zero (es decir, falsa ) de otra manera.
        Insertar(&arbol, elemento, nivel);
        elemento = '\0';
    }
    fclose(cfPtr);
  }
}