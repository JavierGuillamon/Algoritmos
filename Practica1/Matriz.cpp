#include "Matriz.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//Constructor por defecto
Matriz::Matriz() {
	n_filas = 0;
	n_columnas = 0;
	matriz = NULL;
}

//Constructor por parametros
Matriz::Matriz(int n_filas, int n_columnas) {
	assertdomjudge(n_filas > 0);
	assertdomjudge(n_columnas > 0);
	this->n_filas = n_filas;
	this->n_columnas = n_columnas;
	matriz = new double*[n_filas];
	for (int i = 0;i < n_filas;i++) {
		matriz[i] = new double[n_columnas];
	}
	for (int i = 0; i < n_filas; i++) {
		for (int j = 0; j < n_columnas; j++) {
			matriz[i][j] = 0;
		}
	}
}

//constructor Copia
Matriz::Matriz(const Matriz &m) {
	this->n_filas = m.n_filas;
	this->n_columnas = m.n_columnas;
	matriz = new double*[n_filas];
	for (int i = 0; i < n_filas;i++) {
		matriz[i] = new double[n_columnas];
		for (int j = 0;j < n_columnas;j++) {
			matriz[i][j] = m.matriz[i][j];
		}
	}
}

//Destrucotr
Matriz::~Matriz() {
	for (int i = 0; i < n_filas;i++) {
		delete[] matriz[i];
	}
	delete matriz;
}

//Operador suma
Matriz Matriz::operator+ (const Matriz &m) {
	assertdomjudge(n_filas == m.n_filas);
	assertdomjudge(n_columnas == m.n_columnas);
	Matriz mAux(n_filas,n_columnas);
	for (int i = 0; i < n_filas; i++) {
		for (int j = 0; j < n_columnas; j++) {
			mAux.matriz[i][j]=matriz[i][j] + m.matriz[i][j];
		}
	}
	return mAux;
}

//Operador resta
Matriz Matriz::operator- (const Matriz &m) {
	assertdomjudge(n_filas == m.n_filas);
	assertdomjudge(n_columnas == m.n_columnas);
	Matriz mAux(n_filas, n_columnas);
	for (int i = 0; i < n_filas; i++) {
		for (int j = 0; j < n_columnas; j++) {
			mAux.matriz[i][j] = matriz[i][j] - m.matriz[i][j];
		}
	}
	return mAux;
}

//Operador producto por escalar
Matriz Matriz::operator* (double a) {
	Matriz mAux(n_filas, n_columnas);
	for (int i = 0; i < n_filas; i++) {
		for (int j = 0; j < n_columnas; j++) {
			mAux.matriz[i][j] = matriz[i][j] * a;
		}
	}
	return mAux;
}

//Operador producto por una matriz
Matriz Matriz::operator*(const Matriz &m) {
	assertdomjudge(n_columnas == m.n_filas);
	Matriz mAux(n_filas,m.n_columnas);
	for (int i = 0; i < n_filas; i++) {
		for (int j = 0; j < m.n_columnas; j++) {
			for (int k = 0; k < n_columnas; k++) {
				mAux.matriz[i][j] += matriz[i][k] * m.matriz[k][j];
			}
		}
	}
	return mAux;
}

//Calcular TraNspuesta
Matriz Matriz::calcularTraspuesta() {
	Matriz mAux(n_columnas, n_filas);
	for (int i = 0; i < n_filas; i++) {
		for (int j = 0; j < n_columnas; j++) {
			mAux.matriz[i][j] = matriz[j][i];
		}
	}
	return mAux;
}

//Calcular simetrica
bool Matriz::esSimetrica() {
	for (int i = 0; i < n_filas; i++) {
		for (int j = 0; j < n_columnas; j++) {
			if (matriz[i][j] != matriz[j][i]) {
				return false;
			}
		}
	}
	return true;
}

double Matriz::obtenerMaximo() {
	double respuesta = matriz[0][0];
	for (int i = 0; i < n_filas; i++) {
		for (int j = 0; j < n_columnas; j++) {	
			if (matriz[i][j]>respuesta) 
				respuesta = matriz[i][j];
		}
	}
	return respuesta;
}

double Matriz::obtenerMinimo() {
	double respuesta= matriz[0][0];
	for (int i = 0; i < n_filas; i++) {
		for (int j = 0; j < n_columnas; j++) {
			if (matriz[i][j]<respuesta)
				respuesta = matriz[i][j];
		}
	}
	return respuesta;
}

//Asignacion de matrices
Matriz& Matriz::operator= (const Matriz &m)
{
	if (matriz != NULL)
	{
		for (int i = 0; i < n_filas; i++)
			delete[] matriz[i];

		delete[] matriz;
		matriz = NULL;
	}

	this->n_filas = m.n_filas;
	this->n_columnas = m.n_columnas;
	this->matriz = NULL;
	if (n_filas>0 && n_columnas>0)
	{
		matriz = new double *[n_filas];

		for (int i = 0; i < n_filas; i++)
		{
			matriz[i] = new double[n_columnas];
			for (int j = 0; j <n_columnas; j++)
				matriz[i][j] = m.matriz[i][j];
		}
	}

	return(*this);
}

// Leer matriz
void Matriz::rellenarManual()
{
	double elemento;
	for (int i = 0; i < n_filas; i++)
	{
		cout << "Fila " << i << endl;
		for (int j = 0; j < n_columnas; j++)
		{
			cout << "Elemento " << j << endl;
			cin >> elemento;
			matriz[i][j] = elemento;
		}
		cout << endl;
	}

}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed)
{
	srand(seed);
	for (int i = 0; i < n_filas; i++)
		for (int j = 0; j < n_columnas; j++)
			matriz[i][j] = rand();

}

// Imprimir Matriz
void Matriz::mostrarMatriz()
{
	for (int i = 0; i < n_filas; i++)
	{
		for (int j = 0; j < n_columnas; j++)
			cout << matriz[i][j] << " ";
		cout << endl;
	}
}

