#include <stdio.h>

int calcTam(char *);

int main() {
	
	char string[] = "Hola Mundo!";
	
	printf("El tamaño del string es de: %i", calcTam(string));
	
	return 0;
}

int calcTam(char *str){
	int rtdo;
	
	if(*str == '\0'){
		rtdo = 0;
	}
	else{
		rtdo = 1+calcTam(str+1);
	}
	return rtdo;
}

