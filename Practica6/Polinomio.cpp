#include "Polinomio.h"
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

float Polinomio::obtenerAleatorioNormalEstandar() {
	// Una variable aleatoria normal estándar se puede calcular o bien con "normal_distribution" de la biblioteca "random" (versión 2011 de C++)
	// o bien mediante 12 sumas sucesivas de valores aleatorios uniformes entre 0 y 1 (nos lo da rand()/(float)RAND_MAX),
	// y luego restándole 6. Más detalles sobre este método en 
	// http://en.wikipedia.org/wiki/Normal_distribution#Generating_values_from_normal_distribution
	// Para calcular una normal no estándar recordemos que sería X = media + desviación*Z, donde Z es la normal estándar

	float suma = 0; // Suma de 12 variables aleatorias uniformes entre 0 y 1
	for (int i = 0; i<12; i++) suma = suma + rand() / (float)RAND_MAX;
	return(suma - 6);
}

float Polinomio::obtenerRaizRecursivo(SolucionParcial padre) {

	// Imprimimos el padre
	cout << "Seleccionada" << endl;
	padre.imprimir();
	cout << "Mutaciones" << endl;
	SolucionParcial solucion = padre;
	// Calculamos la mutación para cada hijo  y evaluamos el polinomio para dicha mutación
	for (int i = 0; i < numeroHijos; i++) {
		SolucionParcial hijo;
		hijo.x = padre.x + obtenerAleatorioNormalEstandar();
		hijo.y = evaluar(hijo.x);
		// Imprimimos la solucion parcial encontrada para las mutaciones
		hijo.imprimir();
		// Elegimos el mejor hijo de numeroHijos
		if(abs(hijo.y)<abs(solucion.y))
			solucion = hijo;
	}
	// Si el mejor hijo es mejor que el padre, hacemos que tenga descendencia. Si no, hemos acabado
	if (solucion.y != padre.y)
		return obtenerRaizRecursivo(solucion);
	return solucion.x;
}

Polinomio::Polinomio(int n, float *coeficientes) {
	this->n=n;
	this->coeficientes = coeficientes;
	numeroHijos = 10;
}

float Polinomio::evaluar(float x) {
	float evaluacion=0;
	for (int i = 0; i <= n; i++) 
		evaluacion += pow(x, i)*coeficientes[i];
	return evaluacion;
}


float Polinomio::obtenerRaiz() {
	SolucionParcial padre;
	padre.x = 0;
	padre.y = evaluar(padre.x);
	return obtenerRaizRecursivo(padre);
}


Polinomio::~Polinomio() {
	delete coeficientes;
}