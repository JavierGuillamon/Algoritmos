#include "ListaCircular.h"
#include <iostream>
#include "assertdomjudge.h"
using namespace std;

ListaCircular::ListaCircular() {
	lista = NULL;
	n = 0;
}

Nodo* ListaCircular::getNodo(int pos) {
	assertdomjudge(pos >= 0);
	assertdomjudge(pos < n);
	Nodo *aux=lista;
	if (pos < (n / 2)) {
		for (int i = 0; i < pos; i++)
			aux = aux->siguienteNodo;
	}
	else {
		for (int i = 0; i < (n - pos); i++)
			aux = aux->anteriorNodo;
	}
	return aux;
}

string ListaCircular::getValor(int pos) {
	assertdomjudge(pos >= 0);
	assertdomjudge(pos <= n);
	return getNodo(pos)->elemento;
}

void ListaCircular::setValor(int pos, string val) {
	assertdomjudge(pos >= 0);
	assertdomjudge(pos < n);
	getNodo(pos)->elemento = val;
}

int ListaCircular::getN() {
	return n;
}

void ListaCircular::insertar(int pos, string val) {
	assertdomjudge(pos >= 0);
	assertdomjudge(pos <= n);
	Nodo* aux=new Nodo;
	aux->elemento = val;
	if (n == 0) {
		aux->siguienteNodo = aux;
		aux->anteriorNodo = aux;
	}
	else {
		Nodo *siguiente,*anterior;
		if (pos == n)
			siguiente = lista;
		else
			siguiente= getNodo(pos);
		anterior = siguiente->anteriorNodo;
		aux->anteriorNodo = anterior;
		aux->siguienteNodo = siguiente;
		siguiente->anteriorNodo = aux;
		anterior->siguienteNodo = aux;
	}
	if (pos == 0) lista = aux;
	n++;
}

void ListaCircular::eliminar(int pos) {
	assertdomjudge(pos >= 0);
	assertdomjudge(pos < n);
	Nodo* aux = getNodo(pos);
	if (n == 1) lista = NULL;
	else {
		Nodo *siguiente, *anterior;
		siguiente = aux->siguienteNodo;
		anterior = aux->anteriorNodo;
		siguiente->anteriorNodo = anterior;
		anterior->siguienteNodo = siguiente;
		if (pos == 0)lista = siguiente;
	}
	delete(aux);
	n--;
}

void ListaCircular::girar(int p) {
	Nodo*nodo = lista;
	for (int i = 0; i < abs(p); i++) {
		if (p > 0) 
			nodo = nodo->siguienteNodo;		
		else 
			nodo = nodo->anteriorNodo;		
	}
	lista = nodo;
}

ListaCircular::~ListaCircular() {
	while (n != 0) eliminar(0);
}