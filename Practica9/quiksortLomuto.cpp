#include<iostream>

using namespace std;



/*
Función para dividir el array y hacer los intercambios basado en la partición de Lomuto https://en.wikipedia.org/wiki/Quicksort
Parametros:
-array: lista con la que se quiere trabajar
-first: primera posicion
-last: ultima posicion
Retorno:
-int: posicion de la particion
Complejidad:
-Temporal: O(n)= n
-Espacial: O(n)= 1
*/
int particion(int *array, int first, int last) {
	int pivote = array[last];
	int i = first - 1;
	for (int j = first; j < last; j++) {
		if (array[j] <= pivote) {
			i = i + 1;
			int aux = array[i];
			array[i] = array[j];
			array[j] = aux;
		}
	}
	int aux = array[i + 1];
	array[i + 1] = array[last];
	array[last] = aux;
	return i + 1;
}


/*
Función recursiva para hacer el ordenamiento
Parametros:
-array: lista con la que se quiere trabajar
-start: primera posicion
-end: ultima posicion
Complejidad:
-Temporal: O(n)= n^2
-Espacial: O(n)= 1
*/
void quicksort(int *array, int start, int end)
{
	if (start < end) {
		//Divido la lista en dos partes los menores que el pivote y los mayores
		int p = particion(array, start, end);
		// Ordeno la lista de los menores que el pivote
		quicksort(array, start, p - 1);
		// Ordeno la lista de los mayores que el pivote
		quicksort(array, p + 1, end);
		// Imprimo la lista actual	
		for (int i = start; i <= end; i++)
			cout << array[i] << " ";
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
	quicksort(x, 0, n - 1);
}
