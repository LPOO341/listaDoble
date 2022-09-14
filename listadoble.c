//Jorge Omar Torres Sosa 1270900
#include <stdio.h>
#include <stdlib.h>

struct nodoLista{
	int dato; //cada nodo Lista contiene un dato entero
	struct nodoLista *ptrSiguiente; //apuntador al siguiente nodo
  struct nodoLista *ptrAnterior;
};

// sestructura auto referenciada
typedef struct nodoLista NodoLista; // sinonimo para struct nodoLista
typedef NodoLista *ptrNodoLista; // synonym for ListNode*

// prototypes
void insertar(ptrNodoLista *ptrS, int valor);
void insertarFinal(ptrNodoLista *ptrS, int valor);
void insertarCentro(ptrNodoLista *ptrS, int valor, int posicion);
void borrar(ptrNodoLista *sPtr);
void borrarUltimo(ptrNodoLista *sPtr);
void borrarCentro(ptrNodoLista *ptrS, int valor);
int estaVacia(ptrNodoLista ptrS);
void imprimeLista(ptrNodoLista ptrActual);
void instrucciones(void);
int obtenerEntero(char mensaje[]);

int main()
{
	ptrNodoLista ptrInicial = NULL; // inicialmente no existen nodos
	int opcion, opcion2;						// eleccion del usuario
	int var, posicion;							// entero ingresado por el usuario

	// ciclo while para que el usuario no elija 3
  printf("Programa de listas enlazadas dobles\n");
	while (opcion != 3)
	{
		instrucciones();
		opcion = obtenerEntero("opcion: ");
		switch (opcion)
		{
		case 1: // insertar un elemento
			var = obtenerEntero("Entero a ingresar: ");
			printf("1. Ingresar al inicio\n2. Ingresar al final\n3. Ingresar al centro"); // Menu del tipo de insercion
			opcion2 = obtenerEntero("opcion: ");
			switch (opcion2)
			{
			case 1:
				insertar(&ptrInicial, var);
				break;
			case 2:
				if (!estaVacia(ptrInicial)) // valida que el arreglo no este vacio antes de insertar en el centro o al final
				{
					insertarFinal(&ptrInicial, var);
				}
				else
				{
					printf("La lista no esta inicializada, ingrese primero un valor al inicio");
				}
				break;
			case 3:
				if (!estaVacia(ptrInicial))
				{
					posicion = obtenerEntero("Posicion a insertar (2~n):");
					insertarCentro(&ptrInicial, var, posicion);
				}
				else
				{
					printf("La lista no esta inicializada, ingrese primero un valor al inicio\n");
				}
				break;
			default:
				printf("Opcion no valida");
				break;
			}
			break;
		case 2:
			// si la lista no esta vacia
			if (!estaVacia(ptrInicial))
			{
				printf("1. Borrar al inicio\n2. Borrar al final\n3. Borrar al centro");
				opcion2 = obtenerEntero("opcion: ");
				switch (opcion2)
				{
				case 1:
					borrar(&ptrInicial);
					break;
				case 2:
					borrarUltimo(&ptrInicial);
					break;
				case 3:
					posicion = obtenerEntero("Posicion a borrar: ");
					borrarCentro(&ptrInicial, posicion);
					break;
				default:
					printf("Opcion no valida");
					break;
				}
			}
			else
			{
				printf("La lista esta vacia, ingrese elementos primero\n");
			}
			break;
		default:
			printf("Opcion invalida.\n");
			break;
		} // fin del switch
		imprimeLista(ptrInicial);
		printf("\n\n");
	} // fin while

	printf("Termino el programa.");
	return 0;
}

	// display program instructions to user
void instrucciones(void) {
		printf("Introduce una opcion:\n 1. Insertar un elemento a la lista.\n 2. Borrar un elemento de la lista.\n 3: Salir del programa.");

	}
	
// insertar un valor nuevo en la lista en order
void insertar(ptrNodoLista *ptrS, int valor) {
	ptrNodoLista ptrNuevo;
	
	ptrNuevo = malloc(sizeof(NodoLista)); // crear nodo
	
	if(ptrNuevo != NULL) { // hay espacio disponible?
		ptrNuevo->dato = valor; // coloca el valor en el nodo
		// inserta un nuevo nodo al principio de la lista
		ptrNuevo->ptrSiguiente=*ptrS;
    if (ptrNuevo->ptrSiguiente != NULL)
    {
     ptrNuevo->ptrSiguiente->ptrAnterior= ptrNuevo;
    }
    ptrNuevo->ptrAnterior = NULL;
		*ptrS = ptrNuevo;

	}
	else {
		printf("%d no se inserto. Memoria no disponible.\n", valor);
	}
}

