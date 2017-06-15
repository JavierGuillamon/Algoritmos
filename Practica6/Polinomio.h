#pragma once

#include "SolucionParcial.h" // Estructura que guarda el "x" e "y" de una solución parcial

class Polinomio
{
private:
	//número de hijos que se deberan crear en cada iteración
	int numeroHijos;
	//atributo que indica el gado del polinomio
	int n;
	//puntero a un array con los coeficientes del polinomio
	float *coeficientes;

	/*
	Genera numeros aleatorios con una distribución de probabilidad normal estandar
	Retorno:
	-float: numero aleatorio normal estandar
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	float obtenerAleatorioNormalEstandar();
	/*
	llamada recursiva del algoritmo genetico para conseguir una solucion parcial de la raiz de un polinomio
	Parámetros:
	-solucionParcialInicial: objeto del padre que determina la solucion
	Retorno:
	si la solucion de algun hij es mejor que la del padre devuelve una llamada recursiva a este mismo metodo
	si no lo es, devuelve el valor aproximado de la raiz
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= n
	*/
	float obtenerRaizRecursivo(SolucionParcial solucionParcialInicial);

public:
	/*
	Constructor del polinomio
	Parametros:
	-n: grado del polinomio
	-coeficientes: direccion del comienzo del array de coeficientes
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	Polinomio(int n, float *coeficientes);
	/*
	Calcula el valor de un polinomio para un valor de x dado
	Parametros:
	-x: valor de X para el polinomio
	Retorno:
	-float: valor del polinomio
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	float evaluar(float x);
	/*
	Metodo para obtenre la raiz de un polinomio, llama a obtenerRaizRecursivo
	Retorno:
	-float: valor de la raiz
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= n
	*/
	float obtenerRaiz();
	
	//Destructor del polinomio
	~Polinomio();
};
