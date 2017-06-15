#include<iostream>
using namespace std;
/*
Javier Guillamón Pardo
Práctica 2

Implementación del algoritmo de ordenación por selección
*/

/*
Algoritmo que permite ordenar una lista de enteros usando el algoritmo de seleccion
Parámetros:
-x: Lista de enteros que se quiere ordenar
-len: Cantidad de elementos que hay en la lista
Retorno: Una linea por cada iteracion del algoritmo, mostrando el estado de la lista por pantalla
Precondiciones: ninguna
Complejidad:
-Temporal: T(n)=(n^2)/2 + (3n)/2 + 1 | O(n)=n^2
-Espacial: M(n)=1 | O(n)=1
*/
void ordenarSeleccion(int x[], int len)
{
	for (int i = 0; i<len; i++)
	{
		int j, aux = i;
		for (j = i+1; j <len; j++) {
			if (x[j] < x[aux]) {
				aux = j;
			}
		}
		int aux2 = x[i];
		x[i] = x[aux];
		x[aux] = aux2;

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
	ordenarSeleccion(x, n);
}
