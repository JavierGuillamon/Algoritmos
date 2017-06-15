#include "Nodo.h"
class Cola
{
private:
	Nodo *principio;
	Nodo *final;
public:
	/*
	Constructor sin parámetros de la estructura Cola. Inicializa los punteros principio y final
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	Cola();

	/*
	Recibe un número que representara el oprden de llegada del cliente al supermercado y lo colocara al final de la cola
	Parametros:
	-num: orden de llegada
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	void encolar(int num);

	/*
	Devuelve el número que representa el orden de llegada del cliente que se encuentra en la primera posición de la cola
	Retorno:
	-int orden de llegada del cliente
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	int desencolar();

	/*
	Indica si la cola se encuentra vacía
	Retorno:
	-bool: true si esta vaciá, false si no lo está
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	bool estaVacia();
};

