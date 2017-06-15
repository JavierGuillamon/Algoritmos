#include "Agenda.h"
Agenda::Agenda(int capacidad)
{
	this->capacidad = capacidad;
	n = 0;
	tabla = new ListaEnlazada[capacidad];
}

int Agenda::obtenerPosicion(long telefono) {
	return telefono%capacidad;
}

bool Agenda::existeContacto(long telefono) {
	bool respuesta;
	Contacto contacto;
	contacto.telefono = telefono;
	(tabla[obtenerPosicion(telefono)].buscar(contacto)!=-1) ? respuesta = true : respuesta = false;
	return respuesta;
}

string Agenda::getContacto(long telefono) {
	assertdomjudge(existeContacto(telefono));
	int pos = obtenerPosicion(telefono);
	Contacto contacto;
	contacto.telefono = telefono;
	return tabla[pos].getValor(tabla[pos].buscar(contacto)).nombre;
}

void Agenda::introducirContacto(long telefono, string contacto) {	
	n++;
	Contacto cont;
	cont.telefono = telefono;
	cont.nombre = contacto;
	int pos = obtenerPosicion(telefono);
	tabla[pos].insertar(0,cont);
}

void Agenda::eliminarContacto(long telefono) {
	assertdomjudge(existeContacto(telefono));
	n--;
	Contacto contacto;
	contacto.telefono = telefono;
	int pos = obtenerPosicion(telefono);
	tabla[pos].eliminar(tabla[pos].buscar(contacto));
}

void Agenda::imprimir() {
	for (int i = 0; i<capacidad; i++) {
		cout << "Posicion " << i << ": ";
		imprimirListaEnlazada(&tabla[i]);
	}
}

Agenda::~Agenda()
{
	delete[] tabla;
};