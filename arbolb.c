#include <stdio.h>
#include <stdlib.h>
#include "arbolb.h"

/** Menú que se va usar en todo el programa 
 */
void Menu(){
  printf("\n\n====OPERACIONES ARBOL BINARIO======\n");
  printf("\n1)Recorridos\n");
  printf("\n2)Buscar\n");
  printf("\n3)Altura del Arbol\n");
  printf("\n4)Salir\n");
}

/** Crea un arbol temporal inicializando los hijos y
 *  asignando el nivel a dicho arbol, cada que se agrega un nodo
 *  se hace +1 en el nivel.
 */
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

/** Recorrido Preorden */
void Preorden(Arbol* arbol){
  if(arbol){
    printf("%2c",arbol->elemento);
    Preorden(arbol->hijo_izquierdo);
    Preorden(arbol->hijo_derecho);
  }
}

/** Recorrido Inordern */
void Inorden(Arbol* arbol){
  if(arbol){
    Inorden(arbol->hijo_izquierdo);
    printf("%2c",arbol->elemento);
    Inorden(arbol->hijo_derecho);
  }
}

/** Recorrido de PostOrden */
void Postorden(Arbol* arbol){
  if(arbol){
    Postorden(arbol->hijo_izquierdo);
    Postorden(arbol->hijo_derecho);
    printf("%2c",arbol->elemento);
  }
}

/** Compara con el elemento enviado hasta buscar que el nodo coincida
 * Y así regresar el valor de padre 
 */
char Padre(Arbol* arbol, char elemento){
  char aux = '\0';
  int x;
  do{
    if(elemento < arbol->elemento){
      aux = arbol->elemento;
      arbol = arbol->hijo_izquierdo, elemento;
  }
  else if(elemento > arbol->elemento){
    aux = arbol->elemento;
    arbol = arbol->hijo_derecho;
  }
  else if(elemento == arbol->elemento)
    return x=(int)aux;
  }while(arbol);
}

/** Muestra el valor del hijo derecho del nodo a buscar */
void Hijo_derecho(Arbol* arbol, char elemento){
  if(elemento < arbol->elemento)
    Hijo_derecho(arbol->hijo_izquierdo, elemento);
  else if(elemento > arbol->elemento)
    Hijo_derecho(arbol->hijo_derecho, elemento);
  else if(elemento == arbol->elemento)
    if(arbol->hijo_derecho == NULL)
      printf("\nHIJO DERECHO: (null)");
    else
      printf("\nHIJO DERECHO: %c", arbol->hijo_derecho->elemento);
}

/** Muestra el valor del hijo izquierdo */
void Hijo_izquierdo(Arbol* arbol, char elemento){
  if(elemento < arbol->elemento)
    Hijo_izquierdo(arbol->hijo_izquierdo, elemento);
  else if(elemento > arbol->elemento)
    Hijo_izquierdo(arbol->hijo_derecho, elemento);
  else if(elemento == arbol->elemento)
    if(arbol->hijo_izquierdo == NULL)
      printf("\nHIJO IZQUIERDO: (null)");
    else
      printf("\nHIJO IZQUIERDO: %c", arbol->hijo_izquierdo->elemento);
}

/** Muestra el camino de acuerdo a arboles binarios
 *  por donde va pasando lo va imprimiendo hasta llegar 
 *  a donde tiene que llegar 
 */
void Camino(Arbol* arbol, char elemento){
  if(elemento < arbol->elemento){
    printf("%c", arbol->elemento);
    Camino(arbol->hijo_izquierdo, elemento);
  }
  else if(elemento > arbol->elemento){
    printf("%c", arbol->elemento);
    Camino(arbol->hijo_derecho, elemento);
  }
  else if(elemento == arbol->elemento)
    printf("%c", arbol->elemento);
}

/** Busca un nodo y recorre hasta que el valor dado
 * es encontrado
 */
Arbol* Buscar(Arbol* arbol, char elemento){
  if(!arbol)
    return NULL;
  if(elemento < arbol->elemento)
    Buscar(arbol->hijo_izquierdo, elemento);
  else if(elemento > arbol->elemento)
    Buscar(arbol->hijo_derecho, elemento);
  else if(elemento == arbol->elemento)
    return arbol;
}

/** Lee el hijo izquierdo y derecho del nodo en que está posicionado */
void Leernodo(Arbol* arbol, char elemento){
  if(elemento < arbol->elemento)
    Leernodo(arbol->hijo_izquierdo, elemento);
  else if(elemento > arbol->elemento)
    Leernodo(arbol->hijo_derecho, elemento);
  else if(elemento == arbol->elemento){
    Hijo_izquierdo(arbol, elemento);
    Hijo_derecho(arbol, elemento);
  }
}

/** Recorre hasta el último hijo izq y derecho
 *  los compara y agarra el mayor para mostrarlo
 *  de acuerdo a la formula de altura de un arbol.
 */
int altura (Arbol *arbol , int nivel) {
  if(!arbol)
    return 0;
  else {
    int alturaI;
    int alturaD;
    
    alturaI = altura (arbol -> hijo_izquierdo,nivel);
    alturaD = altura (arbol -> hijo_derecho,nivel);
    
    if(alturaI > alturaD) 
      return alturaI + 1;
    else
      return alturaD + 1;
  }
}