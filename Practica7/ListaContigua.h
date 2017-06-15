#pragma once

class ListaContigua
{
	//Puntero a un array de enteros que permitirá almacenar capadidad elemntos de tipo int
	int *vector;

	//atributo que lamacena de forma privada el número de elementos almacenados actualmente en la lista contigua
	int n;

	//atributo que indica el máximo nñumero de elementos que se pueden almacenar en la lista
	int capacidad;

	//atributo que indica el número de posiciones que se incrementa/decrementa la capacidad de la ListaContigua cuando es necesario
	int incremento;


public:
	/*
	Constructor de la lista continua. inicializa los atributos n, capacidad e incremento, asi como el vector de enteros
	Parametros:
	-incremento: valor de incremento
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	ListaContigua(int incremento);

	/*
	Devuelve el elemento de la lista contigua que se encuentra en posicion
	Parametros:
	-posicion: posicion en la que queremos buscar
	Retorno:
	-int: valor del elemento encontrado
	Precondiciones:
	-pos < n;
	-pos >= 0;
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	int getValor(int posicion);

	/*
	Modifica el elemento de la lista contigua que se encuentra en posicion
	Parametros:
	-posicion: posicion en la que queremos modificar el valor
	-nuevoValor: nuevo valor por el que se modifica el elemento
	Precondiciones:
	-pos < n;
	-pos >= 0;
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	void setValor(int posicion, int nuevoValor);

	/*
	Devuelve el tamaño actual de la lista contigua
	Retorno:
	-int: tamaño actual de la lista contigua
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	int getN();

	/*
	Devuelve la capacidad de la lista contigua
	Retorno:
	-int: capacidad de la lista contigua
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	int getCapacidad();

	/*
	Inserta un nuevo elemento en una posición
	Parametros:
	-posicion: posicion en la que queremos insertar
	-nuevoValor: valor que queremos insertar
	Precondiciones:
	-pos <= n;
	-pos >= 0;
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= n
	*/
	void insertar(int posicion, int nuevoValor);

	/*
	Elimina el elemento que se encuentra en la posición
	Parametros:
	-posicion: posicion del valor que queremos eliminar
	Precondiciones:
	-pos < n;
	-pos >= 0;
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= n
	*/
	void eliminar(int posicion);
	/*
	Concatena la lista indicada como parametro al final de la lista que llame a este metodo
	Parametros:
	-listaAConcatenar: lista que se quiere concatenar
	Complejidad:
	-Temporal: O(n)= n + listaAConcatenar->n
	-Espacial: O(n)= n + listaAConcatenar->n
	*/
	void concatenar(ListaContigua *listaAConcatenar);
	/*
	Busca un elemento en la lista contigua con valor igual a elementoABuscar
	Parametros:
	-elementoABuscar: valor que se busca en la lista
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
	~ListaContigua();
};








