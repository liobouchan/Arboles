#include <stdio.h>
#include <stdlib.h>
#include "arbolb.h"

/** Menú que se va usar en todo el programa 
 */
void Menu(){
  printf("\n\n====OPERACIONES ARBOL BINARIO======\n");
  printf("\n1)Recorridos\n");
  printf("\n2)Buscar\n");
  printf("\n3)Insertar nuevo nodo \n");
  printf("\n4)Modificar \n");
  printf("\n5)Eliminar \n");
  printf("\n6)SubArboles");
  printf("\n7)Altura de un arbol\n");
  printf("\n8)Alturas\n");
  printf("\n9)Tipo de NODO\n");
  printf("\n10)Máximo y Mínimo del Arbol");
  printf("\n11)Contar Nodos");
  printf("\n12)Salir\n");
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
    (*arbol) = temporal;
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

/** Recorrido Preorden */
int ContaNodos(Arbol* arbol,int contador){
  if(arbol){
    contador++;
      contador=ContaNodos(arbol->hijo_izquierdo,contador);
      contador=ContaNodos(arbol->hijo_derecho,contador);
  }
  return contador;
}

/** [Alturas description] */
void Alturas(Arbol* arbol){
  if(arbol){
    printf("ELEMENTO: %2c\n",arbol->elemento);
    printf("ALTURA: %d\n", (arbol->nivel)-1 );
    printf("Nivel:  %d\n", arbol->nivel );
    Alturas(arbol->hijo_izquierdo);
    Alturas(arbol->hijo_derecho);
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

Arbol* maximo(Arbol* t){
  if(t==NULL){
    printf("Arbol vacio \n");
    return NULL;
  }
  if(t->hijo_derecho==NULL){
    return t;
  }
  return maximo(t->hijo_derecho);
}

Arbol* minimo(Arbol* t){
  if(t==NULL){
    printf("Arbol vacio \n");
    return NULL;
  }
  if(t->hijo_izquierdo==NULL){
    return t;
  }
  return minimo(t->hijo_izquierdo);
}

Arbol* borrarNodo(Arbol** arbol, char e){
  Arbol* aux, **min, *aux2 , *aux3;
  if((*arbol)->elemento==e){
    aux=(*arbol);
    if((*arbol)->hijo_derecho != NULL ){
    aux3 = minimo(((*arbol)->hijo_derecho));
    min = &aux3;
    aux2 = *min;
    (*min) = (*min)->hijo_derecho;
    aux2->hijo_izquierdo = aux->hijo_izquierdo;
    aux2->hijo_derecho = aux->hijo_derecho;
    *arbol = aux2;
  }
  else{
    (*arbol) = (*arbol)->hijo_izquierdo;
    free(aux);
    return *arbol;
  }
  }

  if(e<(*arbol)->elemento){
    (*arbol)->hijo_izquierdo = borrarNodo(&((*arbol)->hijo_izquierdo),e);
  }else{
    (*arbol)->hijo_derecho = borrarNodo(&((*arbol)->hijo_derecho),e);
  }
  return *arbol;
}

ArbolBin* crearSubArbol(Arbol* nodoRaiz){
  ArbolBin *arbol=NULL;
  arbol=(ArbolBin *)malloc(sizeof(ArbolBin));
  arbol->raiz=nodoRaiz;
  arbol->contNodos=1;
  //arbol->tipo=NULL;
  return arbol;
}

int insertarNodo(Arbol**nA, Arbol* nuevo){
  if ((*nA)==NULL){
    (*nA)==nuevo;
    return 1;
  }
  if(nuevo->elemento==(*nA)->elemento){
    printf("El nodo ya existe. \n");
    return -1;
  }

  if(nuevo->elemento < (*nA)->elemento){
    return insertarNodo(&((*nA)->hijo_izquierdo),nuevo);
  }else{
    return insertarNodo(&((*nA)->hijo_derecho),nuevo);
  }
   

}

int modificarNodo(Arbol**nA ,Arbol*a,char e){
  if((*nA)==NULL){
    printf("Arbol vacio\n");
    return 0;
  }
  if((*nA)->elemento == e){
    printf("El elemento ya existe en otro nodo\n");
    return 0;
  }
  if (a->elemento ==(*nA)->elemento)  {
    (*nA)->elemento=e;
    return 1;
  }

  if(e<(*nA)->elemento){
    return modificarNodo(&((*nA)->hijo_izquierdo),a,e);
  }else{
    return modificarNodo(&((*nA)->hijo_derecho),a,e);
  }


}

void menuSub(){
  printf("\n\nSubArbol Binario\n");
  printf("\n1)Recorridos\n");
  
  printf("\n2)Alturas \n");
  printf("\n3)Conteo \n");
  printf("\n4)Regresar al menu anterior \n");
}

int tipo(Arbol* raiz, Arbol*nodo){
  if(raiz->elemento == nodo->elemento){
    return 1;
  }

  if(nodo->hijo_izquierdo ==NULL && nodo->hijo_derecho==NULL){
    return 2;
  }else{
    return 3;
  }

}

Arbol* crearNodo(int nivel,char e){
  Arbol *temporal = NULL;
  temporal = (Arbol *)malloc(sizeof(Arbol));
  temporal->hijo_izquierdo = NULL;
  temporal->hijo_derecho = NULL;
  temporal->elemento = e;
  temporal->nivel = nivel;
  return temporal;
}