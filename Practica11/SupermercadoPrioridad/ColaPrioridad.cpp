#include "ColaPrioridad.h"
#include"assertdomjudge.h"
using namespace std;
void ColaPrioridad::encolar(int num) {
	vector.insertarAlFinal(num);
	int n = vector.getN();
	while (n > 1 && vector.getValor(n - 1) < vector.getValor(n / 2 - 1)) {
		int aux = vector.getValor(n - 1);
		vector.setValor(n - 1, vector.getValor(n / 2 - 1));
		vector.setValor(n / 2 - 1, aux);
		n=n/2;
	}
}

int ColaPrioridad::desencolar() {
	assertdomjudge(!estaVacia());
	int respuesta = vector.getValor(0);
	vector.setValor(0, vector.getValor(vector.getN()-1));
	vector.eliminarAlFinal();
	if (vector.getN() >= 2) {
		reestructurar();
	}
	return respuesta;
}

bool ColaPrioridad::estaVacia() {
	return !vector.getN() > 0;
}

void ColaPrioridad::reestructurar() {
	for (int i = 1; i < vector.getN(); i++) {
		if (vector.getValor((i - 1) / 2)>vector.getValor(i)) {
			int aux = vector.getValor(i);
			vector.setValor(i, vector.getValor((i - 1) / 2));
			vector.setValor((i - 1) / 2, aux);
		}
	}
}