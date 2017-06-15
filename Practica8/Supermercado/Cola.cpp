#include "Cola.h"
#include<iostream>
using namespace std;

Cola::Cola() {
	principio = NULL;
	final = NULL;
}

void Cola::encolar(int num) {
	Nodo* nuevo = new Nodo(num, NULL);
	if (principio==NULL) principio = nuevo;	
	else final->siguiente = nuevo;
	final = nuevo;
}

int Cola::desencolar() {
	int num = principio->valor;
	principio = principio->siguiente;
	return num;
}

bool Cola::estaVacia() {
	if (principio == NULL) return true;
	else  return false;
}