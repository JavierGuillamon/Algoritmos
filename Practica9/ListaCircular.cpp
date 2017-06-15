#include "ListaCircular.h"
#include"assertdomjudge.h"

ListaCircular::ListaCircular() {
	lista = NULL;
	n = 0;
}

Nodo* ListaCircular::getNodo(int pos) {
	assertdomjudge(pos >= 0);
	assertdomjudge(pos < n);
	Nodo *aux = lista;
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

int ListaCircular::getValor(int pos) {
	assertdomjudge(pos >= 0);
	assertdomjudge(pos <= n);
	return getNodo(pos)->elemento;
}

void ListaCircular::setValor(int pos, int val) {
	assertdomjudge(pos >= 0);
	assertdomjudge(pos < n);
	getNodo(pos)->elemento = val;
}

int ListaCircular::getN() {
	return n;
}

void ListaCircular::insertar(int pos, int val) {
	assertdomjudge(pos >= 0);
	assertdomjudge(pos <= n);
	Nodo* aux = new Nodo;
	aux->elemento = val;
	if (n == 0) {
		aux->siguienteNodo = aux;
		aux->anteriorNodo = aux;
	}
	else {
		Nodo *siguiente, *anterior;
		if (pos == n)
			siguiente = lista;
		else
			siguiente = getNodo(pos);
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

void ListaCircular::concatenar(ListaCircular *listaAConcatenar) {
	assertdomjudge(listaAConcatenar != NULL);	
	if (n == 0) {
		lista = listaAConcatenar->lista;
	}
	else {
		Nodo *auxLUlt = lista->anteriorNodo;
		Nodo *auxLUltC = listaAConcatenar->lista->anteriorNodo;
		auxLUlt->siguienteNodo = listaAConcatenar->lista;
		auxLUltC->siguienteNodo = lista;
		lista->anteriorNodo = auxLUltC;
		listaAConcatenar->lista->anteriorNodo = auxLUlt;
	}
	n += listaAConcatenar->getN();
}

ListaCircular::~ListaCircular() {
	while (n != 0) eliminar(0);
}