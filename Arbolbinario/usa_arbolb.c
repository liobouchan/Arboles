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
	
	fopen("arbol3.txt", "r");
	if ((cfPtr = fopen("arbol3.txt", "r")) == NULL)
		printf("\aEL ARCHIVO NO EXISTE\n");
	else{
		while(!feof(cfPtr)){
			fscanf(cfPtr,"%c", &elemento);
			if(isalpha(elemento))//Un valor distinto de cero (es decir, verdadera ) si es que c es una letra alfabética. Zero (es decir, falsa ) de otra manera.
            //Comprueba si c . es un carácter alfabético cuenta que lo que se considera una carta depende de la configuración regional que se utiliza.
				Insertar(&arbol, elemento, nivel);
			elemento = '\0';
			
		}
		fclose(cfPtr);
	}
	
	do{
		Menu();
		printf("\n\nQUE OPCION DESEA:");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				printf("\nPREORDEN:\n\n");
				Preorder(arbol);

				printf("\n\nINORDEN:\n\n");
				Inorder(arbol);

				printf("\n\nPOSTORDEN:\n\n");
				Postorder(arbol);
				
				printf("\n\n");
				break;
		    case 2:
				printf("\nELEMENTO A BUSCAR:");
				scanf(" %c", &elemento);
				temporal = Buscar(arbol,elemento);
				if (temporal){
					printf("\nSE ENCONTRO AL ELEMENTO: %c\n", temporal->elemento);
					printf("\nCAMINO: "); Camino(arbol, elemento);
					printf("\nNIVEL: %d", temporal->nivel);
					printf("\nPADRE: %c", Padre(arbol, elemento));
					Leernodo(arbol, elemento);
					printf("\n\n");
				}
				else
					printf("NO EXISTE.\n\n");
				break;
			case 3:
				break;
			default:
				printf("\aUNA DE LAS TRES OPCIONES.");
				break;
		}
	}while(opcion != 3);
    
}
