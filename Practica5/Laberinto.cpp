#include<iostream>
using namespace std;
const int LS = 10;
/*
Javier Guillamón Pardo
Práctica 5
*/

/*
Metodo que nos indica si podemos colocarnos en la posicion dada
Parámetros:
-laberinto: imagen de la situación del laberinto
-x: posicion en x
-y: posicion en y
Retorno:
-true: si se puede colocar en dicha posicion
-false: si no se puede colocar
Complejidad:
-Temporal: O(n)= 1
-Espacial: O(n)= 1
*/
bool posicionValida(char laberinto[LS][LS],int x, int y) {
	if (x >= 0 && x<= LS && y >= 0 && y <= LS && (laberinto[x][y] == '.'))
		return true;
	else return false;
}

/*
Recorre un laberinto dado hasta encontrar un tesoro usando un sistema de backtracking.
El orden de movimiento es: arriba, derecha, abajo e izquierda.
Parámetros:
-laberinto: imagen de la situación del laberinto
-x: posicion en x
-y: posicion en y
Retorno:
-true: si encuentra un camino
-false: si el camino esta bloqueado
Complejidad:
-Temporal: O(n)= 4^n
-Espacial: O(n)= n
*/
bool recorrerLaberinto(char laberinto[LS][LS],int x,int y) {	
	if (laberinto[x][y] == 'T') {
		for (int i = 0; i < LS; i++) {
			for (int j = 0; j < LS; j++) {
				cout << laberinto[i][j];
			}
			cout << endl;
		}
		cout << "ENCONTRADO " << x << " " << y<<endl;
		return true;
	}
	if (posicionValida(laberinto, x, y)) {
		laberinto[x][y] = 'X';

		if (recorrerLaberinto(laberinto,x-1,y)) return true; //arriba
		if (recorrerLaberinto(laberinto, x, y+1)) return true; //derecha
		if (recorrerLaberinto(laberinto, x+1, y)) return true; //abajo
		if (recorrerLaberinto(laberinto, x, y-1)) return true; //izquierda

		laberinto[x][y] = '.';
		
		return false;
	}
	return false;
}

int main() {
	char aux;
	char laberinto[LS][LS];
	for (int i = 0; i < LS; i++) {
		for (int j = 0; j < LS; j++) {
			cin >> aux;
			laberinto[i][j] = aux;
		}
	}
	if (recorrerLaberinto(laberinto, 0, 0)==false) 
		cout << "INALCANZABLE"<<endl;
}