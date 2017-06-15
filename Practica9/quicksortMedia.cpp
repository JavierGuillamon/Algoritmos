#include"ListaCircular.h"
#include"assertdomjudge.h"
#include<iostream>

using namespace std;
/*
Elegimos el pivote como la media entre el primer y el último elemento de la lista
Parametros:
-Lista: lista de la que queremos conseguir el pivote
Retorno:
-float: valor del pivote
Complejidad:
-Temporal: O(n)= n
-Espacial: O(n)= 1
*/
float getPivote(ListaCircular * lista)
{
	// Elegimos el pivote como la media entre el primer y el último elemento de la lista
	return (float)(lista->getValor(0) + lista->getValor(lista->getN()-1)) / 2;
}

/*
Elegimos el pivote como la media entre el primer y el último elemento de la lista
Parametros:
-Pivote: pivote a usar 
-listaCompleta: lista entera con los valores
-sublista1: lista auxiliar para almacenar los elementos menores al pivote
-sublsta2: lista auxiliar para almacenar los elementos mayores al pivote
Complejidad:
-Temporal: O(n)= n
-Espacial: O(n)= 1
*/
void repartir(float pivote, ListaCircular * listaCompleta, ListaCircular * sublista1, ListaCircular * sublista2)
{
	// Repartimos los elementos según el pivote. Empezamos por el primero y acabamos por el último.
	// De este modo, el último elemento que metemos es el pivote. Como los elementos que son iguales que el pivote
	// los metemos en la sublista que menos elementos tenga, y como el último que comprobamos es el pivote, de este modo
	// nos aseguramos que la lista que menos elementos tenga al menos tenga tamaño 1
	while (listaCompleta->getN() > 0) {
		int valor = listaCompleta->getValor(0);
		listaCompleta->eliminar(0);
		
		ListaCircular *aux;
		if (valor < pivote) aux = sublista1;
		else if (valor > pivote) aux = sublista2;
		else {
			(sublista1->getN() > sublista2->getN()) ? aux = sublista2 : aux = sublista1;
		}
		aux->insertar(aux->getN(), valor);
	} 
}


void quicksort(ListaCircular *lista)
{
	assertdomjudge(lista != NULL && lista->getN() >= 1);

	int n = lista->getN(); // Tamaño de la lista pasada como parametro

	// Sólo hacemos algo si la lista tiene al menor 2 nodos 
	// Por tanto no hay llamada recursiva (caso trivial) cuando se tiene 1 nodo
	if (n >= 2) {
		// Listas que contendrán a cada una de las dos partes en que dividiremos la lista enlazada
		ListaCircular *sublista1 = new ListaCircular();
		ListaCircular *sublista2 = new ListaCircular();

		// Calculamos el pivote. Tiempo y espacio O(1)
		float pivote = getPivote(lista);
		// Repartimos los elementos segun el pivote. Tiempo O(n) y espacio O(1)
		repartir(pivote, lista, sublista1, sublista2);
		// Hacemos la llamada recursiva para ordenar ambas sublistas por separado
		quicksort(sublista1);
		quicksort(sublista2);

		lista->concatenar(sublista1);
		lista->concatenar(sublista2);
	} // Fin if (lista.getN() >= 2)

	for (int i = 0; i<lista->getN(); i++)
		cout << lista->getValor(i) << " ";
	cout << endl;
}


int main()
{
	int n, x;
	cin >> n;
	ListaCircular lista;
	for (int i = 0; i<n; i++)
	{
		cin >> x;
		lista.insertar(i, x);
	}
	quicksort(&lista);
}

