#include <stdio.h>

int sizeString(char *, int c);

int main() {
	char palabra[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int cantidad;
	
	cantidad = sizeString(palabra, 0);
	
	printf("La cantidad de caracteres contenidos en el string es de: %i", cantidad);
	return 0;
}

int sizeString(char *caracter, int c){
	if(*caracter == '\0'){
		return c;
	}
	if(*caracter != '\0'){
		c = sizeString(caracter + 1, c + 1);
	}
	return c;
}
