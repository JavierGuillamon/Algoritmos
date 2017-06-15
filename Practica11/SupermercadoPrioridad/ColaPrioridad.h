#include "ListaContigua.h"

// Clase que implementa una cola con prioridad mediante un monticulo (arbol binario completo en el cual la clave de cada nodo es menor que la de sus descendientes) e implementado sobre una lista contigua
class ColaPrioridad
{
protected:
	//Lista contigua sobre la que se implementrara el monticulo
	ListaContigua vector;

public:
	/*
	Recibe un numero que representa el orden de llegada del cliente y lo coloca al final de la cola, despues lo recoloca en la posicion que le corresponda
	Parametros:
	-nuevoElemento: orden de llegada
	Complejidad:
	-Temporal: O(n)= log n
	-Espacial: O(n)= 1
	*/
	void encolar(int nuevoElemento);
	
	/*
	Devuelve el numero que representa el orden de llegada del cliente que se encuentra en la primer posicion del monticulo y lo elimina
	Retorno:
	-int: orden de llegada 
	Complejidad:
	-Temporal: O(n)= log n
	-Espacial: O(n)= 1
	*/
	int desencolar();
	
	/*
	Indica si la cola se encuentra vacia
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	bool estaVacia();

protected:
	/*
	Reestructura el vector para que sea un monticulo
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	void reestructurar();
};

