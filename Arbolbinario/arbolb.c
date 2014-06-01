#include <stdio.h>
#include <stdlib.h>
#include "arbolb.h"

void Menu(){
	printf("\n\nARBOL BINARIO\n");
	printf("\n1)RECORRIDO\n");
	printf("\n2)BUSCAR\n");
	printf("\n3)SALIR\n");
}
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
void Preorder(Arbol* arbol){
    if (arbol){
        printf("%2c",arbol->elemento);
        Preorder(arbol->hijo_izquierdo);
        Preorder(arbol->hijo_derecho);
    }
}
void Inorder(Arbol* arbol){
    if (arbol){
        Inorder(arbol->hijo_izquierdo);
        printf("%2c",arbol->elemento);
        Inorder(arbol->hijo_derecho);
    }
}
void Postorder(Arbol* arbol){
    if (arbol){
        Postorder(arbol->hijo_izquierdo);
        Postorder(arbol->hijo_derecho);
        printf("%2c",arbol->elemento);
    }
}
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
