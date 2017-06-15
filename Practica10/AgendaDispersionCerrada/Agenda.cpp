#include "Agenda.h"
Agenda::Agenda(int capacidad)
{
	this->capacidad = capacidad;
	n = 0;
	nombres = new string[capacidad];
	telefonos = new long[capacidad];
	vacias = new bool[capacidad];
	borradas = new bool[capacidad];
	for (int i = 0; i < capacidad; i++) {
		vacias[i] = true;
		borradas[i] = false;
	}
}

int Agenda::obtenerPosicion(long telefono) {
	return telefono%capacidad;
}

int Agenda::buscarContacto(long telefono) {
	int resultado = -1;
	int pos = obtenerPosicion(telefono);
	for (int i = 0; i < capacidad; i++) {
		if (vacias[pos + i] && !borradas[pos + i]) break;
		if (!vacias[pos + i] && telefonos[pos +i] == telefono)
			resultado = (pos + i) % capacidad;
	}
	return resultado;
}

int Agenda::buscarHueco(long telefono) {
	int resultado=-1;
	int pos = obtenerPosicion(telefono);
	for (int i = 0; i < capacidad; i++) {
		if (vacias[pos + i]) {
			resultado = (pos + i) % capacidad;
			break;
		}
	}
	return resultado;
}

bool Agenda::isLlena() {
	bool resultado;
	(n == capacidad) ? resultado = true : resultado = false;
	return resultado;
}

bool Agenda::existeContacto(long telefono) {
	bool respuesta;
	(buscarContacto(telefono)!= -1) ? respuesta = true : respuesta = false;
	return respuesta;
}

string Agenda::getContacto(long telefono) {
	assertdomjudge(existeContacto(telefono));
	return nombres[buscarContacto(telefono)];
}

void Agenda::introducirContacto(long telefono, string contacto) {
	assertdomjudge(!isLlena());
	n++;
	int pos = buscarHueco(telefono);
	nombres[pos] = contacto;
	telefonos[pos] = telefono;
	vacias[pos] = false;
	borradas[pos] = false;
}

void Agenda::eliminarContacto(long telefono) {
	assertdomjudge(existeContacto(telefono));
	n--;
	int pos = buscarContacto(telefono);
	vacias[pos] = true;
	borradas[pos] = true;
}

void Agenda::imprimir() {
	for (int i = 0; i<capacidad; i++)
		cout << "Posicion " << i << " | Vacia: " << vacias[i] << " | Borrada: " << borradas[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

Agenda::~Agenda()
{
	delete[] nombres;
	delete[] telefonos;
	delete[] vacias;
	delete[] borradas;
};