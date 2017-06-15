#include<iostream>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;

/*
Javier Guillamón Pardo
Práctica 4
*/

/*
Calcula las posibles combinaciones de n elementos tomados en grupos de r usndo una solucion basada en programacion dinamica
Parámetros:
-n: Cantidad de elementos tomados
-r: tamaño de los grupos
Retorno: Número de posibles combinaciones
Precondiciones:
-n >= r
Complejidad:
-Temporal: O(n)= n
-Espacial: O(n)= n
*/
double CombinacionesDinamica(int n, int r)
{
	assertdomjudge(n >= r);
	int **triangulo = new int*[n+1];
	for (int i = 0; i <= n; i++) {
		triangulo[i] = new int[n+1];
	}
	int i = 0, j = 0;
	while (i <= n) {
		if (i == 0) {
			triangulo[i][j] = 1;
			i++;
		}
		else if (j == 0) {
			triangulo[i][j] = 1;
			j++;

		}
		else {
			if (j == i) {
				triangulo[i][j] = 1;
				i++;
				j = 0;
			}
			else {
				triangulo[i][j] = triangulo[i - 1][j - 1] + triangulo[i - 1][j];
				j++;
			}
		}
	}
	return triangulo[n][r];
}


int main()
{
	int n, r;
	while (1 == 1) {
		cin >> n;
		cin >> r;
		if (n < 0)
			break;
		else {
			cout << CombinacionesDinamica(n, r) << endl;					
		}
	}
}
