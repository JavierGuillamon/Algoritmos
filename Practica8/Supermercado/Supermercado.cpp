#include "Supermercado.h"
#include "assertdomjudge.h"
#include <iostream>
using namespace std;

Supermercado::Supermercado(int n) {
	assertdomjudge(n >= 0);
	cajas = new Cola[n];
	n_cajas = n;
}

void Supermercado::nuevoUsuario(int n, int id) {
	assertdomjudge(n >= 0);
	assertdomjudge(n <= n_cajas);
	cajas[n].encolar(id);
}

void Supermercado::cerrarCaja(int n) {
	assertdomjudge(n >= 0);
	assertdomjudge(n <= n_cajas);
	int i = 0;
	do {
		if (i != n) {
			cajas[i].encolar(cajas[n].desencolar());
		}
		i++;
		if (i == n_cajas) i = 0;
	} while (!cajas[n].estaVacia());
}

int Supermercado::atenderUsuario(int n) {
	assertdomjudge(n >= 0);
	assertdomjudge(n <= n_cajas);
	return cajas[n].desencolar();
}

bool Supermercado::cajaVacia(int n) {
	assertdomjudge(n >= 0);
	assertdomjudge(n <= n_cajas);
	return cajas[n].estaVacia();
}
