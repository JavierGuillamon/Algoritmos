#pragma once
#include "Nodo.h"

class ListaEnlazada
{
	//Puntero al primer elemento de la lista
	Nodo *lista;

	//atributo que almacena el número de elementos almacenados actualemente en la lista contigua
	int n;

	/*
	Metodo que permite obtener el nodo de la lista que se encuentra en una posicion
	Parametros:
	-posicion: posicion del elemento que se quiere conseguir
	Retorno:
	-Nodo: nodo encontrado en dicha posicion
	Precondiciones:
	-posicion >= 0
	-posicion <= n
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	Nodo * getNodo(int posicion);

public:
	/*
	Constructor de la lista enlazada. Crea una lista de tamaño 0
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	ListaEnlazada();

	/*
	Devuelve el elemento de la listaque se encuentra en una posicion
	Parametros:
	-posicion: posicion del elemento que se quiere conseguir
	Retorno:
	-int: valor del nodo encontrdo en dicha posicion
	Precondiciones:
	-posicion >= 0
	-posicion < n
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	int getValor(int posicion);

	/*
	Modifica el elemento de la lista que se encuentra en una posicion, y se cambia su valor
	Parametros:
	-posicion: posicion del elemento que se quiere conseguir
	-nuevoValor: nuevo valor por el que se modifica el elemento
	Precondiciones:
	-posicion >= 0
	-posicion < n
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	void setValor(int posicion, int nuevoValor);

	/*
	Devuelve el tamaño actual de la lista enlazada
	Retorno:
	-int: valor de n
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	int getN();

	/*
	Inserta un uevo elemento en una posicion de la lista con un valor, cambiando los punteros correspondientes
	Parametros:
	-posicion: posicion del elemento que se quiere conseguir
	-nuevoValor: valor que se quiere introducir en dicha posicion
	Precondiciones:
	-posicion >= 0
	-posicion <= n
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	void insertar(int posicion, int nuevoValor);

	/*
	Elimina el elemento que se encuentra en un posicion dada
	Parametros:
	-posicion: posicion del elemento que se quiere eliminar
	Precondiciones:
	-posicion >= 0
	-posicion < n
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	void eliminar(int posicion);

	/*
	Concatena la lista indicada como parámetro al final de nuestra lista
	Parametros:
	-listaAConcatenar: lista que se quiere concatenar
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	void concatenar(ListaEnlazada *listaAConcatenar);

	/*
	Busca un elemento en la lista
	Parametros:
	-elementoABuscar: elemento que se quiere buscar
	Retorno:
	-int: posicion del elemento si se encuentra ó -1 si no se encuentra
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	int buscar(int elementoABuscar);

	/*
	Libera la memoria que fue reservada de forma dinamica para almacenar el vector
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	~ListaEnlazada();
};







