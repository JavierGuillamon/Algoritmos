#include <iostream>
using namespace std;

// Representa una soluci�n parcial del problema de optimizaci�n gen�tica
class SolucionParcial {
public:
	float x; // Posici�n del hijo
	float y; // Valor del hijo
	void imprimir()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}

};