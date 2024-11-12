#include <stdio.h>

int kNum(int, int);

int main() {
	int numero, kesimo;
	numero = 2351231;
	kesimo = 2;
	
	printf("El k-esimo número es: %i", kNum(numero, kesimo));
	
	return 0;
}

int kNum(int numero, int k){
	
	if (numero < 0) {
		numero = -numero;
	}
	
	if (k != 1) {
		numero = kNum(numero / 10, k - 1);
	}
	else{
		numero = numero % 10; 
	}
	
	return numero;
	
}