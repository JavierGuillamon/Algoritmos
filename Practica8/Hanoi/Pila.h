#include"Nodo.h"
#include<string>
#include<iostream>
using namespace std;

class Pila
{
private:
	//Puntero apuntando a la cima de la pila
	Nodo *cima;
	//Nombre de la pila que se utilizar� para almacenar el nombre del poste
	string name;
public:
	/*
	Constructor con par�metros de la estructura Pila, inicializa el puntero a la cima y asigna el nombre indicado a la pila
	Parametros:
	-name: nombre de la pila
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	Pila(string name);

	/*
	Devuelve el nombre de la pilta
	Retorno:
	-string: nombre de la pila
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	string nombrePila();

	/*
	Recibe un n�mero que representa el tama�o del disco y lo coloca en la cima de la pila
	Parametros:
	-num: tama�o del disco
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	void apilar(int num);

	/*
	Devuelve el n�mero que se encuentra en la cima de la pila y lo quita de la cima
	Retorno:
	-int: numero desapilado
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	int desapilar();

	/*
	Indica si la pila se encuentra vac�a
	Retorno:
	-bool: true pila vacia, false pila no vacia
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	bool estaVacia();
};

