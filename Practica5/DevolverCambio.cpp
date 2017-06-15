#include<iostream>
using namespace std;
/*
Javier Guillamón Pardo
Práctica 5
*/

/*
Devuelve el cambio con el menor número de monedas usando un algoritmo voraz
Parámetros:
-x: Cantidad de pesetas que se quiere devolver en monedas
Complejidad:
-Temporal: O(n)= n
-Espacial: O(n)= 1
*/
void devolverCambio(int x) {
	int m500=0, m200=0, m100=0, m50=0, m25=0, m10=0, m5=0, m1=0;
	while (x >= 500) {
		x -= 500;
		m500++;
	}
	while (x >= 200) {
		x -= 200;
		m200++;
	}
	while (x >= 100) {
		x -= 100;
		m100++;
	}
	while (x >= 50) {
		x -= 50;
		m50++;
	}
	while (x >= 25) {
		x -= 25;
		m25++;
	}
	while (x >= 10) {
		x -= 10;
		m10++;
	}
	while (x >= 5) {
		x -= 5;
		m5++;
	}
	while (x >= 1) {
		x -= 1;
		m1++;
	}
	cout << m500 << " " << m200 << " " << m100 << " " << m50 << " " << m25 << " " << m10 << " " << m5 << " " << m1 << endl;
}

int main() {
	int n;
	while (1 == 1) {
		cin >> n;
		if (n < 0)
			break;
		else {
			devolverCambio(n);
		}
	}
}