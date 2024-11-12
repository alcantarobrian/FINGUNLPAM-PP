#include <stdio.h>

int sOcurrencias(char *, char, int);

int main() {
	char string[]= "Hola Mundo!";
	char caracter = '!';
	
	printf("La cantidad de veces que aparece la letra '%c' son: %i",caracter, sOcurrencias(string, caracter, 0));
	
	return 0;
}

int sOcurrencias(char *str, char c, int cont){
	
	if(*str == '\0'){
		return cont;
	}
	
	if(*str == c){
		cont++;
	}
	
	return	sOcurrencias(str+1, c, cont);
}