void insertarFinal(ptrNodoLista *ptrS, int valor) {
	ptrNodoLista ptrNuevo;
	ptrNodoLista ptrActual;
	ptrNuevo = malloc(sizeof(NodoLista)); // crear nodo
	
	if(ptrNuevo != NULL) { // hay espacio disponible?
		ptrNuevo->dato = valor; // coloca el valor en el nodo
		ptrActual = *ptrS;
    while (ptrActual->ptrSiguiente != NULL)
    { 
      ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
    }
		// inserta un nuevo nodo al principio de la lista
    ptrActual->ptrSiguiente = ptrNuevo;
    ptrNuevo->ptrSiguiente = NULL;
    ptrNuevo->ptrAnterior = ptrActual;
	}
	else {
		printf("%d no se inserto. Memoria no disponible.\n", valor);
	}
}

void insertarCentro(ptrNodoLista *ptrS, int valor, int posicion) {
	ptrNodoLista ptrNuevo;
	ptrNodoLista ptrActual;
	ptrNodoLista ptrAnterior;
	ptrNuevo = malloc(sizeof(NodoLista)); // crear nodo
	int i = 2;
	if(ptrNuevo != NULL) { // hay espacio disponible?

		ptrNuevo->dato = valor; // coloca el valor en el nodo
		ptrActual = *ptrS;
	while (i <= posicion && ptrActual != NULL)
	{
		ptrAnterior = ptrActual; // entra al...
		ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
		i++;
	} 
	if (ptrActual != NULL && posicion >= 2)
	{
		// inserta el nodo en la posiicon requerida de las lista
    ptrAnterior->ptrSiguiente = ptrNuevo;
    ptrNuevo->ptrAnterior = ptrAnterior;
    ptrNuevo->ptrSiguiente = ptrActual;
    ptrActual->ptrAnterior = ptrNuevo;

	}else {
		printf("%d no se inserto. Fuera del rango de valor.\n", valor);
	}

	}
	else {
		printf("%d no se inserto. Memoria no disponible.\n", valor);
	}
}

// Borrar una elemento de la lista
void borrar(ptrNodoLista *ptrS)
{
	ptrNodoLista ptrTemporal;

	// borrar el primero nodos
	ptrTemporal = *ptrS;					 // almacena el nodo a eliminar
	*ptrS = (*ptrS)->ptrSiguiente; // desata el nodo
  (*ptrS)->ptrAnterior=NULL;
	free(ptrTemporal);						 // libera el nodo
}

void borrarUltimo(ptrNodoLista *ptrS) // borra el ultim nodo de la lista
{
	ptrNodoLista ptrActual;

	ptrActual = *ptrS;

	while (ptrActual->ptrSiguiente != NULL) // itera la lista hasta llegar al ulimo nodo
	{				 // entra al...
		ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
	}
	// almacena el nodo a eliminar
  ptrActual->ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente;
	free(ptrActual); // desata el nodo
}

void borrarCentro(ptrNodoLista *ptrS, int valor) // borra un elemeno intermedio de la lista
{
	ptrNodoLista ptrActual;
	ptrActual = *ptrS;
	int i = 2;
	while (i <= valor && ptrActual != NULL)
	{				 // entra al...
		ptrActual = ptrActual->ptrSiguiente; // ... siguiente nodo
		i++;
	}
	if (ptrActual != NULL && valor >= 2)
	{
    ptrActual->ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente;
    ptrActual->ptrSiguiente->ptrAnterior = ptrActual->ptrAnterior;
		free(ptrActual);																		 // desata el nodo
	}
	else
	{
		printf("Fuera del rango de valor (2-n)\n");
	}
}

int estaVacia(ptrNodoLista ptrS)
{
	return ptrS == NULL;
}

// imprime la lista
void imprimeLista(ptrNodoLista ptrActual)
{
	// Si la lista esta vacia
	if (estaVacia(ptrActual))
	{
		printf("La lista esta vacia.\n");
	}
	else
	{
		printf("La lista es:");
    printf("NULL --> ");
		// mientras no sea el final de la lista
		while (ptrActual != NULL)
		{
			printf("%d --> ", ptrActual->dato);
			ptrActual = ptrActual->ptrSiguiente;
		}
		printf("NULL\n");
	}
}

int obtenerEntero(char mensaje[]) // Elimina la redundacia al obtener los int
{
	int var;
	printf("\n%s", mensaje);
	scanf("%d", &var);
	return var;
}