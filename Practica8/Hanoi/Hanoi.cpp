#include<iostream>
#include"Pila.h"
#include"assertdomjudge.h"
using namespace std;
/*
Metodo recursivo que realiza el algoritmo para resolver torres de Hnoy
Parametros:
-n: numero de discos
-origen: puntero a la pila origen
-destino: puntero a la pila destino
-temporal: puntero a la pila temporal
Precondiciones:
- n > 0
Complejidad:
-Temporal: O(n)= 2^n
-Espacial: O(n)= 1
*/
void Hanoi(int n, Pila *origen, Pila *destino, Pila *temporal)
{
	assertdomjudge(n > 0);
	if (n == 1) {
		destino->apilar(origen->desapilar());
	}
	else {
		Hanoi(n - 1, origen, temporal, destino);
		destino->apilar(origen->desapilar());
		Hanoi(n - 1, temporal, destino, origen);
	}
}


int main()
{
	Pila *A = new Pila("A");
	Pila *B = new Pila("B");
	Pila *C = new Pila("C");

	int n;
	cin >> n;

	for (int i = n; i>0; i--)
		A->apilar(i);

	Hanoi(n, A, C, B);

	for (int i = 0; i<n; i++)
		C->desapilar();
	return 0;
}
