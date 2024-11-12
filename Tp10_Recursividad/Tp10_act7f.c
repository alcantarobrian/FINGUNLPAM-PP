#include <stdio.h>

int sOcurrencias(char *, char, int);

int main() {
	char string[]= "Hola Mundo!";
	char caracter = '!';
	
	printf("La cantidad de veces que aparece la letra '%c' son: %i",caracter, sOcurrencias(string, caracter, 0));
	
	return 0;
}

int sOcurrencias(char *str, char c, int cont){
	int result = cont;
	
	if (*str == '\0') {
		result = cont;
	} else {
		if (*str == c) {
			result = sOcurrencias(str + 1, c, cont + 1);
		} else {
			result = sOcurrencias(str + 1, c, cont);
		}
	}
	
	return result;
}

