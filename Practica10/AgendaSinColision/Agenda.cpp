#include "Agenda.h"
Agenda::Agenda(int capacidad)
{
	this->capacidad = capacidad;
	nombres = new string[capacidad];
	telefonos = new long[capacidad];
	ocupados = new bool[capacidad];
	for (int i = 0; i < capacidad; i++) 
		ocupados[i] = false;
}

int Agenda::obtenerPosicion(long posicion) {
	return posicion%capacidad;
}

bool Agenda::existeContacto(long telefono) {
	bool respuesta = false;
	int pos = obtenerPosicion(telefono);
	ocupados[pos]&&telefonos[pos]==telefono ? respuesta = true : respuesta = false;
	return respuesta;
}

string Agenda::getContacto(long telefono) {
	assertdomjudge(existeContacto(telefono));
		return nombres[obtenerPosicion(telefono)];
}

void Agenda::introducirContacto(long telefono, string contacto) {
	assertdomjudge(!ocupados[obtenerPosicion(telefono)]);
	int pos = obtenerPosicion(telefono);
	nombres[pos] = contacto;
	telefonos[pos] = telefono;
	ocupados[pos] = true;
}

void Agenda::eliminarContacto(long telefono) {
	assertdomjudge(existeContacto(telefono));	
	ocupados[obtenerPosicion(telefono)] = false;
}

void Agenda::imprimir() {
	for (int i = 0; i<capacidad; i++) cout << "Posicion " << i << " | Ocupada: " << ocupados[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

Agenda::~Agenda()
{
	delete[] nombres;
	delete[] telefonos;
	delete[] ocupados;
};