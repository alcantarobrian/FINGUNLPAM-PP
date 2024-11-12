#include <stdio.h>

int multiplicar(int, int);

int main() {
	int a = -2, b = -5, rtdo;
	rtdo = multiplicar(a,b);
	
	printf("Resultado = %i", rtdo);
	
	return 0;
}

int multiplicar(int a, int b){
	int calc;
	
	if(b == 0){
		calc = 0;
	}
	else{
		calc = a + multiplicar(a, b-1);
	}
	return calc;
}

