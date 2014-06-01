#include <stdio.h>
#include <stdlib.h>

/**MORALES BAEZ ALAN ANDREW Grupo: 1CV6**/
struct Nodo {
	char dato;
	struct Nodo *hijo_derecho;
	struct Nodo *hijo_izquierdo;
};

struct Nodo *CreaNodo(char dato1);
char Insertar(struct Nodo *ptrRaiz, char dato);
struct Nodo *UnirArbol(struct Nodo *izq, struct Nodo *der);
void elimina(struct Nodo **ptrRaiz, char dato1);
void PreOrden(struct Nodo *ptrRaiz);
void Inorden(struct Nodo *ptrRaiz);
void PostOrden(struct Nodo *ptrRaiz);
int  altura(struct Nodo *ptrRaiz);
void RotacionIzq(struct Nodo ** ptrPadre);
void RotacionDer(struct Nodo ** ptrPadre);
void Balanceo(struct Nodo **ptrRaiz);

void Camino(struct Nodo* ptrRaiz, char dato){
	if(dato < ptrRaiz->dato){
		printf("%c", ptrRaiz->dato);
		Camino(ptrRaiz->hijo_izquierdo, dato);
    }
	else if(dato > ptrRaiz->dato){
		printf("%c", ptrRaiz->dato);
        Camino(ptrRaiz->hijo_derecho, dato);
	}
	else if(dato == ptrRaiz->dato)
		printf("%c", ptrRaiz->dato);
}


char Padre(struct Nodo* ptrRaiz, char dato){
	char aux = 0;
			
	do{
		if(dato < ptrRaiz->dato){
			aux = ptrRaiz->dato;
			ptrRaiz = ptrRaiz->hijo_izquierdo;
		}
		else if(dato > ptrRaiz->dato){
			aux = ptrRaiz->dato;
			ptrRaiz = ptrRaiz->hijo_derecho;
		}
		else if(dato == ptrRaiz->dato)
			return aux;
	}while(ptrRaiz);
}


void Hijoderecho(struct Nodo* ptrRaiz, char dato){
			
	if(dato < ptrRaiz->dato)
		Hijoderecho(ptrRaiz->hijo_izquierdo, dato);
    
	else if(dato > ptrRaiz->dato)
        Hijoderecho(ptrRaiz->hijo_derecho, dato);
		
	else if(dato == ptrRaiz->dato)
		if(ptrRaiz->hijo_derecho == NULL)
			printf("\nHIJO_DERECHO: (null)");
		else
			printf("\nHIJO_DERECHO: %c", ptrRaiz->hijo_derecho->dato);
}


void Hijoizquierdo(struct Nodo* ptrRaiz, char dato){
		
	if(dato < ptrRaiz->dato)
		Hijoizquierdo(ptrRaiz->hijo_izquierdo, dato);
    
	else if(dato > ptrRaiz->dato)
        Hijoizquierdo(ptrRaiz->hijo_derecho, dato);
		
	else if(dato == ptrRaiz->dato)
		if(ptrRaiz->hijo_izquierdo == NULL)
			printf("\nHIJO_IZQUIERDO: (null)");
		else
			printf("\nHIJO_IZQUIERDO: %c", ptrRaiz->hijo_izquierdo->dato);
}


void ReadNode(struct Nodo* ptrRaiz, char dato){
	if(dato < ptrRaiz->dato)
		ReadNode(ptrRaiz->hijo_izquierdo, dato);
    
	else if(dato > ptrRaiz->dato)
        ReadNode(ptrRaiz->hijo_derecho, dato);
		
	else if(dato == ptrRaiz->dato){
		Hijoizquierdo(ptrRaiz, dato);
		Hijoderecho(ptrRaiz, dato);
	}
}

struct Nodo* Busqueda(struct Nodo *ptrRaiz, char dato){
    
    if(dato < ptrRaiz->dato)
		Busqueda(ptrRaiz->hijo_izquierdo, dato);
    
	else if(dato > ptrRaiz->dato)
        Busqueda(ptrRaiz->hijo_derecho, dato);
    
