#include <iostream>
#include <string>
#include "assertdomjudge.h"
#include "impresionListasEnlazadas.h"
using namespace std;
class Agenda
{
public:
	//atributo que indica el m�ximo n�mero de contactos que se puede almacenar en la tabla
	int capacidad;
	//N�mero actual de elementos en la tabla
	int n;
	//Puntero a un array de strings que permitir� almacenar los nombres de los contactos
	string *nombres;
	//Puntero a un array de longs que permitir� almacenar los telefonos de los contactos
	long *telefonos;
	//Puntero a un array de boolenaos que permite omdocar que posiciones de la tabla est�n vac�as
	bool *vacias;
	//Puntero a un array de boolenaos que permite omdocar que posiciones de la tabla han sido borradas
	bool *borradas;
	
	/*
	Constructor de la clase Agenda, incializa el atributo capacidad y n y ademas reserva capacidad elementos para todos los arrays
	Parametros:
	-capacidad: capacidad de la tabla
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	Agenda(int capacidad);

	/*
	Permite obtener la posicion que corespone al n�mero de telefono indicadao dentro de la tabla
	Parametros:
	-telefono: n�mero de telefono a estudiar
	Retorno:
	-int: posicion correspondiente al n�mero dado
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	int obtenerPosicion(long telefono);

	/*
	Obtiene la posicion teal de un contacto en la talba
	Parametros:
	-telefono: n�mero de telefono a buscar
	Retorno:
	-int: posicion correspondiente al n�mero dado
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	int buscarContacto(long telefono);

	/*
	Busca el hueco adecuado para meter un contacto
	Parametros:
	-telefono: n�mero de telefono a estudiar
	Retorno:
	-int: posicion correspondiente al hueco
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	int buscarHueco(long telefono);

	/*
	Indica si la tabla ha alcanzado su m�xima capacidad
	Retorno:
	-bool: true si esta llena, false si no lo est�
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	bool isLlena();

	/*
	Devuelve si el contacto con el t�lefono indicado est� almacenado o no en la tabla
	Parametros:
	-telefono: n�mero de telefono a estudiar
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
	-telefono: n�mero de telefono a estudiar
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
	Introduce un contacto nuevo a la tabla en su posici�n correspondiente
	Parametros:
	-telefono: n�mero de telefono a introducir
	-contacto: nombre del contacto
	Precondiciones:
	-no este llena la tabla
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	void introducirContacto(long telefono, string cotnacto);

	/*
	Elimina el contacto con el t�lefono indicado
	Parametros:
	-telefono: n�mero de telefono a elminar
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

