#include<iostream>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;
/*
Javier Guillam�n Pardo
Pr�ctica 3
*/

/*
Raiz cuadrada de un n�mero de forma recursiva mediante aproximaciones sucesivas
Par�metros:
-num: n�mero del que se quiere calcular la raiz
-error: error minimo que se quiere alcanzar en la raiz
-a: valor mas peuqe�o usado para calcular el punto medio, en la primera iteraci�n es igual a 0 
-b: valor mas grande usado para calcular el punto medio, en la primera iteraci�n es igual a num
Retorno: el resultado de todas las aproximaciones hasta alcanzar el error
Precondiciones:
-num >= 0
-error > 0
*/
float Raiz(float num, float error, float a, float b) {
	assertdomjudge(num >= 0);
	assertdomjudge(error > 0);
	float aux = (a + b) / 2;
	cout << aux << endl;
	if ((aux*aux - num) > error) {		
		return Raiz(num, error, a, aux);
	}
	if(-(aux*aux-num) > error) {
		return Raiz(num,error, aux, b);
	} 
	return aux;
}


int main() {
	float a, b;
	cin >> a;
	cin >> b;
	cout << Raiz(a,b,0,a) << endl;
}