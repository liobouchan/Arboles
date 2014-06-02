#include <stdio.h>
#include <stdlib.h>
#include "arbolb.h"

void main(){
  //Declaramos las variables que vallamos a utilizar
  Arbol *arbol;
  Arbol *temporal;
  ArbolBin* subarbol;
  char elemento;
  int val;
  char e , n , sub;
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
    setbuf(stdin,NULL);
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
        //char e;
        printf("Escriba el valor del elemento\n");
        scanf("%c",&e);
        setbuf(stdin,NULL);
        temporal=crearNodo(nivel,e);
        Insertar(&arbol , e , nivel);
      break;

      case 4:
        //char e,n;
        printf("Escriba el elemento que desea modificar\n");
        scanf("%c",&e);
        setbuf(stdin,NULL);
        temporal=Buscar(arbol,e);
        if(temporal==NULL){
          printf("El nodo no existe\n");
        }else{
          printf("Escriba el nuevo valor\n");
          fflush(stdin);
          setbuf(stdin,NULL);
          scanf(" %c",&n);
          if(modificarNodo(&arbol,temporal,n)==1){
            printf("Nodo modificado con exito\n");
          }
        }
      break;

      case 5:
        //char e;
        printf("Escriba el valor del elemento a elminar\n");
        scanf("%c",&e);
        setbuf(stdin,NULL);
        if(borrarNodo(&arbol,e)==1){
          printf("Nodo eliminado con exito\n");
        }
      break;

      case 6:
        system("clear");
        //char sub;
        printf("Escriba el elemento del nodo raiz del subarbol\n");
        scanf("%c",&sub);
        setbuf(stdin,NULL);
        subarbol=(ArbolBin*)malloc(sizeof(ArbolBin));
        subarbol->raiz=Buscar(arbol,sub);
        subarbol->contNodos=0;
        //subarbol->tipo=NULL;
        if(subarbol->raiz !=NULL){
          do{          
            menuSub();
            scanf("%d" , &opcion);
            switch( opcion ){
              case 1:
              //Esta opcion nos muestra todos los recorridos 
              printf("\nPREORDEN:\n\n");
              Preorden(subarbol->raiz);

              printf("\n\nINORDEN:\n\n");
              Inorden(subarbol->raiz);

              printf("\n\nPOSTORDEN:\n\n");
              Postorden(subarbol->raiz);

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
                temporal = Buscar(subarbol->raiz,elemento);
              
              if(temporal){
                printf("\nSE ENCONTRO AL ELEMENTO: %c\n", temporal->elemento);
                printf("\nCAMINO: "); Camino(subarbol->raiz, elemento);
                printf("\nNIVEL: %d", temporal->nivel);
                printf("\nPADRE: %c", Padre(subarbol->raiz, elemento));
                Leernodo(subarbol->raiz, elemento);
                printf("\n\n");
              }
              else
                printf("NO EXISTE.\n\n");
             break;
             case 3:
              ////char e;
              printf("Escriba el valor del elemento\n");
              scanf("%c",&e);
              setbuf(stdin,NULL);
              temporal=crearNodo(nivel,e);
              if (insertarNodo(&(subarbol->raiz),temporal)==1){
                printf("Nodo insertado con exito\n");
              }

             break;
             case 4:
                //char e,n;
                printf("Escriba el elemento que desea modificar\n");
                scanf("%c",&e);
                setbuf(stdin,NULL);
                temporal=Buscar(subarbol->raiz,e);
                if(temporal==NULL){
                  printf("El nodo no existe\n");
                }else{
                  printf("Escriba el nuevo valor\n");
                  scanf("%c",&n);
                  setbuf(stdin,NULL);
                  if(modificarNodo(&(subarbol->raiz),temporal,n)==1){
                    printf("Nodo modificado con exito\n");
                  }
                }

              break;
              case 5:
                //char e;
                printf("Escriba el valor del elemento a elminar\n");
                  scanf("%c",&e);
                  setbuf(stdin,NULL);
                  if(borrarNodo(&(subarbol->raiz),e)==1){
                    printf("Nodo eliminado con exito\n");
                  }
                break;
              case 6:
                printf("\nAltura: %d", altura(subarbol->raiz , nivel));
              break;

            }
          }while(opcion<=6);
        }else{
          printf("El nodo no existe\n");
        }
        
      break;
      case 7:
      /** 
       * Determina la altura del arbol
       */
        printf("\nAltura: %d", altura(arbol , nivel));
      break;
      case 8:
        printf("\nLa Altura de cada nodo es : \n");
        Alturas(arbol);
      break;
      case 9:
        printf("Escribe el elemnto\n");
        scanf("%c",&e);
        temporal=Buscar(arbol,e);
        if(temporal==NULL){
          printf("EL nodo no existe\n");
        }else{
          val=tipo(arbol,temporal);
          if(val==1){
            printf("El nodo es raiz \n");
          }
          if (val==2){
            printf("El nodo es hoja\n");
          }
          if (val==3){
           printf("El nodo es interno\n");
          }
        }
      break;
      case 10:
        temporal=maximo(arbol);
        printf("El valor maximo del arbol es: %c\n", temporal->elemento);
        temporal=minimo(arbol);
        printf("El valor minimo del arbol es: %c\n",temporal->elemento );
      break;
    }
  }while(opcion <= 10);
}
