#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;
/*
Javier Guillamón Pardo
Práctica 1

Clase que representa una mattriz de números en coma flotante y que además permite realizar operaciones sobre ellos
*/
class Matriz {
public:
	/*
	Construcctor por defecto, crea una matriz que no tiene filas ni columnas
	Parámetros: ninguno
	Precondiciones: ninguna
	Complejidad:
		-Temporal: O(n)=1
		-Espacial: O(n)=1
	*/
	Matriz();
	
	/*
	Constructor por parametros, reserva de forma dinamica el tamaño de la matriz especificado por los parametros de entrada
	Parámetros:
		-n_filas: número de filas de la matriz
		-n_columnas: número de columnas de la matriz
	Precondiciones:
		-n_filas > 0
		-n_columans > 0
	Complejidad:
		-Temporal: O(n)=nm
		-Espacial: O(n)=nm
	*/
	Matriz(int n_filas, int n_columnas);
	
	/*
	Constructor copia, se inicializa una matriz igualando todos sus valores a los de una matriz dada por paramtero
	Parámetros:
		-m: matriz que se quiere copiar
	Precondiciones: ninguna
	Complejidad:
		-Temporal: O(n)=nm 
		-Espacial: O(n)=nm
	*/
	Matriz(const Matriz &m);
	
	/*
	Destructor, se encarga de liberar la memoria reservada para almacenar la matriz
	Parámetros: ninguno
	Precondiciones: ninguna
	Complejdad:
		-Temporal: O(n)=n 
		-Espacial: O(n)=1
	*/
	~Matriz();
	
	/*
	Operador suma, nos permite sumar dos matrices
	Parámetros:
		-m: matriz que se quiere sumar a la actual
	Retorno: matriz resultante de hacer la suma
	Precondiciones:
		-n_filas == m.n_filas
		-n_columnas == m.n_columnas
	Complejidad:
		-Temporal: O(n)=2nm
		-Espacial: O(n)=nm
	*/	
	Matriz operator+ (const Matriz &m);
	
	/*
	Operador resta, nos permite restar dos matrices
	Parámetros:
		-m: matriz que se quiere restar a la actual
	Retorno: matriz resultante de hacer la resta
	Precondiciones:
		-n_filas == m.n_filas
		-n_columnas == m.n_columnas
	Complejidad:
		-Temporal: O(n)=2nm
		-Espacial: O(n)=nm
	*/
	Matriz operator- (const Matriz &m);
	
	/*
	Operador producto por una matriz, nos permite multiplicar dos matrices
	Parámetros:
		-m: matriz que se quiere multiplicar a la actual
	Retorno: matriz resultante de hacer la multiplicación
	Precondiciones:
		-n_columnas == m.n_filas
	Complejidad:
		-Temporal: O(n)=nmk
		-Espacial: O(n)=nm
	*/
	Matriz operator* (const Matriz &m);
	
	/*
	Operador producto por un escalar, nos permite multiplicar la matriz por un número dado
	Parámetros:
		-a: numero que se quiere multiplicar 
	Retorno: matriz resultante de hacer la multiplicación
	Precondiciones: ninguna
	Complejidad:
		-Temporal: O(n)=2nm
		-Espacial: O(n)=nm
	*/
	Matriz operator* (double a);
	
	/*
	Operador de asignación, permite asignar una matriz origen a otra matriz destino
	Parámetros:
		-m: matriz que se quiere asignar
	Retorno: matriz resultante de la asignación
	Precondiciones: ninguna
	Complejidad:
		-Temporal: O(n)=nm
		-Espacial: O(n)=nm
	*/
	Matriz& operator= (const Matriz &m);
	
	/*
	Calcula la matriz transpuesta de una matriz
	Parámetros: ninguno
	Retorno: matriz resultante de realizar la transpuesta
	Precondiciones: ninguna
	Complejidad:
		-Temporal: O(n)=2nm
		-Espacial: O(n)=nm
	*/
	Matriz calcularTraspuesta();

	/*
	Indica si la matriz es simétrica o no
	Parámetros: ninguno
	Retorno: resultado de la comprobación
	Precondiciones: ninguna
	Complejidad:
		-Temporal: O(n)=nm
		-Espacial: O(n)=1
	*/
	bool esSimetrica();

	/*
	Devuelve el mayor elemento de la matriz
	Parámetros: ninguno
	Retorno: elemeto mayor de la matriz
	Precondiciones: ninguna
	Complejidad:
		-Temporal: O(n)=nm
		-Espacial: O(n)=1
	*/
	double obtenerMaximo();
	
	/*
	Devuelve el menor elemento de la matriz
	Parámetros: ninguno
	Retorno: elemento menor de la matriz
	Precondiciones: ninguna
	Complejidad:
		-Temporal: O(n)=nm
		-Espacial: O(n)=1
	*/
	double obtenerMinimo();

	/*
	Permite rellenar una matriz de forma manual, pidiendo input al usuario elemento a elemento
	Parámetros: ninguno
	Precondiciones: INPUT == double
	Complejidad:
		-Temporal: O(n)=nm
		-Espacial: O(n)=1
	*/
	void rellenarManual();
	/*
	Permite rellenar una matriz de forma aleatoria a partir de una semilla introducida por el usuario
	Parámetros: 
		-seed: semilla usada para generar un numero aleatorio
	Retorno: matriz rellenada con números aleatorios
	Precondiciones: ninguna
	Complejidad:
		-Temporal: O(n)=nm
		-Espacial: O(n)=1
	*/
	void rellenarAleatorio(long seed);
	/*
	Permite sacar por pantalla todos los elementos de la matriz
	Parámetros: ninguno
	Retrono: contenido de la matriz por pantalla
	Precondiciones: ninguna
	Complejidad:
		-Temporal: O(n)=nm
		-Espacial: O(n)=1
	*/
	void mostrarMatriz();

private:
	//Puntero a una matriz bidimensional
	double **matriz;
	//Atributo que almacena de forma privada el número de filas de la matriz
	int n_filas;
	//Atributo que almacena de forma privada el número de columnas de la matriz
	int n_columnas;
};

#endif // MATRIZ_H