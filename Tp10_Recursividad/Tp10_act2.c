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
	
	if(*str == '\0'){
		return '\0';
	}
	if (k == 0){
		return *str;
	}
	
	return kCaracter(str+1, k-1);
}