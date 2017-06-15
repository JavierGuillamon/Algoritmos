#include<iostream>
using namespace std;
/*
Javier Guillamón Pardo
Práctica 2

Implementación del algoritmo de ordenación por inserción
*/

/*
Algoritmo que permite ordenar una lista de enteros usando el algoritmo de insercion
Parámetros:
-x: Lista de enteros que se quiere ordenar
-len: Cantidad de elementos que hay en la lista
Retorno: Una linea por cada iteracion del algoritmo, mostrando el estado de la lista por pantalla
Precondiciones: ninguna
Complejidad:
-Temporal: T(n)=(n^2)/2 + n/2 + 1 | O(n)=n^2
-Espacial: M(n)=1 | O(n)=1
*/
void ordenarInsercion(int x[], int len)
{
	for (int i = 1; i<len; i++)
	{
		int j=i-1, aux = x[i];
		while ((j >= 0) && (x[j]>aux)) {
			x[j + 1] = x[j];
			j = j - 1;
		}
		x[j + 1] = aux;

		for (int k = 0; k<len; k++)
			cout << x[k] << " ";
		cout << endl;
	}
}


int main()
{
	int n;
	cin >> n;
	int *x = new int[n];
	for (int i = 0; i<n; i++)
		cin >> x[i];
	ordenarInsercion(x, n);
}