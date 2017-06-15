#include<cstdlib>
#include "Nodo.h"

class ListaCircular
{
	Nodo *lista;

	int n;
	/*
	Devuelve el nodo situado en una posicion dada
	Parametros:
	-posicion: posicion en la que se busca
	Retorno:
	-Nodo: nodo encontrado 
	Precondiciones:
	-pos >= 0
	-pos < n
	Complejidad:
	-Temporal: O(n)= n/2
	-Espacial: O(n)= 1
	*/
	Nodo * getNodo(int posicion);

public:
	/*
	Constructor de la lista circular, incializa el puntero lista y n
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	ListaCircular();

	/*
	Devuelve el string que se encuentra en la posicion en la lista
	Parametros:
	-posicion: posicion en la que se busca
	Retorno:
	-String: elemento del nodo
	Precondiciones:
	-pos >= 0
	-pos <= n
	Complejidad:
	-Temporal: O(n)= n/2
	-Espacial: O(n)= 1
	*/
	string getValor(int posicion);

	/*
	Cambia el valor del elemento del nodo en la posicion
	Parametros:
	-posicion: posicion en la que se busca
	-nuevoValor: nuevo valor a cambiar
	Precondiciones:
	-pos >= 0
	-pos < n
	Complejidad:
	-Temporal: O(n)= n/2
	-Espacial: O(n)= 1
	*/
	void setValor(int posicion, string nuevoValor);

	/*
	Devuelve n
	Retorno:
	-int: n
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	int getN();

	/*
	Introduce el nuevo valor en la posicion de la lista
	Parametros:
	-posicion: posicion en la que se inserta
	-nuevoValor: valor que se inserta
	Precondiciones:
	-pos >= 0
	-pos <= n
	Complejidad:
	-Temporal: O(n)= n/2
	-Espacial: O(n)= 1
	*/
	void insertar(int posicion, string nuevoValor);

	/*
	Elimina el elemento que se encuentra en la posición
	Parametros:
	-posicion: posicion en la que se elimina
	Precondiciones:
	-pos >= 0
	-pos < n
	Complejidad:
	-Temporal: O(n)= n/2
	-Espacial: O(n)= 1
	*/
	void eliminar(int posicion);

	/*
	Gira todos los elementos e la lista hacia la izquierda o la derecha dependiendo de p
	Parametros:
	-p: valor que indica el giro
	Complejidad:
	-Temporal: O(n)= p
	-Espacial: O(n)= 1
	*/
	void girar(int p);

	/*
	Destructor de la lista
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	~ListaCircular();
};







