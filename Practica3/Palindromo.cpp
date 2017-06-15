#include <iostream>
#include <cstring>
#include <stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;
/*
Javier Guillamón Pardo
Práctica 3
*/

/*
Lee una cadena de caracteres e indica si es palindromo
Parámetros:
-s: cadena de caracteres a comprobar
Retorno: si es o no un palindromo
Complejidad:
-Temporal: O(n)=lgn
-Espacial: O(n)=1
*/
bool Palindromo(char s[], int a, int b) {
	if (s[a] != s[b]) return false;	
	else if (s[a] == s[b]) {
		if (a == b || a == (strlen(s) / 2))
			return true;
		else
			Palindromo(s, a + 1, b - 1);
	}
}
/*
Calculo complejidad Temporal Palindromo:
T(1)=1
T(n)=T(n/2)+1
n=2^k; k=lgn
T(2^k)=T(2^(k-1))+1
T(2^k)=F(k)
F(k)=F(k-1)+1
Fk-Fk-1=0
r^(k-1)(r-1)=0; (r-1)(r-1)=0
F(k)=C1*1^k+C2*k*1^k= C1+kC2
F(1)=1; F(2)=2
1=C1+c2; 2=C1+2C2
C1=0; C2=1;
F(k)=0+1*k; F(k)=k+1
T(2^k)=F(k)
T(2^k)=k+1
T(n)=lgn+1
*/

int main() {
	char s[20];
	cin.getline(s, 20, '\n');
	cout << Palindromo(s, 0, strlen(s)-1) << endl;
}