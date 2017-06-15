#include"Pila.h"


Pila::Pila(string name)
{
	cima = NULL;
	this->name = name;
}

std::string Pila::nombrePila()
{
	return name;
}

void Pila::apilar(int num)
{
	cout << "Apilando disco " << num << " en poste " << name << endl;
	Nodo* nuevo = new Nodo(num,cima);
	cima = nuevo;
}

int Pila::desapilar()
{
	int num = cima->valor;
	cout << "Desapilando disco " << num << " del poste " << name << endl;
	cima = cima->siguiente;
	return num;
}

bool Pila::estaVacia()
{
	if (cima == NULL) return true;
	else return false;
}
