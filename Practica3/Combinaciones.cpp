#include<iostream>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;
/*
Javier Guillamón Pardo
Práctica 3
*/

/*
Calcula el factorial de un número
Parámetros:
	-n: número del que se quiere calcular el factorial
Retorno: Factorial del número
Complejidad:
-Temporal: O(n)=n 
-Espacial: O(n)=1
*/
int factorial(int n) {
	if (n == 1) return 1;
	else return(n*factorial(n - 1));
}
/*
Calculo complejidad Temporal Factorial:
T(1)=1
T(n)=T(n-1)+1
Fn-Fn-1=0
r^(n-1)(r-1)=0; (r-1)(r-1)=0
F(n)=C1*1^n+C2*n*1^n= C1+nC2
F(1)=1; F(2)=2
1=C1+c2; 2=C1+2C2
C1=0; C2=1;
F(n)=0+1*n
T(n)=n+1
*/


/*
Calcula las posibles combinaciones de n elementos tomados en grupos de r usando una solución recursiva
Parámetros:
	-n: Cantidad de elementos tomados
	-r: tamaño de los grupos
Retorno: numero de posibles combinaciones
Precondiciones:
-n >= r
-r > 0
Complejidad:
-Temporal: T(n)=n/r(n-r)+1 O(n)=n
-Espacial: O(n)=1
*/
int Combinaciones(int n, int r) {
	assertdomjudge(n >= r);
	assertdomjudge(r > 0);
	if (n == 0) return 0;
	else if( n == r) return 1;
	else 
		return (factorial(n) / (factorial(r)*factorial(n - r)));	
}


int main() {
	int n,r;
	while (1 == 1) {
		cin >> n;
		cin >> r;
		if (n < 0)
			break;
		else {

			cout << Combinaciones(n, r) << endl;	
		}
	}
}