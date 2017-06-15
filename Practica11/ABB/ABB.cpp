#include "ABB.h"
#include "assertdomjudge.h"
#include "iostream"
#include <algorithm>
using namespace std;

ABB::ABB() {
	n = 0;
	raiz = NULL;
}

ABB::~ABB() {
	if (raiz != NULL) eliminarSubarbol(raiz);
}

void ABB::imprimir()
{
	if (raiz == NULL)
		cout << "VACIO" << endl;
	else
		imprimirRecorrido(raiz);
}

void ABB::imprimirRecorrido(Nodo *raizSubarbol)
{
	cout << raizSubarbol->contenido << endl;
	if (raizSubarbol->hijoIzquierdo != NULL)
	{
		cout << "I";
		imprimirRecorrido(raizSubarbol->hijoIzquierdo);
		cout << endl;
	}
	if (raizSubarbol->hijoDerecho != NULL)
	{
		cout << "D";
		imprimirRecorrido(raizSubarbol->hijoDerecho);
		cout << endl;
	}
}

void ABB::leerArbol()
{
	raiz = leerSubarbol(NULL);
}

Nodo * ABB::leerSubarbol(Nodo *padre)
{
	int contenido;
	cin >> contenido;
	if (contenido >= 0)
	{
		Nodo *arbol = new Nodo;
		arbol->contenido = contenido;
		arbol->hijoIzquierdo = leerSubarbol(arbol);
		arbol->hijoDerecho = leerSubarbol(arbol);
		arbol->padre = padre;
		return arbol;
	}
	else
	{
		return NULL;
	}
}

void ABB::insertar(int nuevoElemento) {
	Nodo *aux = new Nodo;
	aux->contenido = nuevoElemento;
	aux->padre = NULL;
	aux->hijoIzquierdo = NULL;
	aux->hijoDerecho = NULL;
	if (n == 0) 
		raiz = aux;	
	else {
		Nodo *hueco = buscarHueco(raiz, nuevoElemento); 
		(nuevoElemento <= hueco->contenido) ? hueco->hijoIzquierdo = aux : hueco->hijoDerecho = aux;
		aux->padre = hueco;
	}
	n++;
}

Nodo* ABB::buscar(int elementoABuscar) {
	return buscarRecursivo(raiz,elementoABuscar);
}

void ABB::eliminar(int elementoAEliminar){
	eliminarNodo(buscar(elementoAEliminar));
	n--;
}

bool ABB::esABB() {

}

bool ABB::esAVL() {

}

void ABB::eliminarSubarbol(Nodo *raizSubarbol) {

}

Nodo *ABB::buscarHueco(Nodo *raizSubarbol, int elementoAInsertar) {
	if (elementoAInsertar < raizSubarbol->contenido)
		if (raizSubarbol->hijoIzquierdo != NULL)
			return (buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar));
		else 
			return raizSubarbol;
	else
		if (raizSubarbol->hijoDerecho != NULL)
			return (buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar));
		else 
			return raizSubarbol;
}

Nodo *ABB::buscarRecursivo(Nodo *raizSubarbol, int elementoABuscar) {
	if (elementoABuscar < raizSubarbol->contenido)
		raizSubarbol = buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
	else if (elementoABuscar > raizSubarbol->contenido)
		raizSubarbol = buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
	else
		return raizSubarbol;
}

Nodo *ABB::buscarMaximo(Nodo *raizSubarbol) {
	if (raizSubarbol->hijoDerecho != NULL) raizSubarbol = buscarMaximo(raizSubarbol->hijoDerecho);
	else return raizSubarbol;
}

Nodo *ABB::buscarMinimo(Nodo *raizSubarbol) {
	if (raizSubarbol->hijoIzquierdo != NULL) raizSubarbol = buscarMaximo(raizSubarbol->hijoIzquierdo);
	else return raizSubarbol;
}

void ABB::eliminarNodo(Nodo *nodoParaEliminar) {
	Nodo *aux = NULL;
	if (nodoParaEliminar != NULL) {
		if (nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho == NULL) {
			Nodo *padre = nodoParaEliminar->padre;
			if (padre != NULL) {
				if (padre->hijoIzquierdo == nodoParaEliminar) padre->hijoIzquierdo = NULL;
				if (padre->hijoDerecho == nodoParaEliminar) padre->hijoDerecho = NULL;
			}
			delete nodoParaEliminar;
		}
		if (nodoParaEliminar->hijoDerecho == NULL && nodoParaEliminar->hijoIzquierdo != NULL) aux = buscarMaximo(nodoParaEliminar);
		else if(nodoParaEliminar->hijoDerecho != NULL && nodoParaEliminar->hijoIzquierdo == NULL) aux = buscarMinimo(nodoParaEliminar);
		else if (nodoParaEliminar->hijoDerecho != NULL && nodoParaEliminar->hijoIzquierdo != NULL) {
			if (alturaNodo(nodoParaEliminar->hijoIzquierdo) > alturaNodo(nodoParaEliminar->hijoDerecho)) {
				aux = buscarMaximo(nodoParaEliminar);
			}
			else {
				aux = buscarMinimo(nodoParaEliminar);
			}
		}
		nodoParaEliminar->contenido = aux->contenido;
		eliminarNodo(aux);
	}
}

int ABB::alturaNodo(Nodo *raizSubarbol) {
	if (raizSubarbol == NULL)return -1;
	else if (raizSubarbol->hijoIzquierdo == NULL && raizSubarbol->hijoDerecho == NULL) return 0;
	else
		return 1 + std::max(alturaNodo(raizSubarbol->hijoIzquierdo), alturaNodo(raizSubarbol->hijoDerecho));
}

bool ABB::esSubABB(Nodo *raizSubarol) {

}

bool ABB::esSubAVL(Nodo *raizSubarbol) {

}