	else if(dato == ptrRaiz->dato)
		return ptrRaiz;
}


struct Nodo *CreaNodo(char dato1) { 
	struct Nodo *ptrAux;
	ptrAux = (struct Nodo*) malloc(sizeof(struct Nodo));
	ptrAux -> dato = dato1;
	ptrAux -> hijo_derecho = NULL;
	ptrAux -> hijo_izquierdo = NULL;
	return ptrAux;
}

char Insertar(struct Nodo *ptrRaiz, char dato) { 
	struct Nodo *Nuevo;
	Nuevo = CreaNodo(dato);
	while(1){
		if(Nuevo -> dato < ptrRaiz -> dato) {
			if(ptrRaiz -> hijo_izquierdo == NULL) {
				ptrRaiz -> hijo_izquierdo = Nuevo;
				return 0;
			}
			else {
				ptrRaiz = ptrRaiz -> hijo_izquierdo;
			}
		}
		else if(Nuevo -> dato > ptrRaiz -> dato){
			if(ptrRaiz -> hijo_derecho == NULL) {
				ptrRaiz -> hijo_derecho = Nuevo;
				return 0;
			}
			else {
				ptrRaiz = ptrRaiz -> hijo_derecho;
			}			
		}
		else
			return 0;
	}
}

struct Nodo *UnirArbol(struct Nodo *izq, struct Nodo *der) { //Enlaza los nodos del árbol
    if(izq == NULL) 
		return der;
    if(der == NULL) 
		return izq;
    struct Nodo *centro = UnirArbol(izq -> hijo_derecho, der -> hijo_izquierdo);
    izq -> hijo_derecho = centro;
    der -> hijo_izquierdo = izq;
    return der;
}


void elimina(struct Nodo **ptrRaiz, char dato1) { 
	if(ptrRaiz != NULL) {
    	if(dato1 < (*ptrRaiz) -> dato)
        	elimina(&((*ptrRaiz) -> hijo_izquierdo), dato1);
    	else {
     		if(dato1 > (*ptrRaiz) -> dato)
         		elimina(&((*ptrRaiz) -> hijo_derecho), dato1);
    		else {
         		struct Nodo *ptrAux = *ptrRaiz;
         		*ptrRaiz = UnirArbol(((*ptrRaiz) -> hijo_izquierdo), ((*ptrRaiz) -> hijo_derecho));
     		}
    	}
	}
	else
		return;
}


void PreOrden(struct Nodo *ptr) { 
	if(ptr != NULL)
	{
		printf("%2c " , ptr->dato);
		PreOrden(ptr -> hijo_izquierdo);
		PreOrden(ptr -> hijo_derecho);
	}
}


void PostOrden(struct Nodo *ptr) {  
	if(ptr != NULL)
	{
		PostOrden(ptr -> hijo_izquierdo);
		PostOrden(ptr -> hijo_derecho);
		printf("%2c" , ptr -> dato);
	}
}


void Inorden(struct Nodo *ptr) { 
	if(ptr != NULL)
	{	
		Inorden(ptr->hijo_izquierdo);
		printf("%2c" , ptr->dato);
		Inorden(ptr->hijo_derecho);
	}
}


void RotacionIzq(struct Nodo ** ptrPadre) {
	struct Nodo *NodoPadre = *ptrPadre;
	*ptrPadre = (*ptrPadre) -> hijo_izquierdo;
	NodoPadre -> hijo_izquierdo = (*ptrPadre) -> hijo_derecho;
	(*ptrPadre) -> hijo_derecho = NodoPadre;
}

void RotacionDer(struct Nodo ** ptrPadre) { 
	struct Nodo *NodoPadre = *ptrPadre;
	*ptrPadre = (*ptrPadre) -> hijo_derecho;
	NodoPadre -> hijo_derecho = (*ptrPadre) -> hijo_izquierdo;
	(*ptrPadre) -> hijo_izquierdo = NodoPadre;
}

