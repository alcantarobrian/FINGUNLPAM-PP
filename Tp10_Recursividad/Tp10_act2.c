#include <stdio.h>

char kCaracter(char *str, int k);

int main() {
	char string[20] = "Hola Mundo!", caracter;
	int nro;
	nro = 4;
	
	caracter = kCaracter(string, nro);
	
	printf("El caracter en la ubicacion '%i' del string es: '%c'", nro, caracter);
	
	return 0;
}

char kCaracter(char *str, int k){
	
	char result;
	
	if (*str == '\0') {
		result = '\0';
	} 
	else if (k == 0) {
		result = *str;
	}
	else {
		result = kCaracter(str + 1, k - 1);
	}
	
	return result;
}