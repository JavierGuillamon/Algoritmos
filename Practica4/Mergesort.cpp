#include<iostream>
using namespace std;
/*
Javier Guillamón Pardo
Práctica 4
*/

/*
Permite combinar dos arrays
Parámetros:
-a: primer array a combinar
-len_a: longitud del array a
-b: segundo array a combinar
-len_b: longitud del array b
-c: array contenedor del resultado de combinar ambos arrays
Complejidad:
-Temporal: O(n)= n
-Espacial: O(n)= 1
*/
void  combinar(int a[], int len_a, int b[], int len_b, int c[])
{
	int i = 0,j=0, h = 0;
	while ( h<(len_a+len_b)) {	
		if (i >= len_a) {
			c[h] = b[j];
			j++;
		}
		else if (j >= len_b) {
			c[h] = a[i];
			i++;
		}
		else if (a[i] < b[j]) {
			c[h] = a[i];
			i++;
		}
		else {
			c[h] = b[j];
			j++;
		}
		h++;		
	}
}

/*
Ordena un array de enteros utilizando el algoritmo de ordenamiento por mezcla, solucion basada en la estrategia divide y vencerás
Parámetros:
-x: array de enteros a ordenar
-len: longitud del array x
Complejidad: 
-Temporal: O(n)= lgn
-Espacial: O(n)= n
*/
void ordenarMergeSort(int x[], int len)
{
	int *temp = new int[len];
	if (len <= 1)
		return;
	else
	{
		int medio = len / 2;

		int *izq = new int[medio];
		int *dch = new int[medio];

		for (int i = 0; i < medio; i++) {
			izq[i]=x[i];
		}
		for (int i = medio; i < len; i++) {
			dch[i - medio] = x[i];
		}

		ordenarMergeSort(izq, medio);
		ordenarMergeSort(dch, len - medio);
		combinar(izq,medio,dch,len-medio,temp);

		for (int k = 0; k < len; k++)
		{
			x[k] = temp[k];
			cout << x[k] << " ";
		}
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
	ordenarMergeSort(x, n);
}
