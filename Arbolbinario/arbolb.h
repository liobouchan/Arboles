#ifndef ARBOLB_H
#define ARBOLB_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Arbol{
	char elemento;
	int nivel;
	struct Arbol* hijo_derecho;
	struct Arbol* hijo_izquierdo;
}Arbol;

void Menu(); 
void Leernodo(Arbol* arbol, char elemento);
void Insertar(Arbol ** arbol, char elemento, int nivel);
char Padre(Arbol* arbol, char elemento);
void Hijo_derecho(Arbol* arbol, char elemento);
void Hijo_izquierdo(Arbol* arbol, char elemento);
void Preorden(Arbol* arbol);
void Inorden(Arbol* arbol);
void Postorden(Arbol* arbol);
void Camino(Arbol* arbol, char elemento);
Arbol* Buscar(Arbol* arbol, char elemento);

#endif