void Balanceo(struct Nodo **ptrRaiz) {
	struct Nodo **Aux; 
	if(*ptrRaiz != NULL) {
		Balanceo(&((*ptrRaiz) -> hijo_izquierdo));
		Balanceo(&((*ptrRaiz) -> hijo_derecho));
		if((altura((*ptrRaiz) -> hijo_derecho)-altura((*ptrRaiz) -> hijo_izquierdo)) < -1 || (altura((*ptrRaiz) -> hijo_derecho) - altura((*ptrRaiz) -> hijo_izquierdo)) > 1) {
			
			if(altura((*ptrRaiz) -> hijo_derecho) > altura((*ptrRaiz) -> hijo_izquierdo)) {
				Aux = ptrRaiz;
				Aux = &((*Aux) -> hijo_derecho);
				if (altura((*Aux) -> hijo_derecho) > altura((*Aux) -> hijo_izquierdo)) {
					
					RotacionDer(ptrRaiz);
				}
				else {
					RotacionIzq(Aux);
					RotacionDer(ptrRaiz);
				}				
			}
			else {
				Aux = ptrRaiz;
				Aux = &((*Aux) -> hijo_izquierdo);
				if (altura((*Aux) -> hijo_derecho) < altura((*Aux) -> hijo_izquierdo)) {
					RotacionIzq(ptrRaiz);
				}
				else{
					RotacionDer(Aux);
					RotacionIzq(ptrRaiz);
				}				
			}
		
		}
	}	
	else {
		return;
	}
}

int menu()
{
	int opc;
	printf("\n\n(1) RECORRIDO \n");
	printf("(2) BUSQUEDA \n\n");
	printf("(3) ELIMINAR \n\n");
	printf("(4) SALIR \n\n");
	scanf("%d", &opc);
	return opc;
}

int altura (struct Nodo *ptr3) {
	if(!ptr3)
		return 0;
	else {
		int alturaI;
		int alturaD;
		
		alturaI = altura (ptr3 -> hijo_izquierdo);
		alturaD = altura (ptr3 -> hijo_derecho);
		
		if(alturaI > alturaD) 
			return alturaI + 1;
		else
			return alturaD + 1;
	}
}


int main(void) {
	int dato, c = 0;
	struct Nodo *ptrRaiz;
	struct Nodo *tmp;
	FILE *cfPtr;
	
	
	fopen("arbol.txt", "r");
	if ((cfPtr = fopen("Arbol2.txt", "r")) == NULL)
		printf("\aERROR NO EXISTE\n");
	else{
		while(!feof(cfPtr)){
			fscanf(cfPtr, "%c", &dato);
			if(c == 0)
				ptrRaiz = CreaNodo(dato);
			else{
				if(isalpha(dato)){Insertar(ptrRaiz, dato);
				Balanceo(&ptrRaiz);}
			}
			dato = 0;
			c++;;
		}
		fclose(cfPtr);
	}
	
	while(1)
	{
		switch(menu())
		{
			case 1:
				printf("\nPREORDEN: ");
				PreOrden(ptrRaiz);
				printf("\nINORDEN: ");
				Inorden(ptrRaiz);
				printf("\nPOSTORDEN: ");
				PostOrden(ptrRaiz);
				printf("\n");
				break;
			case 2:
				printf("\nQUE DESEA BUSCAR:\n");
				scanf(" %c", &dato);
				tmp = Busqueda(ptrRaiz, dato);
				if (tmp){
					printf("EL ELEMENTO BUSCADO ES: %c\n", tmp->dato);
					printf("RECORRIDO: "); Camino(ptrRaiz, dato);
					printf("\nPADRE: %c", Padre(ptrRaiz, dato));
					ReadNode(ptrRaiz, dato);
					printf("\n\n");
				}
				else
					printf("EL DATO NO ESTA EN EL ARBOL.\n\n");
				break;
			case 3:
				printf("\nLETRA A BORRAR: ");
				scanf("%c",&dato);
				elimina(&ptrRaiz,dato);
				Balanceo(&ptrRaiz);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("INCORRECTO \n");
		}
	}
	
return 0;
}