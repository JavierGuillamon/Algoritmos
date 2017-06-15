#include "ListaContigua.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
ListaContigua::ListaContigua(int inc)
{
	assertdomjudge(inc > 0);
	n = 0;
	capacidad = 0;
	incremento = inc;
	vector = NULL;
}

int ListaContigua::getValor(int pos) {
	assertdomjudge(pos < n);
	assertdomjudge(pos >= 0);
	return vector[pos];
}

void ListaContigua::setValor(int pos, int val) {
	assertdomjudge(pos < n);
	assertdomjudge(pos >= 0);
	vector[pos] = val;
}

int ListaContigua::getN() {
	return n;
}

int ListaContigua::getCapacidad() {
	return capacidad;
}

void ListaContigua::insertar(int pos, int val) {
	assertdomjudge(pos <= n);
	assertdomjudge(pos >= 0);
	if (n == capacidad) {
		capacidad += incremento;
		vector = (int*)realloc(vector, sizeof(int)*capacidad);//O(n)=n, temporal y espacial
	}
	memmove(&vector[pos+1],&vector[pos], sizeof(int)*(n-pos));//O(n)=n, temporal y espacial
	n++;
	vector[pos] = val;
}

void ListaContigua::eliminar(int pos) {
	assertdomjudge(pos < n);
	assertdomjudge(pos >= 0);
	n--;
	memmove(&vector[pos], &vector[pos + 1], sizeof(int)*(n-pos));//O(n)=n, temporal y espacial
	if (n <= capacidad-2 * incremento) {
		capacidad -= incremento;
		vector = (int*)realloc(vector, sizeof(int)*capacidad);//O(n)=n, temporal y espacial
	}	
}

void ListaContigua::concatenar(ListaContigua *lista) {
	capacidad += lista->getN();
	vector = (int*)realloc(vector, sizeof(int)*capacidad);//O(n)=n, temporal y espacial

	for (int i = 0; i < lista->getN(); i++)
		insertar(n,lista->vector[i]);
}

int ListaContigua::buscar(int num) {
	for (int i = 0; i < n; i++) {
		if (vector[i] == num) return i;
	}
	return -1;
}

ListaContigua::~ListaContigua()
{
	free(vector);
}
