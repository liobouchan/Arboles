#include <stdio.h>
#include <stdlib.h>
#include "arbolb.h"

void Menu(){
  printf("\n\nArbol Binario\n");
  printf("\n1)Recorridos\n");
  printf("\n2)Buscar\n");
  printf("\n3)Salir\n");
}

void Insertar(Arbol ** arbol, char elemento, int nivel){
  Arbol *temporal = NULL;
  if(!(*arbol)){
    temporal = (Arbol *)malloc(sizeof(Arbol));
    temporal->hijo_izquierdo = temporal->hijo_derecho = NULL;
    temporal->elemento = elemento;
    temporal->nivel = nivel;
    *arbol = temporal;
    return;
  }

  if(elemento < (*arbol)->elemento){
    nivel++;
    Insertar(&(*arbol)->hijo_izquierdo, elemento, nivel);
  }
  else if(elemento > (*arbol)->elemento){
    nivel++;
    Insertar(&(*arbol)->hijo_derecho, elemento, nivel);
  } 
  else if(elemento == (*arbol)->elemento)
    return;
}