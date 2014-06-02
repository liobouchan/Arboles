#ifndef ARBOLB_H
#define ARBOLB_H
#include <stdio.h>
#include <stdlib.h>

/** Struct a utilizar */
typedef struct Arbol{
  char elemento;
  int nivel;
  struct Arbol* hijo_derecho;
  struct Arbol* hijo_izquierdo;
}Arbol;
typedef struct {
	Arbol *raiz;
	int contNodos;
	char tipo[100];
}ArbolBin;

void Menu(); 
void Insertar(Arbol ** arbol, char elemento, int nivel);
void Preorden(Arbol* arbol);
void Inorden(Arbol* arbol);
void Postorden(Arbol* arbol);
void Leernodo(Arbol* arbol, char elemento);
char Padre(Arbol* arbol, char elemento);
void Hijo_derecho(Arbol* arbol, char elemento);
void Hijo_izquierdo(Arbol* arbol, char elemento);
void Camino(Arbol* arbol, char elemento);
Arbol* Buscar(Arbol* arbol, char elemento);
Arbol* maximo(Arbol* t);
Arbol* minimo(Arbol* t);
int borrarNodo(Arbol** nA, char e);
ArbolBin* crearSubArbol(Arbol* nodoRaiz);
int insertarNodo(Arbol**nA, Arbol* nuevo);
int modificarNodo(Arbol**nA ,Arbol*a,char e);
void menuSub();
Arbol* crearNodo(int nivel,char e);


#endif
