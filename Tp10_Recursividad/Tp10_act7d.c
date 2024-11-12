#include <stdio.h>
int calcMcd(int, int);

int main(int argc, char *argv[]) {
	int a, b;
	a = 100;
	b = 20;
	
	printf("El resultado del maximo comun multiplo con el algoritmo de Euclides es: %i", calcMcd(a,b));
	
	return 0;
}

int calcMcd(int a, int b) {
	int rtdo;
	if (b == 0) {
		rtdo = a;
	}
	else{
		rtdo = calcMcd(b, a % b);
	}
	return rtdo;
}

