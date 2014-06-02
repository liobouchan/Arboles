#include <stdio.h>
#include <stdlib.h>
//Incluimos el archivo cabecera
#include "arbolb.h"

void main(){
  //Declaramos las variables que vallamos a utilizar
  Arbol *arbol;
  Arbol *temporal;
  char elemento;
  int opcion, nivel = 1;
  arbol = NULL;
  FILE *cfPtr;

  /*Abrimos el archivo TXT donde se encuentran las letras que van a entrar
   * en el arbol, leemos el archivo e insertamos nodo por nodo
   */
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

  do{
    //Desplegamos el Menú
    Menu();
    scanf("%d" , &opcion);
    switch( opcion ){
      case 1:
      //Esta opcion nos muestra todos los recorridos 
      printf("\nPREORDEN:\n\n");
      Preorden(arbol);

      printf("\n\nINORDEN:\n\n");
      Inorden(arbol);

      printf("\n\nPOSTORDEN:\n\n");
      Postorden(arbol);

      printf("\n\n");
      break;
      
      case 2:
        /*Buscamos si existe un elementro y muestra:
          nivel
          Hijos
          Camino para llegar a dicho punto
        */
        printf("\nELEMENTO A BUSCAR:");
        scanf(" %c", &elemento);
        temporal = Buscar(arbol,elemento);
      
      if(temporal){
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
      /** 
       * Determina la altura del arbol
       */
        printf("\nAltura: %d", altura(arbol , nivel));
      break;
    }
  }while(opcion != 4);
}