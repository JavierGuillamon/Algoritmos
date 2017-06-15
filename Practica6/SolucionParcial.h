#include <iostream>
using namespace std;

// Representa una solución parcial del problema de optimización genética
class SolucionParcial {
public:
	float x; // Posición del hijo
	float y; // Valor del hijo
	void imprimir()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}

};