#include <iostream>
#include <string>
#include "assertdomjudge.h"
#include "impresionListasEnlazadas.h"
#include "ListaEnlazada.h"
using namespace std;
class Agenda
{
public:
	//atributo que indica el máximo número de contactos que se puede almacenar en la tabla
	int capacidad;
	//Número actual de elementos en la tabla
	int n;
	//Vector de capacidad listas enlazadas, cada lista enlazada puede almacenar nodos de la clase Nodo que contienen un elemento de tipo COntacto que almacena el nombre y el telefono
	ListaEnlazada *tabla;
	
	/*
	Constructor de la clase Agenda, incializa el atributo capacidad y n y ademas reserva capacidad elementos para todos los arrays
	Parametros:
	-capacidad: capacidad de la tabla
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	Agenda(int capacidad);

	/*
	Permite obtener la posicion que corespone al número de telefono indicadao dentro de la tabla
	Parametros:
	-telefono: número de telefono a estudiar
	Retorno:
	-int: posicion correspondiente al número dado
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	int obtenerPosicion(long telefono);

	/*
	Devuelve si el contacto con el télefono indicado está almacenado o no en la tabla
	Parametros:
	-telefono: número de telefono a estudiar
	Retorno:
	-bool: true si existe, false si no existe
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	bool existeContacto(long telefono);

	/*
	Devuelve el nombre del contacto que tiene el telefono indicado
	Parametros:
	-telefono: número de telefono a estudiar
	Retorno:
	-string: nombre del contacto
	Precondiciones:
	-existe el contacto
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	string getContacto(long telefono);

	/*
	Introduce un contacto nuevo a la tabla en su posición correspondiente
	Parametros:
	-telefono: número de telefono a introducir
	-contacto: nombre del contacto
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	void introducirContacto(long telefono, string cotnacto);

	/*
	Elimina el contacto con el télefono indicado
	Parametros:
	-telefono: número de telefono a elminar
	Precondiciones:
	-existe el contacto
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	void eliminarContacto(long telefono);

	/*
	Imprime toda la tabla
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	void imprimir();

	/*
	Destructor de Agenda, librea la memoria reservada por el constructor
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	~Agenda();
};

