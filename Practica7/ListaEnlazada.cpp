#include "ListaEnlazada.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

ListaEnlazada::ListaEnlazada() {
	n = 0;
	lista = NULL;
}

Nodo* ListaEnlazada::getNodo(int pos) {
	assertdomjudge(pos >= 0);
	assertdomjudge(pos <= n);
	Nodo* aux=lista;
	for (int i = 0; i < pos; i++)
		aux = aux->siguienteNodo;
	return aux;
}

int ListaEnlazada::getValor(int pos) {
	assertdomjudge(pos < n);
	assertdomjudge(pos >= 0);
	return getNodo(pos)->elemento;
}

void ListaEnlazada::setValor(int pos, int val) {
	assertdomjudge(pos < n);
	assertdomjudge(pos >= 0);
	getNodo(pos)->elemento = val;
}

int ListaEnlazada::getN() {
	return n;
}

void ListaEnlazada::insertar(int pos, int val) {
	assertdomjudge(pos <= n);
	assertdomjudge(pos >= 0);
	Nodo* nuevo=new Nodo;
	nuevo->elemento = val;
	if (n == 0) {
		nuevo->siguienteNodo = NULL;
		lista = nuevo;
	}
	else {
		if (pos == 0) {
			nuevo->siguienteNodo = lista;
			lista = nuevo;
		}
		else if (pos == n) {
			nuevo->siguienteNodo = NULL;
			getNodo(pos - 1)->siguienteNodo = nuevo;
		}
		else {
			nuevo->siguienteNodo = getNodo(pos);
			getNodo(pos - 1)->siguienteNodo = nuevo;
		}
	}
	n++;
}

void ListaEnlazada::eliminar(int pos) {
	assertdomjudge(pos >= 0);
	assertdomjudge(pos < n);
	Nodo* aux;
	if (pos == 0) {
		aux = lista;
		lista = aux->siguienteNodo;
	}
	else {
		aux = getNodo(pos);
		getNodo(pos - 1)->siguienteNodo = aux->siguienteNodo;
	}
	delete(aux);
	n--;
}

void ListaEnlazada::concatenar(ListaEnlazada *lis) {
	Nodo* aux = lista;
	for (int i = 0; i < n-1; i++)
		aux = aux->siguienteNodo;
	aux->siguienteNodo = lis->lista;
	n += lis->getN();
}

int ListaEnlazada::buscar(int num) {
	Nodo* aux = lista;
	for (int i = 0; i < n; i++) {
		if (aux->elemento == num) return i;
		else aux = aux->siguienteNodo;
	}
	return -1;
}

ListaEnlazada::~ListaEnlazada() {
	free(lista);
}
